#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include "figure.h"
#include "ui_figurepropertiesdialog.h"  // или ui_form.h если вы переименовали ui файл

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(Figure *figure, QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_applyButton_2_clicked();
    void on_changeColorButton_2_clicked();
    void onRotationChanged(int value);  // Слот для изменения угла поворота
    void onSizeChanged(int value);     // Слот для изменения размера

private:
    Ui::Form *ui;  // Можно заменить на Ui::Form, если вы переименовали ui
    Figure *m_figure;  // Указатель на фигуру, для которой изменяются свойства
    bool m_dragging;
    QPoint m_lastMousePosition;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // FORM_H
