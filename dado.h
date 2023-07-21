#ifndef DADO_H
#define DADO_H

#include <QWidget>
#include <QTimer>
#include <QRandomGenerator>

namespace Ui {
class Dado;
}

class Dado : public QWidget
{
    Q_OBJECT

public:
    explicit Dado(QWidget *parent = nullptr);
    ~Dado();

    int resultado() const;

    void bloquearDado();

private:
    Ui::Dado *ui;
    QPixmap imagenes[6];
    int contadorAnimacion = -1;
    int m_resultado = -1;
};

#endif // DADO_H
