#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <QColorDialog>
#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PaintScene *scene;  // Объявляем кастомную графическую сцену
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                         * графической сцены
                         * */
private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();

    void on_action_8_triggered();
    void on_action_7_triggered();
    void on_action_6_triggered();
    void on_action_5_triggered();
    void on_action_4_triggered();
    void on_action_3_triggered();
    void on_action_2_triggered();
    void on_action_triggered();
    void on_action_10_triggered();
    void on_action_11_triggered();
};

#endif // MAINWINDOW_H
