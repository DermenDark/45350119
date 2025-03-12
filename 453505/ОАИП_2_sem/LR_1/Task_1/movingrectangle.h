#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class MovingRectangle : public QWidget
{
    Q_OBJECT

protected:
    int x, y;        // Позиция прямоугольника
    int width, height; // Размер прямоугольника
    int targetY;      // Целевая координата Y
    int maxY;         // Максимальная граница Y (можно использовать для ограничения движения)


public:
    QTimer *timer;
    MovingRectangle(QWidget *parent = nullptr);
    virtual ~MovingRectangle() {}
    void setPosition(int newX, int newY);  // Устанавливает позицию прямоугольника
    virtual void paintEvent(QPaintEvent *event) override;  // Отображение прямоугольника
    void updatePosition();  // Метод для плавного движения прямоугольника
};

#endif // MOVINGRECTANGLE_H
