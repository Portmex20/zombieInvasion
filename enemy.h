#ifndef ENEMY_H
#define ENEMY_H
#include <QRectF>
#include <QPainter>
#include <QImage>

class enemy: public QRectF
{
public:
    enemy();
    void remove();
    void didCollide();
    virtual void reset();
    virtual void advance();
    virtual void advance(int) = 0;
    virtual QImage getImage();
    virtual QRectF getRect();
    virtual bool isActive();

protected:
    int x;
    int y;
    bool active;
    QRectF rect;
    QImage image;
};

#endif // ENEMY_H
