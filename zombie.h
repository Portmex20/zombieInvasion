#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "enemy.h"
#include <QRectF>
#include <QPainter>
#include <QImage>

class zombie : public QRectF
{
public:
    zombie();
    void reset();
    void advance(int);
    void remove();
    void didCollide();
    QRectF getRectF();
    QImage getImage();
    bool isActive();

private:
    int x;
    int y;
    QRectF zrect;
    bool active;
    QImage image;

};

#endif // ZOMBIE_H
