#include "mainwindow.h"
#include "inicio.h"

#include <QApplication>
#include <QElapsedTimer>
#include <QLocale>
#include <QTranslator>

static void delay(int mSecs)
{
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < mSecs) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Juego-OCA_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    Inicio splashScreen;
    splashScreen.show();
    delay(2000);
    splashScreen.close();

    MainWindow mainWindow;

    QObject::connect(mainWindow.config().idiomas(), &Idiomas::cerrarConfiguracion, [&mainWindow]() {
        mainWindow.config().cerrarVentana();
    });

    QObject::connect(&mainWindow.config(), &Configuracion::idiomaCambiado,
                     [&translator, &app, &mainWindow](const QString &idioma) {
        const QString baseName = "Juego-OCA_" + idioma;
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            mainWindow.config().idiomas()->retranslateUi();
            mainWindow.config().temario()->retranslateUi();
        }
    });

    mainWindow.show();
    return app.exec();
}
