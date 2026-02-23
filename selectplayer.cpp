#include "selectplayer.h"
#include "ui_selectplayer.h"
#include "soundplayer.h"

#include <QMessageBox>

SelectPlayer::SelectPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectPlayer)
{
    ui->setupUi(this);

    // Cargar imágenes de fichas
    for (int i = 1; i <= 4; ++i) {
        m_imagenesFicha.append(
            QPixmap(QStringLiteral(":/Recursos/Imagenes/Ficha%1.png").arg(i)));
    }

    // Configurar botones de selección
    m_lblImagenesFicha = { ui->rbtnJugador_1, ui->rbtnJugador_2,
                           ui->rbtnJugador_3, ui->rbtnJugador_4 };

    for (int i = 0; i < 4; ++i) {
        m_lblImagenesFicha[i]->setIcon(QIcon(m_imagenesFicha[i]));
        m_lblImagenesFicha[i]->setIconSize(QSize(250, 250));
    }

    connect(ui->btnCancelar, &QPushButton::clicked,
            this, &SelectPlayer::on_btnCancelar_clicked);
    connect(ui->btnSiguiente, &QPushButton::clicked,
            this, &SelectPlayer::on_btnSiguiente_clicked);
}

SelectPlayer::~SelectPlayer()
{
    delete ui;
}

void SelectPlayer::on_btnSiguiente_clicked()
{
    if (ui->lineEditJugador_1->text().isEmpty()
        && ui->lineEditJugador_2->text().isEmpty()
        && ui->lineEditJugador_3->text().isEmpty()
        && ui->lineEditJugador_4->text().isEmpty()) {
        QMessageBox::warning(this, tr("Nuevo Juego"),
                             tr("Necesita seleccionar al menos 1 ficha"));
        return;
    }
    emit siguientePressed();
}

void SelectPlayer::on_btnCancelar_clicked()
{
    emit cancelarPressed();
}

QList<Jugador *> &SelectPlayer::jugadores()
{
    return m_jugadores;
}

void SelectPlayer::actualizarJugador(int numJugador, const QString &nombre)
{
    // Eliminar jugador existente con ese número
    eliminarJugador(numJugador);

    if (nombre.isEmpty()) {
        SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundAlerta.wav"));
        return;
    }

    auto *jugador = new Jugador(this);
    jugador->setNombre(nombre);
    jugador->setFichaImagen(m_imagenesFicha[numJugador - 1]);
    jugador->setNumJugador(numJugador);

    if (m_jugadores.size() >= 4) {
        m_jugadores.removeFirst();
    }
    m_jugadores.append(jugador);
    SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundPregunta2.wav"));
}

void SelectPlayer::eliminarJugador(int numJugador)
{
    for (int i = m_jugadores.size() - 1; i >= 0; --i) {
        if (m_jugadores[i]->numJugador() == numJugador) {
            delete m_jugadores.takeAt(i);
        }
    }
}

void SelectPlayer::on_rbtnJugador_1_clicked()
{
    ui->lineEditJugador_1->setFocus();
}

void SelectPlayer::on_rbtnJugador_2_clicked()
{
    ui->lineEditJugador_2->setFocus();
}

void SelectPlayer::on_rbtnJugador_3_clicked()
{
    ui->lineEditJugador_3->setFocus();
}

void SelectPlayer::on_rbtnJugador_4_clicked()
{
    ui->lineEditJugador_4->setFocus();
}

void SelectPlayer::on_lineEditJugador_1_textChanged(const QString &arg1)
{
    actualizarJugador(1, arg1);
}

void SelectPlayer::on_lineEditJugador_2_textChanged(const QString &arg1)
{
    actualizarJugador(2, arg1);
}

void SelectPlayer::on_lineEditJugador_3_textChanged(const QString &arg1)
{
    actualizarJugador(3, arg1);
}

void SelectPlayer::on_lineEditJugador_4_textChanged(const QString &arg1)
{
    actualizarJugador(4, arg1);
}
