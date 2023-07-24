#include "idiomas.h"
#include "ui_idiomas.h"

Idiomas::Idiomas(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Idiomas)
{
    ui->setupUi(this);
}

Idiomas::~Idiomas()
{
    delete ui;
}

void Idiomas::on_bttnAceptar_clicked()
{
    /*
     * 0 Es Español
     * 1 Es Ingles*/
    if(ui->cbIdiomas->currentIndex() == 0){
        emit idiomaCambiado((QLocale(QLocale::Spanish)).name());
    }else if(ui->cbIdiomas->currentIndex() == 1){
        emit idiomaCambiado((QLocale(QLocale::English)).name());

    }
    close();
}

