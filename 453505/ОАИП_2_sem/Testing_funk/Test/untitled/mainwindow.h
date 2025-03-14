#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void slotAlarmTimer();


private:
    void resizeEvent(QResizeEvent *event);

    QTimer              *timer;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
