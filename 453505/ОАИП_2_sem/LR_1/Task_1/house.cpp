#include "house.h"
#include <QPainter>

HouseWithLift::HouseWithLift(QWidget *parent) : QWidget(parent) {
    setFixedSize(450, 650);
}

void HouseWithLift::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Рисуем дом
    painter.setBrush(Qt::lightGray);
    painter.drawRect(25, 40, 230, 400);
    // Рисуем траву
    painter.setBrush(Qt::green);
    painter.drawRect(0, 440, 450, 250);

    painter.setPen(Qt::black);
    for (int i = 0; i <= 10; i++) {
        int y = 440 - i * 40;  // 440 - нижняя граница   40 - высота этажа
        painter.drawLine(25, y, 255, y);
    }
}

