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
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(fillColor());  // Используем цвет заливки, заданный пользователем

    // Вычисляем ширину и высоту прямоугольника
    qreal width = qAbs(endPoint().x() - startPoint().x());
    qreal height = qAbs(endPoint().y() - startPoint().y());
    // Берем минимальное значение, чтобы прямоугольник был квадратом
    qreal side = qMin(width, height);

    // Создаем квадрат, используя startPoint() как верхний левый угол
    QRectF rect(startPoint(), QSizeF(side, side));
    painter->drawEllipse(rect);  // Рисуем круг, вписанный в квадрат

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
