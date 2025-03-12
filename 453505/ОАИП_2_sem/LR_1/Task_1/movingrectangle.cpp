#include "movingrectangle.h"
#include <QPainter>

MovingRectangle::MovingRectangle(QWidget *parent)
    : QWidget(parent), x(0), y(0), width(45), height(38)
{
    setFixedSize(450, 500);  // Размер окна
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MovingRectangle::updatePosition);  // Таймер для обновления позиции
}

void MovingRectangle::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
    update();  // Обновление экрана
}

void MovingRectangle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(x, y, width, height);  // Рисуем прямоугольник
}

void MovingRectangle::updatePosition()
{
    // Плавное движение прямоугольника
    if (y > targetY) {
        y -= 1;  // Двигаем вверх
    } else if (y < targetY) {
        y += 1;  // Двигаем вниз
    }

    setPosition(x, y);  // Обновляем позицию
    update();

    if (y == targetY) {  // Если достигли цели, останавливаем движение
        timer->stop();
    }
}
