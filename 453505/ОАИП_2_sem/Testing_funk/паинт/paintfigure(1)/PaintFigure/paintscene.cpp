#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "squaree.h"
#include "star.h"
#include "ellipse.h"
#include "hexagon.h"
#include "circle.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены,
     * необходимо для устранения артефактов при отрисовке фигур
     * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
 * и помещаем её на сцену, сохранив указатель на неё в переменной
 * tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case SquareeType: {
        Squaree *item = new Squaree(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case EllipseType: {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case HexagonType: {
        Hexagon *item = new Hexagon(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case StarType: {
        Star *item = new Star(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case CircleType: {
        Circle *item = new Circle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    this->addItem(tempFigure);
}
void PaintScene::setFigureFillColor(const QColor &color)
{
    if (tempFigure) {
        tempFigure->setFillColor(color);
    }
}
