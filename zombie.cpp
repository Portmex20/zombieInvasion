#include "zombie.h"

zombie::zombie()
{
    image.load("zombie.png");
    zrect = image.rect();
    zrect.moveTo(700,700);
    int temp = 600 - zrect.width();
    x = rand() % temp;
    y = 25;
    active = true;
}

void zombie::reset()
{
    zrect.moveTo(x,y);
}

void zombie::advance(int level)
{
    for (int i=0; i<(level + 2); i++){
        y++;
        zrect.moveTo(x,y);
    }
}

void zombie::remove()
{
    zrect.moveTo(600,400);
}

QRectF zombie::getRectF()
{
    return zrect;
}

void zombie::didCollide()
{
    active = false;
}

bool zombie::isActive()
{
    return active;
}

QImage zombie::getImage()
{
    return image;
}
