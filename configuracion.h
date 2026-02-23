#pragma once

#include <QDialog>

#include "idiomas.h"
#include "temario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Configuracion; }
QT_END_NAMESPACE

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion() override;

    Temario *temario();
    Idiomas *idiomas();

    void cerrarVentana();

signals:
    void idiomaCambiado(const QString &idioma);

private slots:
    void on_btnOpcion_1_clicked();
    void on_btnOpcion_2_clicked();

private:
    Ui::Configuracion *ui;
    Temario *m_temario = nullptr;
    Idiomas *m_idiomas = nullptr;
};
