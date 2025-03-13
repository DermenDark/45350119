#include "star.h"
#include <QPainter>

Star::Star(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Star::~Star()
{

}

// Реализуем метод отрисовки
void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(fillColor());  // Используем цвет заливки, заданный пользователем

    // Определяем радиус звезды как половину максимального расстояния по X или Y
    qreal radius = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y())) / 2.0;

    // Фиксируем центр звезды в startPoint()
    QPointF center = startPoint();

    // Количество вершин звезды
    int numPoints = 10;  // 5 длинных лучей + 5 коротких точек

    QVector<QPointF> points;
    for (int i = 0; i < numPoints; ++i)
    {
        // Чередуем длинные и короткие лучи
        qreal r = (i % 2 == 0) ? radius : radius / 2.5;

        qreal angle = i * 2 * M_PI / numPoints;  // Угол для текущей точки
        qreal x = center.x() + r * cos(angle);
        qreal y = center.y() + r * sin(angle);

        points.append(QPointF(x, y));
    }

    // Рисуем звезду
    QPolygonF starPolygon(points);
    painter->drawPolygon(starPolygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
