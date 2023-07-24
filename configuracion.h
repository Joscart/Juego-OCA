#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include "idiomas.h"
#include <QDialog>
#include <temario.h>

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion();
    Temario *temario();
signals:
    void idiomaCambiado(QString idioma);
public slots:
    void cerrarVentana() { this->close(); }
private slots:

    void on_btnOpcion_1_clicked();

    void on_btnOpcion_2_clicked();

private:
    Ui::Configuracion *ui;
    Temario *m_temario;
    Idiomas *m_idiomas;
public:
    Idiomas *idiomas() { return m_idiomas; }
};

#endif // CONFIGURACION_H
