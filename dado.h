#pragma once

#include <QWidget>
#include <QTimer>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class Dado; }
QT_END_NAMESPACE

class Dado : public QWidget
{
    Q_OBJECT

public:
    explicit Dado(QWidget *parent = nullptr);
    ~Dado() override;

    int resultado() const;
    void bloquearDado();

signals:
    /** Se emite cuando el dado termina de girar y se obtiene un resultado. */
    void resultadoObtenido(int resultado);

private:
    Ui::Dado *ui;
    QPixmap m_imagenes[6];
    int m_contadorAnimacion = -1;
    int m_resultado = -1;
};
