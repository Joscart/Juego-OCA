#include "temario.h"
#include "ui_temario.h"
#include "preguntasdialog.h"

#include <QApplication>
#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QStandardPaths>
#include <QTextStream>

Temario::Temario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temario)
    , m_archivoRuta(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)
                    + QStringLiteral("/temario.bin"))
{
    ui->setupUi(this);
    setWindowTitle(tr("TEMARIO"));

    ui->tbl_temario->setColumnCount(2);
    ui->tbl_temario->setHorizontalHeaderLabels({ tr("Pregunta"), tr("Respuesta") });
    ui->tbl_temario->setColumnWidth(Pregunta_Col, 641);
    ui->tbl_temario->setColumnWidth(Respuesta_Col, 90);

    // Crear el directorio de datos si no existe
    const QString ruta = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir().mkpath(ruta);

    cargarPreguntas();
}

Temario::~Temario()
{
    delete ui;
}

void Temario::on_btnagregar_clicked()
{
    preguntasdialog dialog(this);
    dialog.setWindowTitle(tr("Agregar Pregunta"));

    if (dialog.exec() == QDialog::Rejected) {
        return;
    }

    Pregunta *p = dialog.preguntas();
    const int fila = ui->tbl_temario->rowCount();
    ui->tbl_temario->insertRow(fila);
    ui->tbl_temario->setItem(fila, Pregunta_Col, new QTableWidgetItem(p->pregunta()));
    ui->tbl_temario->setItem(fila, Respuesta_Col, new QTableWidgetItem(p->respuesta()));
    m_listaPreguntas.append(
        new Pregunta(QString::number(m_listaPreguntas.size() + 1),
                     p->pregunta(), p->respuesta()));
}

void Temario::on_btnguardar_clicked()
{
    const int filas = ui->tbl_temario->rowCount();
    if (filas == 0) {
        QMessageBox::warning(this, tr("Guardar temario"),
                             tr("El temario no tiene suficientes preguntas"));
        return;
    }

    QFile archivo(m_archivoRuta);
    if (!archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QMessageBox::critical(this, tr("Guardar temario"),
                              tr("No se puede abrir para escritura ") + m_archivoRuta);
        return;
    }

    QDataStream salida(&archivo);
    salida.setVersion(QDataStream::Qt_6_0);

    for (int i = 0; i < filas; ++i) {
        const auto *pregunta = ui->tbl_temario->item(i, Pregunta_Col);
        const auto *respuesta = ui->tbl_temario->item(i, Respuesta_Col);

        if (!pregunta || !respuesta) {
            continue;
        }
        salida << pregunta->text() << respuesta->text();
    }
    archivo.close();

    if (salida.status() != QDataStream::Ok) {
        QMessageBox::critical(this, tr("Guardar temario"),
                              tr("Error al escribir en ") + m_archivoRuta);
    } else {
        QMessageBox::information(this, tr("Guardar temario"), tr("Temario guardado"));
    }
}

void Temario::cargarPreguntas()
{
    QFile archivo(m_archivoRuta);
    if (!archivo.exists()) {
        archivo.setFileName(QStringLiteral(":/Recursos/Preguntas/temario.bin"));
    }

    m_listaPreguntas.clear();
    ui->tbl_temario->clearContents();
    ui->tbl_temario->setRowCount(0);

    if (!archivo.open(QFile::ReadOnly)) {
        return;
    }

    QDataStream entrada(&archivo);
    while (!entrada.atEnd()) {
        QString textoPregunta;
        QString textoRespuesta;
        entrada >> textoPregunta >> textoRespuesta;

        const int fila = ui->tbl_temario->rowCount();
        ui->tbl_temario->insertRow(fila);
        ui->tbl_temario->setItem(fila, Pregunta_Col, new QTableWidgetItem(textoPregunta));
        ui->tbl_temario->setItem(fila, Respuesta_Col, new QTableWidgetItem(textoRespuesta));
        m_listaPreguntas.append(
            new Pregunta(QString::number(m_listaPreguntas.size() + 1),
                         textoPregunta, textoRespuesta));
    }
    archivo.close();
}

void Temario::mostrarPreguntas(const QString &rutaArchivo)
{
    QFile archivo(rutaArchivo);
    if (!archivo.exists()) {
        QMessageBox::critical(this, tr("Cargar temario"), tr("El temario no existe"));
        return;
    }

    m_listaPreguntas.clear();
    ui->tbl_temario->clearContents();
    ui->tbl_temario->setRowCount(0);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Cargar temario"), tr("No se pudo abrir el temario"));
        return;
    }

    QTextStream stream(&archivo);
    int fila = 0;
    while (!stream.atEnd()) {
        const QString linea = stream.readLine();
        const QStringList datos = linea.split(QChar(';'));
        if (datos.size() == 2) {
            ui->tbl_temario->insertRow(fila);
            ui->tbl_temario->setItem(fila, Pregunta_Col, new QTableWidgetItem(datos[Pregunta_Col]));
            ui->tbl_temario->setItem(fila, Respuesta_Col, new QTableWidgetItem(datos[Respuesta_Col]));
            m_listaPreguntas.append(
                new Pregunta(QString::number(m_listaPreguntas.size() + 1),
                             datos[Pregunta_Col], datos[Respuesta_Col]));
            fila++;
        }
    }
    archivo.close();
}

QList<Pregunta *> Temario::randomizarPreguntas()
{
    QList<Pregunta *> temp = m_listaPreguntas;
    QList<Pregunta *> resultado;

    while (!temp.isEmpty()) {
        const int indice = QRandomGenerator::global()->bounded(temp.size());
        resultado.append(temp[indice]);
        temp.removeAt(indice);
    }
    return resultado;
}

void Temario::on_btneditar_clicked()
{
    const int fila = ui->tbl_temario->currentRow();
    if (fila < 0) {
        return;
    }

    auto *preguntaItem = ui->tbl_temario->item(fila, Pregunta_Col);
    auto *respuestaItem = ui->tbl_temario->item(fila, Respuesta_Col);
    if (!preguntaItem || !respuestaItem) {
        return;
    }

    preguntasdialog dialog(this);
    dialog.setWindowTitle(tr("Editar Pregunta"));
    dialog.setPregunta(preguntaItem->text());
    dialog.setRespuesta(respuestaItem->text());

    if (dialog.exec() == QDialog::Rejected) {
        return;
    }

    preguntaItem->setText(dialog.getPregunta());
    respuestaItem->setText(dialog.getRespuesta());
    QMessageBox::information(this, tr("Editor de preguntas"), tr("Pregunta actualizada"));
}

void Temario::on_btneliminar_clicked()
{
    const int fila = ui->tbl_temario->currentRow();
    if (fila < 0) {
        return;
    }

    ui->tbl_temario->setCurrentCell(fila, Pregunta_Col);
    const QString textoPregunta = ui->tbl_temario->currentItem()->text();

    for (int i = m_listaPreguntas.size() - 1; i >= 0; --i) {
        if (m_listaPreguntas[i]->pregunta() == textoPregunta) {
            m_listaPreguntas.removeAt(i);
        }
    }
    ui->tbl_temario->removeRow(fila);
}

void Temario::on_btnexportar_clicked()
{
    const int filas = ui->tbl_temario->rowCount();
    if (filas == 0) {
        QMessageBox::warning(this, tr("Guardar temario"), tr("No hay datos para guardar"));
        return;
    }

    const QString filePath = QFileDialog::getSaveFileName(
        this, tr("Guardar temario"),
        QDir::homePath() + QStringLiteral("/temario.csv"),
        tr("Archivos csv") + QStringLiteral(" (*.csv)"));

    if (filePath.isEmpty()) {
        QMessageBox::information(this, tr("Guardar temario"),
                                 tr("Operaci\u00f3n de exportar cancelada"));
        return;
    }

    QFile archivo(filePath);
    if (!archivo.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Guardar temario"),
                              tr("No se puede escribir en el archivo csv"));
        return;
    }

    QTextStream salida(&archivo);
    for (int i = 0; i < filas; ++i) {
        const auto *pregunta = ui->tbl_temario->item(i, Pregunta_Col);
        const auto *respuesta = ui->tbl_temario->item(i, Respuesta_Col);
        salida << pregunta->text() << ";" << respuesta->text() << "\n";
    }
    archivo.close();
    QMessageBox::information(this, tr("Guardar temario"),
                             tr("Preguntas guardadas exitosamente en el archivo csv"));
    cargarPreguntas();
}

void Temario::on_btnimportar_clicked()
{
    const QString rutaArchivo = QFileDialog::getOpenFileName(
        this, tr("Seleccionar temario"), QString(),
        tr("Archivos de texto") + QStringLiteral(" (*.csv)"));

    if (!rutaArchivo.isEmpty()) {
        mostrarPreguntas(rutaArchivo);
        QMessageBox::information(this, tr("Cargar archivo"),
                                 tr("Temario cargado exitosamente."));
    }
}

void Temario::retranslateUi()
{
    ui->tbl_temario->setHorizontalHeaderLabels({
        QApplication::translate("Temario", "Pregunta", nullptr),
        QApplication::translate("Temario", "Respuesta", nullptr)
    });
    ui->btnexportar->setText(QApplication::translate("Temario", "Exportar", nullptr));
    ui->btnimportar->setText(QApplication::translate("Temario", "Importar", nullptr));
    ui->btnagregar->setText(QApplication::translate("Temario", "Agregar", nullptr));
    ui->btneditar->setText(QApplication::translate("Temario", "Editar", nullptr));
    ui->btneliminar->setText(QApplication::translate("Temario", "Eliminar", nullptr));
    ui->btnguardar->setText(QApplication::translate("Temario", "Guardar", nullptr));
}

