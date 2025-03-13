#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsSceneMouseEvent>  // Для обработки кликов
#include <QCursor>                   // Для получения позиции курсора
#include <QStatusBar>
#include <QMessageBox>

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
    ui->graphicsView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->graphicsView, &QGraphicsView::customContextMenuRequested,
            this, &MainWindow::on_graphicsView_customContextMenuRequested);

    timer = new QTimer(this);  // Инициализируем таймер (указываем родительский объект)

    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateScene);

    timer->setInterval(100);   // Устанавливаем интервал в 100 мс (по умолчанию таймер повторяется)
    timer->start();            // Запускаем таймер
}


MainWindow::~MainWindow()
{
    delete ui;
}
// В .cpp файле
void MainWindow::updateScene()
{
    qDebug() << "Timer triggered";
    scene->update();  // Обновляем сцену (перерисовываем её)
    qDebug() << "132456345324";
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
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

void MainWindow::on_action_11_triggered()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this, "Choose Fill Color");
    if (color.isValid()) {
        scene->setFigureFillColor(color);  // Устанавливаем цвет для всех фигур на сцене
    }
}

void MainWindow::on_action_12_triggered()
{
    // Вызываем метод для удаления всех фигур на сцене
    scene->removeAllFigures();
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (selecting) {
        QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
        QGraphicsItem *itemUnderCursor = scene->itemAt(scenePos, QTransform());

        Figure *figure = qgraphicsitem_cast<Figure *>(itemUnderCursor);
        if (figure) {
            // Открываем диалоговое окно для изменения свойств фигуры
            Form dialog(figure, this);
            if (dialog.exec() == QDialog::Accepted) {
                // Если пользователь принял изменения, обновляем фигуру
                figure->update();
                scene->update();   // Обновляем всю сцену на всякий случай
            }
        } else {
            QMessageBox::warning(this, "Warning", "Please select a valid figure.");
        }

        selecting = false;
        ui->graphicsView->setCursor(Qt::ArrowCursor);
    }

    QMainWindow::mousePressEvent(event);
}



void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (selecting) {
        QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
        QGraphicsItem *itemUnderCursor = scene->itemAt(scenePos, QTransform());

        if (itemUnderCursor) {
            // Под курсором фигура, меняем курсор на крестик
            ui->graphicsView->setCursor(Qt::CrossCursor);
        } else {
            // Нет фигуры под курсором, восстанавливаем обычный курсор
            ui->graphicsView->setCursor(Qt::ArrowCursor);
        }
    }

    // Вызываем базовый обработчик, если нужно
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::on_action_10_triggered()
{
    // Активируем режим выделения
    selecting = true;
    ui->graphicsView->setCursor(Qt::CrossCursor);  // Устанавливаем курсор крестиком

    // Сообщаем пользователю, что нужно выбрать фигуру
    statusBar()->showMessage("Select an object on the scene.", 2000);  // Сообщение на 2 секунды
}

void MainWindow::on_graphicsView_customContextMenuRequested(const QPoint &pos)
{
    // Преобразуем координаты из области виджета в координаты сцены
    QPointF scenePos = ui->graphicsView->mapToScene(pos);

    // Выбираем объект под курсором
    QGraphicsItem *selectedItem = scene->itemAt(scenePos, QTransform());

    Figure *figure = qgraphicsitem_cast<Figure *>(selectedItem);
    if (figure) {
        // Если объект — это фигура, открываем диалоговое окно для изменения её свойств
        Form dialog(figure, this);
        dialog.exec();
    } else {
        QMessageBox::warning(this, "Warning", "No figure selected.");
    }
}
