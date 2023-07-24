#include "mainwindow.h"
#include "inicio.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

void delay(int mSecs);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Juego-OCA_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Inicio b;
    b.show();
    delay(2000);
    b.close();

    MainWindow w;
    QObject::connect(w.config().idiomas(), &Idiomas::cerrarConfiguracion, [&w]() {
        w.config().cerrarVentana(); // Cierra la ventana de configuración.
    });

    QObject::connect(&w.config(),&Configuracion::idiomaCambiado,[&translator, &a, &w](QString idioma){
        const QString baseName = "Juego-OCA_" + idioma;
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);

            w.config().idiomas()->retranslateUi(); // Llama a retranslateUi en Idiomas.
            w.config().temario()->retranslateUi();
        };
    });
    w.show();
    return a.exec();
}

void delay(int mSecs)
{
    QTime dieTime= QTime::currentTime().addMSecs(mSecs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
