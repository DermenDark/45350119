/********************************************************************************
** Form generated from reading UI file 'figurepropertiesdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGUREPROPERTIESDIALOG_H
#define UI_FIGUREPROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *colorLabel_2;
    QPushButton *changeColorButton_2;
    QPushButton *applyButton_2;
    QSlider *rotationSlider;
    QLabel *rotationLabel;
    QSlider *sizeSlider;
    QLabel *sizeLabel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(385, 179);
        colorLabel_2 = new QLabel(Form);
        colorLabel_2->setObjectName(QString::fromUtf8("colorLabel_2"));
        colorLabel_2->setGeometry(QRect(210, 40, 93, 51));
        changeColorButton_2 = new QPushButton(Form);
        changeColorButton_2->setObjectName(QString::fromUtf8("changeColorButton_2"));
        changeColorButton_2->setGeometry(QRect(10, 50, 161, 31));
        applyButton_2 = new QPushButton(Form);
        applyButton_2->setObjectName(QString::fromUtf8("applyButton_2"));
        applyButton_2->setGeometry(QRect(10, 10, 101, 31));
        rotationSlider = new QSlider(Form);
        rotationSlider->setObjectName(QString::fromUtf8("rotationSlider"));
        rotationSlider->setGeometry(QRect(20, 100, 161, 22));
        rotationSlider->setMinimum(0);
        rotationSlider->setMaximum(360);
        rotationSlider->setValue(0);
        rotationSlider->setOrientation(Qt::Horizontal);
        rotationLabel = new QLabel(Form);
        rotationLabel->setObjectName(QString::fromUtf8("rotationLabel"));
        rotationLabel->setGeometry(QRect(210, 100, 93, 21));
        sizeSlider = new QSlider(Form);
        sizeSlider->setObjectName(QString::fromUtf8("sizeSlider"));
        sizeSlider->setGeometry(QRect(20, 140, 161, 22));
        sizeSlider->setMinimum(1);
        sizeSlider->setMaximum(100);
        sizeSlider->setValue(1);
        sizeSlider->setOrientation(Qt::Horizontal);
        sizeLabel = new QLabel(Form);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));
        sizeLabel->setGeometry(QRect(220, 140, 93, 21));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        colorLabel_2->setText(QCoreApplication::translate("Form", "Current Color", nullptr));
        changeColorButton_2->setText(QCoreApplication::translate("Form", "Change Color", nullptr));
        applyButton_2->setText(QCoreApplication::translate("Form", "Apply", nullptr));
        rotationLabel->setText(QCoreApplication::translate("Form", "Rotation: 0\302\260", nullptr));
        sizeLabel->setText(QCoreApplication::translate("Form", "Size: 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGUREPROPERTIESDIALOG_H
