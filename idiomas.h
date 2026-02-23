#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Idiomas; }
QT_END_NAMESPACE

class Idiomas : public QDialog
{
    Q_OBJECT

public:
    explicit Idiomas(QWidget *parent = nullptr);
    ~Idiomas() override;

    void retranslateUi();

signals:
    void idiomaCambiado(const QString &idioma);
    void cerrarConfiguracion();

private slots:
    void on_bttnAceptar_clicked();

private:
    Ui::Idiomas *ui;
};
