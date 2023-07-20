QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    casilla.cpp \
    dado.cpp \
    ficha.cpp \
    formulario.cpp \
    idiomas.cpp \
    main.cpp \
    mainwindow.cpp \
    pregunta.cpp \
    tablero.cpp

HEADERS += \
    casilla.h \
    dado.h \
    ficha.h \
    formulario.h \
    idiomas.h \
    mainwindow.h \
    pregunta.h \
    tablero.h

FORMS += \
    casilla.ui \
    dado.ui \
    formulario.ui \
    idiomas.ui \
    mainwindow.ui \
    tablero.ui

TRANSLATIONS += \
    Juego-OCA_es_419.ts\
    Juego-OCA_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc
