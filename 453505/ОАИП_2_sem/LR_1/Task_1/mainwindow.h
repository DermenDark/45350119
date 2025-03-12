#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lift.h"
#include "house.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Lift *lift;
    HouseWithLift *house;
    QPushButton *goUpButton1;
    QPushButton *goUpButton2;
    QPushButton *goUpButton3;
    QPushButton *goUpButton4;
    QPushButton *goUpButton5;
    QPushButton *goUpButton6;
    QPushButton *goUpButton7;
    QPushButton *goUpButton8;
    QPushButton *goUpButton9;
    QPushButton *goUpButton10;
    QSpinBox *floorSpinBox;        // Элементы для выбора этажа

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void goToSelectedFloor();  // Для выбора этажа с помощью QSpinBox
    void goToSelectedFloor1(int floor);  // Для выбора этажа с помощью кнопок
};

#endif // MAINWINDOW_H
