#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "jugador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SelectPlayer; }
QT_END_NAMESPACE

class SelectPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit SelectPlayer(QWidget *parent = nullptr);
    ~SelectPlayer() override;

    QList<Jugador *> &jugadores();

signals:
    void siguientePressed();
    void cancelarPressed();

private slots:
    void on_btnSiguiente_clicked();
    void on_btnCancelar_clicked();
    void on_rbtnJugador_1_clicked();
    void on_rbtnJugador_2_clicked();
    void on_rbtnJugador_3_clicked();
    void on_rbtnJugador_4_clicked();
    void on_lineEditJugador_1_textChanged(const QString &arg1);
    void on_lineEditJugador_2_textChanged(const QString &arg1);
    void on_lineEditJugador_3_textChanged(const QString &arg1);
    void on_lineEditJugador_4_textChanged(const QString &arg1);

private:
    Ui::SelectPlayer *ui;
    QList<QPixmap> m_imagenesFicha;
    QList<QPushButton *> m_lblImagenesFicha;
    QList<Jugador *> m_jugadores;

    void actualizarJugador(int numJugador, const QString &nombre);
    void eliminarJugador(int numJugador);
};
