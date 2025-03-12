#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();   // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);          // Запускаем таймер
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}


//Ромб
void MainWindow::on_action_8_triggered()
{
    scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::on_action_7_triggered()
{
    scene->setTypeFigure(PaintScene::StarType);
}

void MainWindow::on_action_6_triggered()
{
    scene->setTypeFigure(PaintScene::HexagonType);
}

void MainWindow::on_action_5_triggered()
{
    scene->setTypeFigure(PaintScene::TriangleType);
}

void MainWindow::on_action_4_triggered()
{
    scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::on_action_3_triggered()
{
    scene->setTypeFigure(PaintScene::SquareeType);
}

void MainWindow::on_action_2_triggered()
{
    scene->setTypeFigure(PaintScene::EllipseType);
}

void MainWindow::on_action_triggered()
{
    scene->setTypeFigure(PaintScene::CircleType);
}


void MainWindow::on_action_10_triggered()
{
//функция для вызова инструменнта(выделение фигуры)
}

void MainWindow::on_action_11_triggered()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this, "Choose Fill Color");
    if (color.isValid()) {
        scene->setFigureFillColor(color);
    }
}

