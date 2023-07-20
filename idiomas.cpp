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
        QLocale::setDefault(QLocale(QLocale::Spanish, QLocale::Spain));
    }else if(ui->cbIdiomas->currentIndex() == 1){
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

    }
}

