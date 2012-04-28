#include "enemy.h"

enemy::enemy()
{
    active = true;
}

void enemy::reset()
{
    rect.moveTo(x,y);
}

QImage enemy::getImage()
{
    return image;
}

QRectF enemy::getRect()
{
    return rect;
}


bool enemy::isActive()
{
    return active;
}

void enemy::remove()
{
    rect.moveTo(800,800);
}

void enemy::didCollide()
{
    active = false;
}

void enemy::advance()
{
    y++;
    rect.moveTo(x,y);
}
