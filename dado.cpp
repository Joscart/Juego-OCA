#include "dado.h"
#include "ui_dado.h"
#include "soundplayer.h"

Dado::Dado(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dado)
{
    ui->setupUi(this);

    for (int i = 0; i < 6; ++i) {
        m_imagenes[i] = QPixmap(
            QStringLiteral(":/Recursos/Imagenes/Dice%1.png").arg(i + 1));
    }

    auto *timer = new QTimer(this);

    connect(ui->btnDado, &QPushButton::clicked, this, [timer, this]() {
        m_contadorAnimacion = -1;
        m_resultado = -1;
        timer->start(200);
        SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundDado.wav"));
    });

    ui->btnDado->setIcon(m_imagenes[0]);
    ui->btnDado->setIconSize(QSize(250, 250));

    connect(timer, &QTimer::timeout, this, [timer, this]() {
        if (++m_contadorAnimacion < 6) {
            ui->btnDado->setIcon(m_imagenes[m_contadorAnimacion]);
            ui->btnDado->setEnabled(false);
        } else {
            timer->stop();
            m_contadorAnimacion = QRandomGenerator::global()->bounded(0, 6);
            ui->btnDado->setIcon(m_imagenes[m_contadorAnimacion]);
            m_resultado = m_contadorAnimacion + 1;
            emit resultadoObtenido(m_resultado);
        }
    });
}

Dado::~Dado()
{
    delete ui;
}

int Dado::resultado() const
{
    return m_resultado;
}

void Dado::bloquearDado()
{
    ui->btnDado->setEnabled(true);
}
