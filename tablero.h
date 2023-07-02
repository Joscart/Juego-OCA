#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include "casilla.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QFrame>
#include <QPushButton>
#include <QMessageBox>
#include <dice.h>

namespace Ui {
class Tablero;
}

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    ~Tablero();
    QList<Casilla> labels;
    QPushButton *piece1;
    QPushButton *piece2;

private:
    Ui::Tablero *ui;
    QVBoxLayout *layout1;
    QGridLayout *gridLayout;
    QList<Casilla> getLabels();

private slots:
    void handleButton();
    void handleSecondWindowData(int data);
};

#endif // TABLERO_H
