#pragma once

#include <QDialog>
#include <QTableWidget>

#include "pregunta.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Temario; }
QT_END_NAMESPACE

class Temario : public QDialog
{
    Q_OBJECT

public:
    explicit Temario(QWidget *parent = nullptr);
    ~Temario() override;

    QList<Pregunta *> randomizarPreguntas();
    void cargarPreguntas();
    void retranslateUi();

private slots:
    void on_btnagregar_clicked();
    void on_btnguardar_clicked();
    void on_btneditar_clicked();
    void on_btneliminar_clicked();
    void on_btnexportar_clicked();
    void on_btnimportar_clicked();

private:
    enum Columna {
        Pregunta_Col,
        Respuesta_Col
    };

    Ui::Temario *ui;
    QString m_archivoRuta;
    QList<Pregunta *> m_listaPreguntas;

    void mostrarPreguntas(const QString &rutaArchivo);
};
