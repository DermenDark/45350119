#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lift(new Lift(this)), house(new HouseWithLift(this))  // Исправили ошибку
{
    setWindowTitle("Лифт");

    // Создаем кнопки для этажей
    goUpButton1 = new QPushButton("1", this);
    goUpButton2 = new QPushButton("2", this);
    goUpButton3 = new QPushButton("3", this);
    goUpButton4 = new QPushButton("4", this);
    goUpButton5 = new QPushButton("5", this);
    goUpButton6 = new QPushButton("6", this);
    goUpButton7 = new QPushButton("7", this);
    goUpButton8 = new QPushButton("8", this);
    goUpButton9 = new QPushButton("9", this);
    goUpButton10 = new QPushButton("10", this);

    floorSpinBox = new QSpinBox(this);
    floorSpinBox->setRange(1, 10);  // Этажи от 1 до 10

    connect(goUpButton1, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(1); });
    connect(goUpButton2, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(2); });
    connect(goUpButton3, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(3); });
    connect(goUpButton4, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(4); });
    connect(goUpButton5, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(5); });
    connect(goUpButton6, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(6); });
    connect(goUpButton7, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(7); });
    connect(goUpButton8, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(8); });
    connect(goUpButton9, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(9); });
    connect(goUpButton10, &QPushButton::clicked, this, [=]() { goToSelectedFloor1(10); });

    connect(floorSpinBox, SIGNAL(valueChanged(int)), this, SLOT(goToSelectedFloor()));

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);  // Используем правильное имя для layout
    mainLayout->addWidget(floorSpinBox);

    QVBoxLayout *minLayout = new QVBoxLayout();
    minLayout->addWidget(house);

    mainLayout->addWidget(lift);   // Добавляем лифт в layout

    QGridLayout *gridLayout = new QGridLayout();

    // Добавляем кнопки для выбора этажей
    gridLayout->addWidget(goUpButton1, 0, 0);  // Строка 0, столбец 0
    gridLayout->addWidget(goUpButton2, 0, 1);  // Строка 0, столбец 1
    gridLayout->addWidget(goUpButton3, 1, 0);  // Строка 1, столбец 0
    gridLayout->addWidget(goUpButton4, 1, 1);  // Строка 1, столбец 1
    gridLayout->addWidget(goUpButton5, 2, 0);  // Строка 2, столбец 0
    gridLayout->addWidget(goUpButton6, 2, 1);  // Строка 2, столбец 1
    gridLayout->addWidget(goUpButton7, 3, 0);  // Строка 3, столбец 0
    gridLayout->addWidget(goUpButton8, 3, 1);  // Строка 3, столбец 1
    gridLayout->addWidget(goUpButton9, 4, 0);  // Строка 4, столбец 0
    gridLayout->addWidget(goUpButton10, 4, 1);

    mainLayout->addLayout(gridLayout);
}

MainWindow::~MainWindow() {}


void MainWindow::goToSelectedFloor() {
    lift->goToFloor(floorSpinBox->value());  // Перемещаем лифт на выбранный этаж
}

void MainWindow::goToSelectedFloor1(int floor) {
    lift->goToFloor(floor);  // Перемещаем лифт на выбранный этаж по кнопке
}

