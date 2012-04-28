#ifndef ATTACKER_H
#define ATTACKER_H

#include "enemy.h"
#include "QRectF"
#include "QImage"

class attacker : public QRectF
{
public:
    attacker();
    attacker(int);
    void reset();
    void advance();
    void remove();
    void didCollide();
    bool isActive();
    QRectF getRectF();
    QImage getImage();

private:
    int x;
    int y;
    int targetX;
    bool active;
    QRectF rect;
    QImage image;
};

#endif // ATTACKER_H
