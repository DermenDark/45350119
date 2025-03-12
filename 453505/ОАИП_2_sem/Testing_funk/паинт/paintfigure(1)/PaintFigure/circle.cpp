#include "circle.h"
#include <QPainter>

Circle::Circle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Circle::~Circle()
{

}
// Реализуем метод отрисовки круга
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color(), 2)); // Используем цвет обводки
    painter->setBrush(QBrush(fillColor()));

    qreal radius = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));

    //(фиксируем startPoint() как центр)
    QPointF center = startPoint();

    // Создаем квадратную область для рисования окружности
    QRectF rect(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);
    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
