#ifndef BLOCKER_H
#define BLOCKER_H
#include <QRectF>
#include <QPainter>
#include <QImage>
#include "enemy.h"

class blocker : public QRectF
{
public:
    blocker();
    void reset();
    void advance();
    void remove();
    void didCollide();
    QRectF getRectF();
    bool isActive();
    QImage getImage();

private:
    int x;
    int y;
    QRectF rect;
    bool active;
    QImage image;

};

#endif // BLOCKER_H
