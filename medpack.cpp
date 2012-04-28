#include "medpack.h"

medpack::medpack()
{
    image.load("medpack.png");
    rect = image.rect();
    active = false;
    rect.moveTo(700,700);
}

void medpack::reset()
{
    active = true;
    int temp = 600 - rect.width();
    x = rand() % temp;
    y = 25;
    rect.moveTo(x,y);
}

void medpack::advance()
{
    y++;
    rect.moveTo(x,y);
}

QRectF medpack::getRectF()
{
    return rect;
}

QImage medpack::getImage()
{
    return image;
}

bool medpack::isActive()
{
    return active;
}

void medpack::remove()
{
    rect.moveTo(700,700);
    active = false;
}
