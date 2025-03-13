#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>

// Реализация конструктора и других методов...

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Проверяем, активирован ли режим выделения
    if (selecting) {
        // Преобразуем координаты из области виджета в координаты сцены
        QPointF scenePos = ui->graphicsView->mapToScene(event->pos());

        // Выбираем объект под курсором
        scene->selectItemAt(scenePos);

        // Получаем выделенный объект
        QGraphicsItem *selectedItem = nullptr;
        if (!scene->selectedItems().isEmpty()) {
            selectedItem = scene->selectedItems().first();  // Получаем первый выбранный объект
        }

        // Проверяем, является ли выбранный объект фигурой
        Figure *figure = qgraphicsitem_cast<Figure *>(selectedItem);
        if (figure) {
            // Если объект — это фигура, открываем диалоговое окно для изменения её свойств
            Form dialog(figure, this);
            dialog.exec();  // Показываем окно модально
        } else {
            // Если объект не является фигурой, показываем предупреждение
            QMessageBox::warning(this, "Warning", "Please select a valid figure.");
        }

        // Отключаем режим выделения после первого выбора
        selecting = false;
        ui->graphicsView->setCursor(Qt::ArrowCursor);  // Возвращаем курсор в обычный вид
    }

    // Передаем обработку события в родительский класс, если нужно
    QMainWindow::mousePressEvent(event);
}
