#include "tablero.h"
#include "ui_tablero.h"
#include "soundplayer.h"

#include <QElapsedTimer>

Tablero::Tablero(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tablero)
    , m_music(this)
{
    ui->setupUi(this);
    m_dado = new Dado(this);

    m_music.setSource(QUrl(QStringLiteral("qrc:/Recursos/Audio/MusicLoop.wav")));
    m_music.setLoopCount(QSoundEffect::Infinite);
    m_music.setVolume(0.25);
    m_music.play();

    // Conexión del dado: usar señal propia en vez del hack de windowTitle
    connect(m_dado, &Dado::resultadoObtenido, this, &Tablero::procesarTirada);

    m_formulario = new Formulario(this);
    m_formulario->setJugadores(&m_jugadores);

    connect(this, &Tablero::actualChanged, m_formulario, &Formulario::setFichaActual);

    cargarWidgets();

    connect(m_formulario, &Formulario::respuesta, this, [this](bool esVerdadero) {
        const QString respuestaUsuario = esVerdadero ? QStringLiteral("verdadero")
                                                     : QStringLiteral("falso");
        if (m_formulario->actual()->respuesta() != respuestaUsuario) {
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundIncorrecto.wav"));
            m_formulario->incorrecto();
            moverFicha(-1 * m_dado->resultado());
            return;
        }
        SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundCorrecto.wav"));
        m_formulario->correcto();
        cambiarTurno();
        m_formulario->usarPregunta();
    });

    // Sombras de texto para los numeradores
    constexpr int xOffset = 2;
    constexpr int yOffset = 1;

    for (int i = 0; i < m_numeradores.size(); ++i) {
        m_numeradores[i]->setText(QString::number(i + 1));
        auto *effect = new QGraphicsDropShadowEffect(m_numeradores[i]);
        effect->setColor(Qt::white);
        effect->setOffset(xOffset, yOffset);
        m_numeradores[i]->setGraphicsEffect(effect);
    }

    // Sombra para labels de inicio y meta
    auto *efectoInicio = new QGraphicsDropShadowEffect(ui->lblInicio);
    efectoInicio->setColor(Qt::white);
    efectoInicio->setOffset(xOffset, yOffset);
    ui->lblInicio->setGraphicsEffect(efectoInicio);

    auto *efectoMeta = new QGraphicsDropShadowEffect(ui->lblMeta);
    efectoMeta->setColor(Qt::white);
    efectoMeta->setOffset(xOffset, yOffset);
    ui->lblMeta->setGraphicsEffect(efectoMeta);
}

Tablero::~Tablero()
{
    delete ui;
}

void Tablero::cargarWidgets()
{
    //Cargar manualmente label y casillas creados por ui
    m_numeradores.append(ui->lblCasilla_1);
    m_numeradores.append(ui->lblCasilla_2);
    m_numeradores.append(ui->lblCasilla_3);
    m_numeradores.append(ui->lblCasilla_4);
    m_numeradores.append(ui->lblCasilla_5);
    m_numeradores.append(ui->lblCasilla_6);
    m_numeradores.append(ui->lblCasilla_7);
    m_numeradores.append(ui->lblCasilla_8);
    m_numeradores.append(ui->lblCasilla_9);
    m_numeradores.append(ui->lblCasilla_10);
    m_numeradores.append(ui->lblCasilla_11);
    m_numeradores.append(ui->lblCasilla_12);
    m_numeradores.append(ui->lblCasilla_13);
    m_numeradores.append(ui->lblCasilla_14);
    m_numeradores.append(ui->lblCasilla_15);
    m_numeradores.append(ui->lblCasilla_16);
    m_numeradores.append(ui->lblCasilla_17);
    m_numeradores.append(ui->lblCasilla_18);
    m_numeradores.append(ui->lblCasilla_19);
    m_numeradores.append(ui->lblCasilla_20);
    m_numeradores.append(ui->lblCasilla_21);
    m_numeradores.append(ui->lblCasilla_22);
    m_numeradores.append(ui->lblCasilla_23);
    m_numeradores.append(ui->lblCasilla_24);
    m_numeradores.append(ui->lblCasilla_25);
    m_numeradores.append(ui->lblCasilla_26);
    m_numeradores.append(ui->lblCasilla_27);
    m_numeradores.append(ui->lblCasilla_28);
    m_numeradores.append(ui->lblCasilla_29);
    m_numeradores.append(ui->lblCasilla_30);
    m_numeradores.append(ui->lblCasilla_31);
    m_numeradores.append(ui->lblCasilla_32);
    m_numeradores.append(ui->lblCasilla_33);
    m_numeradores.append(ui->lblCasilla_34);
    m_numeradores.append(ui->lblCasilla_35);
    m_numeradores.append(ui->lblCasilla_36);
    m_numeradores.append(ui->lblCasilla_37);
    m_numeradores.append(ui->lblCasilla_38);
    m_numeradores.append(ui->lblCasilla_39);
    m_numeradores.append(ui->lblCasilla_40);
    m_numeradores.append(ui->lblCasilla_41);
    m_numeradores.append(ui->lblCasilla_42);
    m_numeradores.append(ui->lblCasilla_43);
    m_numeradores.append(ui->lblCasilla_44);
    m_numeradores.append(ui->lblCasilla_45);
    m_numeradores.append(ui->lblCasilla_46);
    m_numeradores.append(ui->lblCasilla_47);
    m_numeradores.append(ui->lblCasilla_48);
    m_numeradores.append(ui->lblCasilla_49);
    m_numeradores.append(ui->lblCasilla_50);
    m_numeradores.append(ui->lblCasilla_51);
    m_numeradores.append(ui->lblCasilla_52);
    m_numeradores.append(ui->lblCasilla_53);
    m_numeradores.append(ui->lblCasilla_54);
    m_numeradores.append(ui->lblCasilla_55);
    m_numeradores.append(ui->lblCasilla_56);
    m_numeradores.append(ui->lblCasilla_57);
    m_numeradores.append(ui->lblCasilla_58);
    m_numeradores.append(ui->lblCasilla_59);
    m_numeradores.append(ui->lblCasilla_60);
    m_numeradores.append(ui->lblCasilla_61);
    m_numeradores.append(ui->lblCasilla_62);
    m_numeradores.append(ui->lblCasilla_63);

    m_casillas.append(ui->Casilla_1);
    m_casillas.append(ui->Casilla_2);
    m_casillas.append(ui->Casilla_3);
    m_casillas.append(ui->Casilla_4);
    m_casillas.append(ui->Casilla_5);
    m_casillas.append(ui->Casilla_6);
    m_casillas.append(ui->Casilla_7);
    m_casillas.append(ui->Casilla_8);
    m_casillas.append(ui->Casilla_9);
    m_casillas.append(ui->Casilla_10);
    m_casillas.append(ui->Casilla_11);
    m_casillas.append(ui->Casilla_12);
    m_casillas.append(ui->Casilla_13);
    m_casillas.append(ui->Casilla_14);
    m_casillas.append(ui->Casilla_15);
    m_casillas.append(ui->Casilla_16);
    m_casillas.append(ui->Casilla_17);
    m_casillas.append(ui->Casilla_18);
    m_casillas.append(ui->Casilla_19);
    m_casillas.append(ui->Casilla_20);
    m_casillas.append(ui->Casilla_21);
    m_casillas.append(ui->Casilla_22);
    m_casillas.append(ui->Casilla_23);
    m_casillas.append(ui->Casilla_24);
    m_casillas.append(ui->Casilla_25);
    m_casillas.append(ui->Casilla_26);
    m_casillas.append(ui->Casilla_27);
    m_casillas.append(ui->Casilla_28);
    m_casillas.append(ui->Casilla_29);
    m_casillas.append(ui->Casilla_30);
    m_casillas.append(ui->Casilla_31);
    m_casillas.append(ui->Casilla_32);
    m_casillas.append(ui->Casilla_33);
    m_casillas.append(ui->Casilla_34);
    m_casillas.append(ui->Casilla_35);
    m_casillas.append(ui->Casilla_36);
    m_casillas.append(ui->Casilla_37);
    m_casillas.append(ui->Casilla_38);
    m_casillas.append(ui->Casilla_39);
    m_casillas.append(ui->Casilla_40);
    m_casillas.append(ui->Casilla_41);
    m_casillas.append(ui->Casilla_42);
    m_casillas.append(ui->Casilla_43);
    m_casillas.append(ui->Casilla_44);
    m_casillas.append(ui->Casilla_45);
    m_casillas.append(ui->Casilla_46);
    m_casillas.append(ui->Casilla_47);
    m_casillas.append(ui->Casilla_48);
    m_casillas.append(ui->Casilla_49);
    m_casillas.append(ui->Casilla_50);
    m_casillas.append(ui->Casilla_51);
    m_casillas.append(ui->Casilla_52);
    m_casillas.append(ui->Casilla_53);
    m_casillas.append(ui->Casilla_54);
    m_casillas.append(ui->Casilla_55);
    m_casillas.append(ui->Casilla_56);
    m_casillas.append(ui->Casilla_57);
    m_casillas.append(ui->Casilla_58);
    m_casillas.append(ui->Casilla_59);
    m_casillas.append(ui->Casilla_60);
    m_casillas.append(ui->Casilla_61);
    m_casillas.append(ui->Casilla_62);
    m_casillas.append(ui->Casilla_63);
    m_casillas.append(ui->Casilla_64);

    for (int i = 0; i < m_casillas.size(); ++i) {
        const int numeroCasilla = i + 1;

        for (int casilla : kCasillasOca) {
            if (numeroCasilla == casilla) {
                m_casillas[i]->setTipo(Casilla::Tipo::Oca);
                m_casillas[i]->setStyleSheet(
                    QStringLiteral("QFrame#frame{ border-image: url(:/Recursos/Imagenes/CasillaOca2.png); }"));
            }
        }
        for (int casilla : kCasillasPuente) {
            if (numeroCasilla == casilla) {
                m_casillas[i]->setTipo(Casilla::Tipo::Puente);
                m_casillas[i]->setStyleSheet(
                    QStringLiteral("QFrame#frame{ border-image: url(:/Recursos/Imagenes/Portal.png); }"));
            }
        }
        for (int casilla : kCasillasCalavera) {
            if (numeroCasilla == casilla) {
                m_casillas[i]->setTipo(Casilla::Tipo::Calavera);
                m_casillas[i]->setStyleSheet(
                    QStringLiteral("QFrame#frame{ border-image: url(:/Recursos/Imagenes/CasillaCalavera3.png); }"));
            }
        }
        if (numeroCasilla == kCasillaFinal) {
            m_casillas[i]->setTipo(Casilla::Tipo::Final);
        }
    }
}

void Tablero::moverFicha(int pasos)
{
    if (m_actual == nullptr) {
        return;
    }
    if (m_preguntas.isEmpty()) {
        restaurarPreguntas();
    }

    if (pasos > 0) {
        for (int i = 0; i < pasos; ++i) {
            delay(kVelocidadAnimacion);
            m_casillas[m_actual->numCasillas()]->eliminarFicha(m_actual);
            m_casillas[m_actual->numCasillas() + 1]->aniadirFicha(m_actual);
            m_actual->setNumCasillas(m_actual->numCasillas() + 1);
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundTap.wav"));
        }
    } else if (pasos < 0) {
        for (int i = 0; i > pasos; --i) {
            if (m_actual->numCasillas() <= 0) {
                break;
            }
            delay(kVelocidadAnimacion + 100);
            m_actual->setNumCasillas(m_actual->numCasillas() - 1);
            m_casillas[m_actual->numCasillas()]->aniadirFicha(m_actual);
            m_casillas[m_actual->numCasillas() + 1]->eliminarFicha(m_actual);
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundTap.wav"));
        }
    }

    m_formulario->mostrarPregunta();
    cambiarTurno();
    m_formulario->usarPregunta();
}

void Tablero::procesarTirada(int pasos)
{
    if (m_actual == nullptr || pasos == 0) {
        return;
    }
    if (m_preguntas.isEmpty()) {
        restaurarPreguntas();
    }

    if (m_actual->numCasillas() + pasos < kCasillaFinal) {
        // Mover hacia adelante
        for (int i = 0; i < pasos; ++i) {
            delay(kVelocidadAnimacion);
            m_casillas[m_actual->numCasillas()]->eliminarFicha(m_actual);
            m_casillas[m_actual->numCasillas() + 1]->aniadirFicha(m_actual);
            m_actual->setNumCasillas(m_actual->numCasillas() + 1);
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundTap.wav"));
        }

        // Evaluar tipo de casilla
        switch (m_casillas[m_actual->numCasillas()]->getTipo()) {
        case Casilla::Tipo::Normal:
            m_formulario->mostrarPregunta();
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundPregunta.wav"));
            return;

        case Casilla::Tipo::Oca:
            for (int i = 0; i < kCasillasOca.size(); ++i) {
                if (m_actual->numCasillas() == kCasillasOca[i] - 1) {
                    if (m_actual->numCasillas() == kCasillasOca.last() - 1) {
                        m_dado->bloquearDado();
                        break;
                    }
                    int siguiente = (i + 1 < kCasillasOca.size()) ? i + 1 : 0;
                    SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundOca2.wav"));
                    moverFichaA(kCasillasOca[siguiente]);
                    m_dado->bloquearDado();
                    break;
                }
            }
            return;

        case Casilla::Tipo::Calavera:
            moverFichaA(1);
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundCalavera.wav"));
            break;

        case Casilla::Tipo::Puente:
            for (int i = 0; i < kCasillasPuente.size(); ++i) {
                if (m_actual->numCasillas() == kCasillasPuente[i] - 1) {
                    int siguiente = (i + 1 < kCasillasPuente.size()) ? i + 1 : 0;
                    moverFichaA(kCasillasPuente[siguiente]);
                    SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundPortal.wav"));
                    break;
                }
            }
            break;

        case Casilla::Tipo::Final:
            SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundCorrecto.wav"));
            QMessageBox::information(this,
                tr("Fin del Juego"),
                m_actual->nombreJugador() + tr(" ha Ganado el Juego :D"));
            m_music.stop();
            return;
        }
    } else {
        SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundIncorrecto2.wav"));
    }

    cambiarTurno();
    m_formulario->usarPregunta();
}

void Tablero::moverFichaA(int casillaDestino)
{
    if (m_actual == nullptr || casillaDestino > kCasillaFinal || casillaDestino <= 0) {
        return;
    }
    delay(kVelocidadAnimacion);
    m_casillas[m_actual->numCasillas()]->eliminarFicha(m_actual);
    m_casillas[casillaDestino - 1]->aniadirFicha(m_actual);
    m_actual->setNumCasillas(casillaDestino - 1);
    SoundPlayer::play(QStringLiteral(":/Recursos/Audio/SoundTap.wav"));
}

QList<Pregunta *> Tablero::preguntas() const
{
    return m_preguntas;
}

void Tablero::setPreguntas(const QList<Pregunta *> &nuevasPreguntas)
{
    m_preguntas = nuevasPreguntas;
    m_formulario->setPreguntas(&m_preguntas);
    m_preguntasBase = nuevasPreguntas;
}


void Tablero::cambiarTurno()
{
    if (m_jugadores.isEmpty()) {
        m_actual = nullptr;
        return;
    }
    m_turno++;
    if (m_turno >= m_jugadores.size()) {
        m_turno = 0;
    }
    m_actual = m_jugadores[m_turno];
    emit actualChanged(m_actual);
    m_dado->bloquearDado();
}

void Tablero::restaurarPreguntas()
{
    m_preguntas = m_preguntasBase;
    m_formulario->setPreguntas(&m_preguntas);
}

Formulario *Tablero::formulario() const
{
    return m_formulario;
}

void Tablero::addFicha(Ficha *ficha)
{
    if (m_jugadores.size() >= 4) {
        m_jugadores.removeFirst();
    }
    m_jugadores.append(ficha);
    m_casillas[0]->aniadirFicha(m_jugadores.last());

    if (m_jugadores.size() == 1) {
        m_actual = m_jugadores[0];
        emit actualChanged(m_actual);
    }
    m_turno = 0;
    m_formulario->actualizarJugadores();
}

Dado *Tablero::dado() const
{
    return m_dado;
}

void Tablero::delay(int mSecs)
{
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < mSecs) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
