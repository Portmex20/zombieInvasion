#ifndef ZOMBIE_INVASION_H
#define ZOMBIE_INVASION_H

#include <QWidget>
#include <QKeyEvent>
#include <QVector>
#include <QPixmap>
#include "enemy.h"
#include "player.h"
#include "zombie.h"
#include "blocker.h"
#include "medpack.h"
#include "attacker.h"
#include "smartattacker.h"

class zombie_invasion : public QWidget
{

Q_OBJECT

public:
    zombie_invasion(QWidget *parent = 0);
    ~zombie_invasion();
    
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void stopGame();
    void checkcollison();
    void updateScore();

private:

    int x;
    int timerId;
    int score;
    int lives;
    int level;
    int spawnTimer;
    player Player;
    QVector<zombie> Zombies;
    QVector<blocker> Blockers;
    QVector<attacker> Attackers;
    QVector<enemy*> Smart;
    medpack med;
    bool gameOver;
    bool gameStarted;
    bool startScreen;
    QRectF scoreLabel;
    QPixmap pixmap;
};

#endif // ZOMBIE_INVASION_H
