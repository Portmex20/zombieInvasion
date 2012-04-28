#ifndef MEDPACK_H
#define MEDPACK_H
#include <QRectF>
#include <QPainter>
#include <QImage>

class medpack : public QRectF
{
public:
    medpack();
    void advance();
    void reset();
    void remove();
    QRectF getRectF();
    QImage getImage();
    bool isActive();

private:
    int x;
    int y;
    QRectF rect;
    QImage image;
    bool active;
};

#endif // MEDPACK_H
