#pragma once

#include "ficha.h"

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Casilla; }
QT_END_NAMESPACE

class Casilla : public QWidget
{
    Q_OBJECT

public:
    enum class Tipo {
        Normal,
        Calavera,
        Oca,
        Puente,
        Final
    };

    explicit Casilla(QWidget *parent = nullptr);
    ~Casilla() override;

    void aniadirFicha(Ficha *ficha);
    void eliminarFicha(Ficha *ficha);

    Tipo getTipo() const;
    void setTipo(Tipo nuevoTipo);

private:
    Ui::Casilla *ui;
    QVector<Ficha *> m_fichas;
    QList<QLabel *> m_lugarFichas;
    Tipo m_tipo = Tipo::Normal;

    void actualizarVistaFichas();
};
