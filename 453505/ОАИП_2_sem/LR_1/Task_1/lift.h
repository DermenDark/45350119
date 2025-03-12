#ifndef LIFT_H
#define LIFT_H

#include "movingrectangle.h"
#include <QMessageBox>

class Lift : public MovingRectangle
{
    Q_OBJECT

private:
    int currentFloor;  // Текущий этаж лифта

public:
    explicit Lift(QWidget *parent = nullptr);
    void goToFloor(int floor);  // Метод для перемещения на заданный этаж
};

#endif // LIFT_H
