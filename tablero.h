#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QLabel>
#include <dado.h>

namespace Ui {
class Tablero;
}

class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    ~Tablero();

    Dado *dado() const;

private:
    Ui::Tablero *ui;
    QList <QWidget*> m_casillas;
    QList <QLabel*> m_numeradores;
    void cargarWidgets();
    Dado *m_dado;
};

#endif // TABLERO_H
