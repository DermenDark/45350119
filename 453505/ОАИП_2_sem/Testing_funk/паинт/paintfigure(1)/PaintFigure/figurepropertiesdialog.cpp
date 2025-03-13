#include "figurepropertiesdialog.h"
#include "ui_figurepropertiesdialog.h"
#include <QColorDialog>

Form::Form(Figure *figure, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form),  // Создание UI
    m_figure(figure)
{
    ui->setupUi(this);  // Настройка UI

    if (m_figure) {
        // Устанавливаем цвет фона метки (показываем текущий цвет фигуры)
        ui->colorLabel_2->setStyleSheet(QString("background-color: %1").arg(m_figure->fillColor().name()));
        connect(ui->rotationSlider, &QSlider::valueChanged, this, &Form::onRotationChanged);
        connect(ui->sizeSlider, &QSlider::valueChanged, this, &Form::onSizeChanged);
    }
}

Form::~Form()
{
    delete ui;  // Освобождаем ресурсы
}

#include <QMouseEvent>

// При нажатии левой кнопкой мыши фиксируем начальную позицию курсора
void Form::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_lastMousePosition = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
}

// При перемещении мыши двигаем окно, если кнопка мыши зажата
void Form::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - m_lastMousePosition);
        event->accept();
    }
}



void Form::on_changeColorButton_2_clicked()
{
    QColor color = QColorDialog::getColor(m_figure->fillColor(), this, "Выберите цвет");
    if (color.isValid()) {
        m_figure->setFillColor(color);
        m_figure->update();
        ui->colorLabel_2->setStyleSheet(QString("background-color: %1").arg(color.name()));
        m_figure->update();
    }
}

void Form::on_applyButton_2_clicked()
{
    // Применить изменения и закрыть окно
    this->accept();
}

void Form::onRotationChanged(int value)
{
    if (m_figure) {
        m_figure->setRotation(value);  // Поворот фигуры относительно центра
        ui->rotationLabel->setText(QString("Rotation: %1°").arg(value));  // Обновляем метку
    }
}


// Слот для изменения размера
void Form::onSizeChanged(int value)
{
    if (m_figure) {
        m_figure->setScale(value / 10.0);  // Масштабирование фигуры (предполагается, что scale — это значение от 0.01 до 1)
        ui->sizeLabel->setText(QString("Size: %1").arg(value));  // Обновляем метку
    }
}

