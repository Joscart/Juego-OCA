#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>

namespace Ui {
class Tablero;
}

class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    ~Tablero();

private:
    Ui::Tablero *ui;
};

#endif // TABLERO_H
