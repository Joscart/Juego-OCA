#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tablero)
{
    ui->setupUi(this);
    m_dado = new Dado(this);

    connect(m_dado,SIGNAL(windowTitleChanged(QString)),this,SLOT(moverFicha(QString)));

    m_formulario = new Formulario(this);
    m_formulario->setJugadores(&m_jugadores);

    connect(this, &Tablero::actualChanged, m_formulario, &Formulario::setFichaActual);

    cargarWidgets();

    connect(m_formulario, &Formulario::respuesta, this, [this](bool aux) {
        QString respuesta = aux ? "verdadero" : "falso";
        if (m_formulario->actual()->respuesta() != respuesta) {
            m_formulario->incorrecto();
            moverFicha(-1 * m_dado->resultado());
        }else{
            m_formulario->correcto();
            cambiarTurno();
        }
        m_formulario->usarPregunta();
    });


    //Sombras de letras
    int xOffset = 2;
    int yOffset = 1;

    //Numerar los label
    for(int i=0;i<m_numeradores.size();i++){
        m_numeradores[i]->setText(QString::number(i+1));
        auto effect = new QGraphicsDropShadowEffect(m_numeradores[i]);
        effect->setColor(Qt::white);
        effect->setOffset(xOffset,yOffset);
        m_numeradores[i]->setGraphicsEffect(effect);
    }

    //aplicar sombra a Label extras
    auto effect_2 = new QGraphicsDropShadowEffect(ui->lblInicio);
    effect_2->setColor(Qt::white);
    effect_2->setOffset(xOffset,yOffset);
    ui->lblInicio->setGraphicsEffect(effect_2);
    auto effect_3 = new QGraphicsDropShadowEffect(ui->lblMeta);
    effect_3->setColor(Qt::white);
    effect_3->setOffset(xOffset,yOffset);
    ui->lblMeta->setGraphicsEffect(effect_3);
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

    for(int i=0;i<m_casillas.size();i++){
        foreach(int casilla,m_casillasOca){
            if(i+1==casilla){
                m_casillas[i]->setTipo(Casilla::Tipo::Oca);
                m_casillas[i]->setStyleSheet("QFrame#frame{"
                                             "border-image: url(:/Recursos/Imagenes/CasillaOca2.png);"
                                             "}");
            }
        }
        foreach(int casilla,m_casillasPuente){
            if(i+1==casilla){
                m_casillas[i]->setTipo(Casilla::Tipo::Puente);
                m_casillas[i]->setStyleSheet("QFrame#frame{"
                                             "border-image: url(:/Recursos/Imagenes/Portal.png);"
                                             "}");
            }
        }
        foreach(int casilla,m_casillasCalabera){
            if(i+1==casilla){
                m_casillas[i]->setTipo(Casilla::Tipo::Calavera);
                m_casillas[i]->setStyleSheet("QFrame#frame{"
                                             "border-image: url(:/Recursos/Imagenes/CasillaCalavera3.png);"
                                             "}");
            }
        }
        if(i+1==m_casillaFinal){
            m_casillas[i]->setTipo(Casilla::Tipo::Final);
        }
    }
}

void Tablero::moverFicha(int pasos)
{
    if(actual==nullptr)
        return;
    if(m_preguntas.isEmpty())
        restaurarPreguntas();

    for(int i=0;i<pasos;i++){
        delay(m_speed);
        m_casillas[actual->numCasillas()]->eliminarFicha(actual);
        m_casillas[actual->numCasillas()+1]->aniadirFicha(actual);
        actual->setNumCasillas(actual->numCasillas() + 1);
        QSound::play(":/Recursos/Audio/SoundTap.wav");
    }
    if(pasos<0){
        for(int i=0;i>pasos;i--){
            if(actual->numCasillas()<=0)
                break;
            delay(m_speed+100);
            actual->setNumCasillas(actual->numCasillas() - 1);
            m_casillas[actual->numCasillas()]->aniadirFicha(actual);
            m_casillas[actual->numCasillas()+1]->eliminarFicha(actual);
            QSound::play(":/Recursos/Audio/SoundTap.wav");
        }
    }
    m_formulario->mostrarPregunta();
    cambiarTurno();
    m_formulario->usarPregunta();
}

void Tablero::moverFicha(QString pasosText)
{
    if(actual==nullptr)
        return;
    if(pasosText.isEmpty())
        return;
    if(m_preguntas.isEmpty())
        restaurarPreguntas();

    int pasos = pasosText.toInt();

    if(actual->numCasillas()+pasos<m_casillaFinal)
    {
        for(int i=0;i<pasos;i++){
            delay(m_speed);
            m_casillas[actual->numCasillas()]->eliminarFicha(actual);
            m_casillas[actual->numCasillas()+1]->aniadirFicha(actual);
            actual->setNumCasillas(actual->numCasillas() + 1);
            QSound::play(":/Recursos/Audio/SoundTap.wav");
        }
        if(pasos<0){
            for(int i=0;i>pasos;i--){
                if(actual->numCasillas()<=0)
                    break;
                delay(m_speed+100);
                actual->setNumCasillas(actual->numCasillas() - 1);
                m_casillas[actual->numCasillas()]->aniadirFicha(actual);
                m_casillas[actual->numCasillas()+1]->eliminarFicha(actual);
                QSound::play(":/Recursos/Audio/SoundTap.wav");
            }
        }
        if (actual->numCasillas() == m_casillaFinal) {
            // La ficha ha llegado a la casilla final

        }



        switch (m_casillas[actual->numCasillas()]->getTipo()) {
        case Casilla::Tipo::Normal:
            m_formulario->mostrarPregunta();
            return;
        case Casilla::Tipo::Oca:
            for(int i=0;i<m_casillasOca.size();i++){
                if(actual->numCasillas()==m_casillasOca[i]-1){
                    if(i==m_casillasOca.size()-1)
                        i = -1;
                    moverFichaA(m_casillasOca[i+1]);
                    m_dado->bloquearDado();
                    break;
                }
            }
            return;
        case Casilla::Tipo::Calavera:
            moverFichaA(1);
            break;
        case Casilla::Tipo::Puente:
            for(int i=0;i<m_casillasPuente.size();i++){
                if(actual->numCasillas()==m_casillasPuente[i]-1){
                    if(i==m_casillasPuente.size()-1)
                        i = -1;
                    moverFichaA(m_casillasPuente[i+1]);
                    break;
                }
            }
            break;
        case Casilla::Tipo::Final:
            QMessageBox::information(this,"Fin del Juego",actual->NombreJugador()+" ha Ganado el Juego :D");
            return;
        }
    }

    cambiarTurno();
    m_formulario->usarPregunta();
}

void Tablero::moverFichaA(int casillaDestino)
{
    if(actual==nullptr or casillaDestino>m_casillaFinal or casillaDestino<=0)
        return;
    delay(m_speed);
    m_casillas[actual->numCasillas()]->eliminarFicha(actual);
    m_casillas[casillaDestino-1]->aniadirFicha(actual);
    actual->setNumCasillas(casillaDestino-1);
    QSound::play(":/Recursos/Audio/SoundTap.wav");
}

QList<Pregunta *> Tablero::preguntas()
{
    return m_preguntas;
}

void Tablero::setPreguntas(QList<Pregunta *> newPreguntas)
{
    m_preguntas = newPreguntas;
    m_formulario->setPreguntas(&m_preguntas);
    m_preguntasBase = newPreguntas;
}


void Tablero::cambiarTurno()
{
    if(m_jugadores.size()<0){
        actual=nullptr;
        return;
    }
    m_turno++;
    if(m_turno>=m_jugadores.size())
        m_turno=0;
    actual = m_jugadores[m_turno];
    emit actualChanged(actual);
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

void Tablero::addFicha(Ficha *newFicha)
{
    if(m_jugadores.size()>=4)
        m_jugadores.removeFirst();
    m_jugadores.append(newFicha);
    m_casillas[0]->aniadirFicha(m_jugadores.last());
    if(m_jugadores.size()==1){
        actual = m_jugadores[0];
        emit actualChanged(actual);
    }
    m_turno=0;
    m_formulario->actualizarJugadores();
}

Dado *Tablero::dado() const
{
    return m_dado;
}

void Tablero::delay(int mSecs)
{
    QTime dieTime= QTime::currentTime().addMSecs(mSecs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
