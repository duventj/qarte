/****************************************************************************
**
**
****************************************************************************/

#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

#include "lcdrange.h"

LCDRange::LCDRange(QWidget *parent)
    : QWidget(parent)
{

    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));
    connect(slider, SIGNAL(valueChanged(int)),
            this, SIGNAL(valueChanged(int)));

    QPushButton *moins = new QPushButton("-");
    moins->setFont(QFont("Times", 18, QFont::Bold));
    connect(moins, SIGNAL(clicked()), this, SLOT(Moins()));

    QPushButton *plus = new QPushButton(tr("+"));
    plus->setFont(QFont("Times", 18, QFont::Bold));
    connect(plus, SIGNAL(clicked()), this, SLOT(Plus()));


    QGridLayout *glayout = new QGridLayout();
    glayout->setSpacing(4);
    glayout->setObjectName(QString::fromUtf8("mise_layout"));
//     QVBoxLayout *layout = new QVBoxLayout;
    glayout->addWidget(moins,0,0);
    glayout->addWidget(lcd,0,1);
    glayout->addWidget(slider,1,1);
    glayout->addWidget(plus,0,2);
    setLayout(glayout);

//! [0]
    setFocusProxy(slider);
//! [0]
}

void LCDRange::Moins()
{
    this->setValue(this->value()-1);
}
void LCDRange::Plus()
{
    this->setValue(this->value()+1);
}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

//! [1]
void LCDRange::setRange(int minValue, int maxValue)
{
    if (minValue < 0 || maxValue > 99 || minValue > maxValue) {
        qWarning("LCDRange::setRange(%d, %d)\n"
                 "\tRange must be 0..99\n"
                 "\tand minValue must not be greater than maxValue",
                 minValue, maxValue);
        return;
    }
    slider->setRange(minValue, maxValue);
//! [1] //! [2]
}
//! [2]
