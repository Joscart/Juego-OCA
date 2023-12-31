#ifndef PREGUNTASDIALOG_H
#define PREGUNTASDIALOG_H

#include <QDialog>
#include <pregunta.h>
#include <QMessageBox>
#include <QWidget>
namespace Ui {
class preguntasdialog;
}

class preguntasdialog : public QDialog
{
    Q_OBJECT

public:
    explicit preguntasdialog(QWidget *parent = nullptr);
    ~preguntasdialog();
    Pregunta *preguntas() const;

    QString pregunta;
    QString respuesta;

    QString getPregunta() const;
    void setPregunta(const QString &newPregunta);

    QString getRespuesta() const;
    void setRespuesta(const QString &newRespuesta);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::preguntasdialog *ui;
    Pregunta *m_preguntas;
};

#endif // PREGUNTASDIALOG_H
