#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Ellipse::~Ellipse()
{

}

// Реализуем метод отрисовки
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(fillColor());  // Используем цвет заливки, заданный пользователем

    // Определяем прямоугольник, в который вписывается эллипс
    QRectF rect;
    rect.setTopLeft(startPoint());  // Фиксируем начальную точку
    rect.setBottomRight(endPoint()); // Конечная точка задаёт размер эллипса

    // Рисуем эллипс
    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}


