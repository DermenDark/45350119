#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T20:24:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PaintFigure
TEMPLATE = app


SOURCES += main.cpp\
    circle.cpp \
    ellipse.cpp \
    hexagon.cpp \
        mainwindow.cpp \
    romb.cpp \
    paintscene.cpp \
    figure.cpp \
    squaree.cpp \
    star.cpp \
    triangle.cpp \
    square.cpp

HEADERS  += mainwindow.h \
    circle.h \
    ellipse.h \
    hexagon.h \
    romb.h \
    paintscene.h \
    figure.h \
    squaree.h \
    star.h \
    triangle.h \
    square.h

FORMS    += mainwindow.ui
