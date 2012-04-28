#ifndef SMARTATTACKER_H
#define SMARTATTACKER_H
#include <QPainter>
#include <QImage>
#include "enemy.h"


class smartAttacker : public enemy
{
public:
    smartAttacker();
    void advance(int);
};

#endif // SMARTATTACKER_H
