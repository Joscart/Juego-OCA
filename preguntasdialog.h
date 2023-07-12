#ifndef PREGUNTASDIALOG_H
#define PREGUNTASDIALOG_H

#include <QDialog>
#include <preguntas.h>

namespace Ui {
class preguntasdialog;
}

class preguntasdialog : public QDialog
{
    Q_OBJECT

public:
    explicit preguntasdialog(QWidget *parent = nullptr);
    ~preguntasdialog();
    Preguntas *preguntas() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::preguntasdialog *ui;
    Preguntas *m_preguntas;
};

#endif // PREGUNTASDIALOG_H
