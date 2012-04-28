#include "smartattacker.h"

smartAttacker::smartAttacker()
{
    image.load("attacker.png");
    rect = image.rect();
    rect.moveTo(700,700);
    int temp = 600 - rect.width();
    x = rand() % temp;
    y = 25;
    active = true;
}

void smartAttacker::advance(int pX)
{


    for (int i=0; i<2; i++){
        if (pX > x)
            x++;
        else if (pX < x)
            x--;
        y++;
        rect.moveTo(x,y);
    }

}
