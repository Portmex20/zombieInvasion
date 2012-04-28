#include "player.h"
#include <QPainter>
#include <QStyleOption>

player::player()
{
    image.load("android.png");
    rect = image.rect();
    rect.moveTo(700,700);
}

void player::reset()
{
    int y = rect.height();
    int x = rect.width();
    rect.moveTo(300-x/2,498-y);
}

void player::moveLeft(int pos)
{
    if (rect.left() >= 2)
        rect.moveTo(pos,rect.top());
}

void player::moveRight(int pos)
{
    if (rect.right() <= 598)
        rect.moveTo(pos,rect.top());
}

QRectF player::getRectF()
{
    return rect;
}

QImage player::getImage()
{
    return image;
}
