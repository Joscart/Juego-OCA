#include "preguntasdialog.h"
#include "ui_preguntasdialog.h"

#include <QMessageBox>

preguntasdialog::preguntasdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::preguntasdialog)
{
    ui->setupUi(this);
}

preguntasdialog::~preguntasdialog()
{
    delete ui;
}

void preguntasdialog::on_buttonBox_accepted()
{
    const QString textoPregunta = ui->lnlpregunta->text();
    if (textoPregunta.isEmpty()) {
        QMessageBox::warning(this, tr("Ingresar pregunta"), tr("Campo de pregunta vac\u00edo"));
        return;
    }

    QString textoRespuesta;
    if (ui->verdaderoButton->isChecked()) {
        textoRespuesta = QStringLiteral("verdadero");
    } else if (ui->falsobutton->isChecked()) {
        textoRespuesta = QStringLiteral("falso");
    }

    m_preguntas = new Pregunta(QString(), textoPregunta, textoRespuesta);
    accept();
}

void preguntasdialog::on_buttonBox_rejected()
{
    reject();
}

Pregunta *preguntasdialog::preguntas() const
{
    return m_preguntas;
}

QString preguntasdialog::getPregunta() const
{
    return ui->lnlpregunta->text();
}

void preguntasdialog::setPregunta(const QString &texto)
{
    ui->lnlpregunta->setText(texto);
}

QString preguntasdialog::getRespuesta() const
{
    if (ui->verdaderoButton->isChecked()) {
        return QStringLiteral("verdadero");
    }
    if (ui->falsobutton->isChecked()) {
        return QStringLiteral("falso");
    }
    return QString();
}

void preguntasdialog::setRespuesta(const QString &texto)
{
    if (texto == QStringLiteral("verdadero")) {
        ui->verdaderoButton->setChecked(true);
    } else if (texto == QStringLiteral("falso")) {
        ui->falsobutton->setChecked(true);
    }
}
