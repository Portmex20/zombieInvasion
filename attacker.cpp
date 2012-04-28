#include "attacker.h"

attacker::attacker() {}

attacker::attacker(int pX)
{
    image.load("attacker.png");
    rect = image.rect();
    rect.moveTo(700,700);
    int temp = 600 - rect.width();
    x = rand() % temp;
    y = 25;
    targetX = pX;
    active = true;
}

void attacker::reset()
{
    rect.moveTo(x,y);
}

void attacker::advance()
{
    if (targetX > x)      { x++; }
    else if (targetX < x) { x--; }
    y += 3;
    rect.moveTo(x,y);
}

void attacker::remove()
{
    rect.moveTo(700,700);
}

QRectF attacker::getRectF()
{
    return rect;
}

void attacker::didCollide()
{
    active = false;
}

bool attacker::isActive()
{
    return active;
}

QImage attacker::getImage()
{
    return image;
}
