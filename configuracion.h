#ifndef CONFIGURACION_H
#define CONFIGURACION_H

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

private slots:

    void on_btnOpcion_1_clicked();

    void on_btnOpcion_2_clicked();

private:
    Ui::Configuracion *ui;
    Temario *m_temario;
};

#endif // CONFIGURACION_H
