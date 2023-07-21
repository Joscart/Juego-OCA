#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

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

private slots:
    void on_btnSiguiente_clicked();

    void on_btnCancelar_clicked();

signals:
    void siguientePressed();

    void cancelarPressed();

private:
    Ui::SelectPlayer *ui;
    QList<QPixmap> m_imagenesFicha;
    QList<QLabel*> m_lblImagenesFicha;
};

#endif // SELECTPLAYER_H
