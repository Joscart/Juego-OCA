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

void Idiomas::retranslateUi() {
    // Traducir y establecer el texto del primer ítem
    ui->cbIdiomas->setItemText(0, QApplication::translate("Idiomas", "Español", nullptr));
    // Traducir y establecer el texto del segundo ítem
    ui->cbIdiomas->setItemText(1, QApplication::translate("Idiomas", "Ingles", nullptr));
    ui->bttnAceptar->setText(QApplication::translate("Idiomas", "Aceptar", nullptr));
    ui->label->setText(QApplication::translate("Idiomas", "Idiomas", nullptr));

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
    emit cerrarConfiguracion();
}

