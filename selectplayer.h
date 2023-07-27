#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

#include "qabstractbutton.h"
#include <jugador.h>
#include <QMessageBox>
#include <QSound>
#include <QWidget>
#include <QLabel>

namespace Ui {
class SelectPlayer;
}

class SelectPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit SelectPlayer(QWidget *parent = nullptr);
    ~SelectPlayer();

    QList<Jugador *> &jugadores();
    void setJugadores(Jugador *newJugadores);
    void delJugadores(Jugador *Jugador);

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

signals:
    void siguientePressed();

    void cancelarPressed();

private:
    Ui::SelectPlayer *ui;
    QList<QPixmap> m_imagenesFicha;
    QList<QPushButton*> m_lblImagenesFicha;
    QList<Jugador*> m_jugadores;
};

#endif // SELECTPLAYER_H
