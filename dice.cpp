#include "dice.h"
#include "ui_dice.h"

#include <QMouseEvent>
#include <QRandomGenerator>

Dice::Dice(QWidget* parent)
    : QLabel(parent)
    , m_dicePixmaps{
        QPixmap(":/Dice-1.png").scaled(QSize(400, 400), Qt::KeepAspectRatio),
        QPixmap(":/Dice-2.png").scaled(QSize(400, 400), Qt::KeepAspectRatio),
        QPixmap(":/Dice-3.png").scaled(QSize(400, 400), Qt::KeepAspectRatio),
        QPixmap(":/Dice-4.png").scaled(QSize(400, 400), Qt::KeepAspectRatio),
        QPixmap(":/Dice-5.png").scaled(QSize(400, 400), Qt::KeepAspectRatio),
        QPixmap(":/Dice-6.png").scaled(QSize(400, 400), Qt::KeepAspectRatio)

    }
{
    resize(400, 400);
    // Establecer la imagen inicial del dado
    setPixmap(m_dicePixmaps[0]);
}

int Dice::roll() {
    int randomResult = QRandomGenerator::global()->bounded(6);
    setPixmap(m_dicePixmaps[randomResult]);
    myData=randomResult+1;
    return randomResult + 1;
}

void Dice::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        roll();
    }
}
