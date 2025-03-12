#ifndef SQUAREE_H
#define SQUAREE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Squaree : public Figure
{
    Q_OBJECT

public:
    explicit Squaree(QPointF point, QObject *parent = 0);
    ~Squaree();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H
