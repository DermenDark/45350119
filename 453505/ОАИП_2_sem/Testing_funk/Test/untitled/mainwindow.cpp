#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

#include <QPushButton>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)  // b теперь поле класса
{
    ui->setupUi(this);

    // Создаём сцену и графическое представление
    QGraphicsView *view = new QGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);
    setCentralWidget(view);  // Делаем QGraphicsView центральным виджетом

    QAction *action = new QAction("Нажми меня", this);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    connect(action, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Информация", "Кнопка нажата!");
    });

    // Кнопка
    QPushButton *button = new QPushButton("Кнопка", this);
    button->setGeometry(10, 20, width(), 100);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [this]() {  // b теперь поле класса
        qDebug() << "1+77";
    });

    // Добавляем тулбар и кнопку
    QToolBar *toolbar = addToolBar("Toolbar");
    toolbar->addAction(action);
//    toolbar->addWidget(button);

    // Таймер
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &MainWindow::slotAlarmTimer);
    timer->start(50);
}

void MainWindow::slotAlarmTimer() {
    qDebug() << "Таймер сработал!";
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(50);
    QMainWindow::resizeEvent(event);  // Вызываем событие родительского класса
}

MainWindow::~MainWindow() {
    delete ui;
}

