#include "configuracion.h"
#include "ui_configuracion.h"

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
    m_temario = new Temario;
    m_idiomas = new Idiomas;
    ui->stkConfig->setCurrentIndex(0);
    ui->stkConfig->removeWidget(ui->stkConfig->currentWidget());
    ui->stkConfig->setCurrentIndex(0);
    ui->stkConfig->removeWidget(ui->stkConfig->currentWidget());
    ui->stkConfig->addWidget(m_temario);
    ui->stkConfig->addWidget(m_idiomas);
    connect(m_idiomas,&Idiomas::idiomaCambiado,this,[this](QString idioma){
        emit idiomaCambiado(idioma);
        ui->retranslateUi(this);
    });
}

Configuracion::~Configuracion()
{
    delete ui;
}

Temario *Configuracion::temario()
{
    return m_temario;
}

void Configuracion::on_btnOpcion_1_clicked()
{
    ui->stkConfig->setCurrentIndex(0);
}


void Configuracion::on_btnOpcion_2_clicked()
{
    ui->stkConfig->setCurrentIndex(1);
}

