#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tablero)
{
    ui->setupUi(this);
    m_dado = new Dado(this);
    m_formulario = new Formulario(this);
    cargarWidgets();

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
}

Formulario *Tablero::formulario() const
{
    return m_formulario;
}

Dado *Tablero::dado() const
{
    return m_dado;
}
