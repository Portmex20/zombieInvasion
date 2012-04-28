#include "blocker.h"

blocker::blocker()
{
    image.load("spear.png");
    rect = image.rect();
    int temp = 600 - rect.width();
    x = rand() % temp;
    y = 25;
    active = true;
    rect.moveTo(700,700);
}

void blocker::reset()
{
    rect.moveTo(x,25);
}

void blocker::advance()
{
    for (int i=0; i<3; i++){
        y++;
        rect.moveTo(x,y);
    }
}

void blocker::remove()
{
    rect.moveTo(600,400);
}

QRectF blocker::getRectF()
{
    return rect;
}

void blocker::didCollide()
{
    active = false;
}

bool blocker::isActive()
{
    return active;
}

QImage blocker::getImage()
{
    return image;
}
