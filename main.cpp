#include <QtGui/QApplication>
#include "zombie_invasion.h"
#include <QKeyEvent>
#include <QTime>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDesktopWidget>
#include <QtGlobal>
#include <QLabel>
#include <QRectF>
#include <ctime>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 600;
  int HEIGHT = 500;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    srand(time(NULL));

    zombie_invasion zombieWindow;

    zombieWindow.setFixedSize(550,400);
    zombieWindow.setWindowTitle("Zombie Invasion");
    zombieWindow.show();
    center(zombieWindow);

    return app.exec();
}
