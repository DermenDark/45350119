#include "hexagon.h"
#include <QPainter>

Hexagon::Hexagon(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Hexagon::~Hexagon()
{

}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(fillColor());  // Используем цвет заливки, заданный пользователем

    // Определяем радиус шестиугольника
    qreal radius = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));

    // Фиксируем центр шестиугольника в startPoint()
    QPointF center = startPoint();

    QVector<QPointF> points;
    for (int i = 0; i < 6; ++i) // 6 углов шестиугольника
    {
        qreal angle = M_PI / 3 * i;  // Углы кратны 60 градусам
        qreal x = center.x() + radius * cos(angle);
        qreal y = center.y() + radius * sin(angle);

        points.append(QPointF(x, y));
    }

    // Рисуем шестиугольник
    QPolygonF hexagonPolygon(points);
    painter->drawPolygon(hexagonPolygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

