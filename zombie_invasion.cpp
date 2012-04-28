#include "zombie_invasion.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPainter>
#include <QApplication>
#include <QTimer>

zombie_invasion::zombie_invasion(QWidget *parent) :
    QWidget(parent)
{
    gameOver    = false;
    gameStarted = false;
    startScreen = true;
    lives       = 3;
    spawnTimer  = 0;
    score       = 0;
    level       = 1;
}

zombie_invasion::~zombie_invasion() {}

void zombie_invasion::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // START SCREEN
    if(startScreen){
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);

        QRectF rect(0,100,600,100);

        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter,
                         QString("Zombie Invasion\nAvoid the Zombies\n Press SPACE to start"));

    }

    // GAME OVER SCREEN
    if (gameOver) {
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        painter.setFont(font);
        QRectF rect(0,100,600,100);
        painter.drawText(rect, Qt::AlignCenter,
                         tr("GAME OVER\n\nYou scored %0 points.\n\nPress 'Q' to quit.\nPress 'SPACE' to restart").arg(score));
    }

    else {

        // DRAW SCORE LABEL
        painter.drawText(scoreLabel, Qt::AlignLeft,
                         QString("Lives: %0   Level: %1   Score: %2").arg(lives).arg(level).arg(score));

        // DRAW PLAYER
        painter.drawImage(Player.getRectF(),Player.getImage());

        // DRAW MEDPACK
        painter.drawImage(med.getRectF(),med.getImage());

        // DRAW ENEMEIES
        for (int i=0; i<Zombies.size(); i++)
            painter.drawImage(Zombies[i].getRectF(),Zombies[i].getImage());
        for (int i=0; i<Blockers.size(); i++)
            painter.drawImage(Blockers[i].getRectF(),Blockers[i].getImage());
        for (int i=0; i<Attackers.size(); i++)
            painter.drawImage(Attackers[i].getRectF(),Attackers[i].getImage());
        for (int i=0; i<Smart.size(); i++)
            painter.drawImage(Smart[i]->getRect(),Smart[i]->getImage());
    }
}

void zombie_invasion::keyPressEvent(QKeyEvent *event)
{
    x = Player.getRectF().x();
    switch (event->key()) {

        // MOVE LEFT
        case Qt::Key_Left:
            for (int i=1; i<= 15; i++)
                Player.moveLeft(x--);
            break;

        // MOVER RIGHT
        case Qt::Key_Right:
            for (int i=1; i<= 15; i++)
                Player.moveRight(x++);
            break;

        // START GAME
        case Qt::Key_Space:
            startGame();
            break;

        // QUIT
        case Qt::Key_Q:
            qApp->quit();
            break;

        // DEFAULT
        default:
            QWidget::keyPressEvent(event);
            break;
        }
}

void zombie_invasion::timerEvent(QTimerEvent *event)
{
    // MOVE ENEMIES
    for (int i=0; i<Zombies.size(); i++){
        if (Zombies[i].isActive())
            Zombies[i].advance(level);
    }

    for (int i=0; i<Blockers.size(); i++){
        if (Blockers[i].isActive())
            Blockers[i].advance();
    }

    for (int i=0; i<Attackers.size(); i++){
        if (Attackers[i].isActive())
            Attackers[i].advance();
    }

    for (int i=0; i<Smart.size(); i++){
        if (Smart[i]->isActive())
            Smart[i]->advance(x);
    }


    // MOVE MEDPACK
    if (med.isActive()) { med.advance(); }

    checkcollison();
    updateScore();;
    repaint();
    spawnTimer++;

    // START LEVEL LOGIC
    if (score == 15)  { level = 2; }
    if (score == 30){
        level = 3;
        Zombies.clear();
        Blockers.clear();
    }
    if (score == 45) { level = 4; }

    if (level == 4 && spawnTimer % 150 == 0){
        enemy* temp = new smartAttacker;
        Smart.push_back(temp);
        temp->reset();
    }

    if (spawnTimer % 50 == 0 && level < 3){
        zombie temp;
        Zombies.push_back(temp);
        temp.reset();
    }

    if (level == 2 && spawnTimer % 75 == 0){
        blocker temp;
        Blockers.push_back(temp);
        temp.reset();
    }

    if (level == 3 && spawnTimer % 75 == 0){
        attacker temp(x);
        Attackers.push_back(temp);
        temp.reset();
    }

    if (score % 30== 0 && score != 0 && !med.isActive()){
        med.reset();
    }

    // END LEVEL LOGIC

}

void zombie_invasion::startGame()
{
    if (!gameStarted){

        Player.reset();
        zombie temp;
        Zombies.push_back(temp);
        Zombies[0].reset();
        scoreLabel.setRect(0,0,500,25);


        startScreen = false;
        gameOver = false;
        gameStarted = true;
        timerId = startTimer(20);
    }
    else{
        lives = 3;
        level = 1;
        score = 0;
        startScreen = false;
        gameOver = false;
        gameStarted = true;
        timerId = startTimer(20);
        Player.reset();
        Zombies.clear();
        Blockers.clear();
        Attackers.clear();
        Smart.clear();

        zombie temp;
        Zombies.push_back(temp);
        Zombies[0].reset();
        scoreLabel.setRect(0,0,500,25);
    }
}

void zombie_invasion::checkcollison()
{
    for (int i=0; i<Zombies.size(); i++){
        if (Zombies[i].getRectF().intersects(Player.getRectF())
                && Zombies[i].isActive()){
            Zombies[i].didCollide();
            Zombies[i].remove();
            lives--;
        }
    }

    for (int i=0; i<Blockers.size(); i++){
        if (Blockers[i].getRectF().intersects(Player.getRectF())
                && Blockers[i].isActive()){
            Blockers[i].didCollide();
            Blockers[i].remove();
            lives--;
        }
    }

    for (int i=0; i<Attackers.size(); i++){
        if (Attackers[i].getRectF().intersects(Player.getRectF())
                && Attackers[i].isActive()){
            Attackers[i].didCollide();
            Attackers[i].remove();
            lives--;
        }
    }

    for (int i=0; i<Smart.size(); i++){
        if (Smart[i]->getRect().intersects(Player.getRectF())
                && Smart[i]->isActive()){
            Smart[i]->didCollide();
            Smart[i]->remove();
            lives--;
        }
    }

    if (med.getRectF().intersects(Player.getRectF())){
        lives++;
        med.remove();
    }

    if (lives == 0){
        gameOver = true;
        killTimer(timerId);
    }
}

void zombie_invasion::updateScore()
{
    for (int i=0; i<Zombies.size(); i++){
        if (Zombies[i].getRectF().top() > 500 && Zombies[i].isActive()){
            Zombies[i].didCollide();
            Zombies[i].remove();
            score++;
        }
    }

    for (int i=0; i<Blockers.size(); i++){
        if (Blockers[i].getRectF().top() > 500 && Blockers[i].isActive()){
            Blockers[i].didCollide();
            Blockers[i].remove();
            score++;
        }
    }

    for (int i=0; i<Attackers.size(); i++){
        if (Attackers[i].getRectF().top() > 500 && Attackers[i].isActive()){
            Attackers[i].didCollide();
            Attackers[i].remove();
            score++;
        }
    }

    for (int i=0; i<Smart.size(); i++){
        if (Smart[i]->getRect().top() > 500 && Smart[i]->isActive()){
            Smart[i]->didCollide();
            Smart[i]->remove();
            score++;
        }
    }

    if (med.getRectF().top() > 500 && med.isActive()){
        med.remove();
    }
}
