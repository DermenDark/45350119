#include "lift.h"
#include <QMessageBox>

Lift::Lift(QWidget *parent)
    : MovingRectangle(parent), currentFloor(1)
{
    setPosition(200, 360);  // Изначальная позиция лифта
}

void Lift::goToFloor(int floor)
{
    if (floor < 1 || floor > 10) {
        QMessageBox::warning(this, "Ошибка", "Неверный этаж.");
        return;
    }

    targetY = 400 - (floor * 40); // Целевая позиция по Y для лифта
    currentFloor = floor;

    timer->start(7);  // Запускаем таймер для плавного движения
}
