#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

#include <jugador.h>
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

    void on_rbtnJugador_4_toggled(bool checked);

    void on_rbtnJugador_3_toggled(bool checked);

    void on_rbtnJugador_2_toggled(bool checked);

    void on_rbtnJugador_1_toggled(bool checked);

signals:
    void siguientePressed();

    void cancelarPressed();

private:
    Ui::SelectPlayer *ui;
    QList<QPixmap> m_imagenesFicha;
    QList<QLabel*> m_lblImagenesFicha;
    QList<Jugador*> m_jugadores;
};

#endif // SELECTPLAYER_H
