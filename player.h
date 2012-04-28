#ifndef PLAYER_H
#define PLAYER_H

#include <QRectF>
#include <QPainter>
#include <QImage>


class player : public QRectF
{

public:
    player();
    void reset();
    void moveLeft(int pos);
    void moveRight(int pos);
    QRectF getRectF();
    QImage getImage();
    int drop[5];
    
private:
    QRectF rect;
    QImage image;

};

#endif // PLAYER_H
