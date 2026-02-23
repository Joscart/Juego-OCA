#pragma once

#include <QDialog>

#include "pregunta.h"

QT_BEGIN_NAMESPACE
namespace Ui { class preguntasdialog; }
QT_END_NAMESPACE

class preguntasdialog : public QDialog
{
    Q_OBJECT

public:
    explicit preguntasdialog(QWidget *parent = nullptr);
    ~preguntasdialog() override;

    Pregunta *preguntas() const;

    QString getPregunta() const;
    void setPregunta(const QString &texto);

    QString getRespuesta() const;
    void setRespuesta(const QString &texto);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::preguntasdialog *ui;
    Pregunta *m_preguntas = nullptr;
};
