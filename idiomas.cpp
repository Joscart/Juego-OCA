#include "idiomas.h"
#include "ui_idiomas.h"

#include <QApplication>
#include <QLocale>

Idiomas::Idiomas(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Idiomas)
{
    ui->setupUi(this);
}

Idiomas::~Idiomas()
{
    delete ui;
}

void Idiomas::retranslateUi()
{
    ui->cbIdiomas->setItemText(0, QApplication::translate("Idiomas", "Espa\u00f1ol", nullptr));
    ui->cbIdiomas->setItemText(1, QApplication::translate("Idiomas", "Ingles", nullptr));
    ui->bttnAceptar->setText(QApplication::translate("Idiomas", "Aceptar", nullptr));
    ui->label->setText(QApplication::translate("Idiomas", "Idiomas", nullptr));
}

void Idiomas::on_bttnAceptar_clicked()
{
    if (ui->cbIdiomas->currentIndex() == 0) {
        emit idiomaCambiado(QLocale(QLocale::Spanish).name());
    } else if (ui->cbIdiomas->currentIndex() == 1) {
        emit idiomaCambiado(QLocale(QLocale::English).name());
    }
    emit cerrarConfiguracion();
}
