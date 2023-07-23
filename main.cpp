#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

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

    MainWindow w;
    QObject::connect(&w.config(),&Configuracion::idiomaCambiado,[&translator, &a](QString idioma){
        const QString baseName = "Juego-OCA_" + idioma;
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
        };
    });
    w.show();
    return a.exec();
}
