#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure READ typeFigure WRITE setTypeFigure NOTIFY typeFigureChanged)
    Q_PROPERTY(QColor collorFill READ collorFill WRITE setCollorFill NOTIFY collorFillChanged)

public:
    explicit PaintScene(QObject *parent = nullptr);
    ~PaintScene();

    void selectItemAt(const QPointF &position);

    int typeFigure() const;
    void setTypeFigure(const int type);

    // Перечисление типов фигур
    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        SquareeType,
        StarType,
        HexagonType,
        EllipseType,
        CircleType
    };

    QColor collorFill() const { return m_collorFill; }  // Геттер
    void setCollorFill(const QColor &color);           // Сеттер
    void removeAllFigures();

public slots:
    void setFigureFillColor(const QColor &color);

signals:

    void typeFigureChanged();
    void collorFillChanged();  // Новый сигнал

private:
    Figure *tempFigure;
    int m_typeFigure;
    QColor m_collorFill = Qt::transparent; // Исправленная переменная

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H

