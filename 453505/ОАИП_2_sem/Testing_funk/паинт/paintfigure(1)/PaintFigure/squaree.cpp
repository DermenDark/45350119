#include "squaree.h"
#include <QPainter>

Squaree::Squaree(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Squaree::~Squaree()
{

}

// Реализуем метод отрисовки
void Squaree::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    // Определяем длину стороны квадрата как максимальное расстояние по X или Y
    qreal side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));

    // Вычисляем координаты конца квадрата, исходя из фиксированной начальной точки
    qreal left = startPoint().x();
    qreal top = startPoint().y();

    if (endPoint().x() < startPoint().x()) {
        left -= side;  // Растем влево
    }
    if (endPoint().y() < startPoint().y()) {
        top -= side;  // Растем вверх
    }

    // Создаем квадрат
    QRectF rect(left, top, side, side);

    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}



