#ifndef HOUSEWITHLIFT_H
#define HOUSEWITHLIFT_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class HouseWithLift : public QWidget {
    Q_OBJECT

public:
    explicit HouseWithLift(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // HOUSEWITHLIFT_H

