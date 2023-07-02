#include "tablero.h"
#include "ui_tablero.h"

#include "casilla.h"
#include "qlabel.h"


Tablero::Tablero(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Juego de la Oca");
    resize(780, 720);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout1 = new QVBoxLayout();

    // Creamos una cuadrícula para organizar los elementos del juego
    gridLayout = new QGridLayout();
    // Creamos las casillas del tablero
    this->labels= this->getLabels(); // Lista de etiquetas para las casillas
    //dibuja tablero con casillas de this->labels
    for (int i = 0; i < labels.length(); ++i) {
        int valor=labels.at(i).getValor();
        QLabel *label;
        if (valor==64) {
            label= new QLabel("OCA");
            label->setStyleSheet("border: 1px solid black; color:white; background-color:red;");
        } else {
            label= new QLabel(QString::number(valor));
            label->setStyleSheet("border: 1px solid black;");
        }
        label->setAlignment(Qt::AlignCenter);
        label->setFixedSize(60, 60); // Establecemos el ancho y alto definido
        // Establecemos el estilo de borde
        gridLayout->addWidget(label, labels.at(i).getX(), labels.at(i).getY());
    }
    //añade jugadores al tablero
    QPushButton* botonDice= new QPushButton("OCA");
    connect(botonDice, SIGNAL(clicked()), this, SLOT(handleButton()));
    piece1= new QPushButton("J1");
    piece2= new QPushButton("J2");
    piece1->setFixedSize(15,15);
    piece2->setFixedSize(15,15);
    gridLayout->addWidget(piece1, 7, 0,Qt::AlignTop | Qt::AlignLeft);
    gridLayout->addWidget(piece2, 7, 4,Qt::AlignTop | Qt::AlignRight);
    gridLayout->addWidget(botonDice, 8, 8);
    //añade layout a la pantalla
    layout1->addLayout(gridLayout);
    centralWidget->setLayout(layout1);
    //centralWidget->set
    centralWidget->show();
}

Tablero::~Tablero()
{
    delete ui;
}

QList<Casilla> Tablero::getLabels()
{
    QList<Casilla> labels;

    int inicioFila = 7;
    int finFila = 0;
    int inicioCol = 0;
    int finCol = 7;
    int cont=1;
    do {
        // Agregar elementos de la fila inferior
        for (int colT = inicioCol; colT <= finCol; ++colT) {
            labels.append(*new Casilla(cont++,inicioFila,colT));
        }
        //inicioCol++;
        inicioFila--;
        for (int filT = inicioFila; filT >= finFila; --filT) {
            labels.append(*new Casilla(cont++,filT,finCol));
        }
        finCol--;
        for (int colT = finCol; colT >= inicioCol; --colT) {
            labels.append(*new Casilla(cont++,finFila,colT));
        }
        finFila++;
        for (int filT = finFila; filT <= inicioFila; ++filT) {
            labels.append(*new Casilla(cont++,filT,inicioCol));
        }
        inicioCol++;
    }while (cont<=63);
    return labels;
}

void Tablero::handleButton() {
    // Aquí es donde manejas el evento del botón.
    // Por ejemplo, podrías imprimir un mensaje en la consola:
    Dice *dice=new Dice;
    connect(dice, SIGNAL(closingWithData(int)), this, SLOT(handleSecondWindowData(int)));
    dice->show();

}
void Tablero::handleSecondWindowData(int data) {  // Reemplaza "int" con el tipo de datos que estás transmitiendo, y "data" con el nombre de tus datos
    QString cadena = QString::number(data);
    //QMessageBox::critical(this, "¡Algo salió mal!", (cadena));
    //TODO:
    /*
    1)Sacar la posicion actual del jugador/
    /1->(7,0)  buscar en el arreglo de casillas this->labels recuperamos el valor
    2) sumar valor+ data(valor del dado)ejemplo 1+5=6
    6 busco en el areglo this->labels por el valor y saco x ,y
    3) x, y van en el metodo de addWidget
    */
    //funcion que me saca la posicion donde esta el jugador
    int index = gridLayout->indexOf(piece1);
    int row, column, rowSpan, columnSpan;
    if (index != -1) {

        gridLayout->getItemPosition(index, &row, &column, &rowSpan, &columnSpan);

        //QMessageBox::critical(this, "¡Algo salió mal!", "El widget está en la fila" + QString::number(row) + ", columna"+ QString::number(column));
        //qDebug() << "El widget ocupa" << rowSpan << "filas y" << columnSpan << "columnas";
    } else {
        //qDebug() << "El widget no está en el layout";
    }

    ///////////
    auto casillaEncontrada = std::find_if(this->labels.begin(), this->labels.end(), [&row,&column](const Casilla& obj) {
        return obj.getX() == row && obj.getY()==column;  // Reemplaza getMiAtributo con el método que obtiene el atributo en el que estás interesado
    });
    //QMessageBox::critical(this, "¡Algo salió mal!",QString::number(casillaEncontrada->getValor()));

     int valorBuscar=casillaEncontrada->getValor()+data;

     auto casillaEncontradaFinal = std::find_if(this->labels.begin(), this->labels.end(), [&valorBuscar](const Casilla& obj) {
         return obj.getValor() == valorBuscar;  // Reemplaza getMiAtributo con el método que obtiene el atributo en el que estás interesado
     });

    gridLayout->addWidget(piece1, casillaEncontradaFinal->getX(), casillaEncontradaFinal->getY(),Qt::AlignTop | Qt::AlignLeft);



    ////// validar tipo de casilla, sacar pregunta en el caso que sea, mover puente
    /// validar si llego al final se acabe el juego y muestra resultados

}

