QT += core gui widgets multimedia

RC_ICONS = mi_icono.ico

TARGET = Oca-Acuarela
TEMPLATE = app

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    acercade.cpp \
    casilla.cpp \
    configuracion.cpp \
    dado.cpp \
    ficha.cpp \
    formulario.cpp \
    idiomas.cpp \
    inicio.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    pregunta.cpp \
    preguntasdialog.cpp \
    selectplayer.cpp \
    tablero.cpp \
    temario.cpp

HEADERS += \
    acercade.h \
    casilla.h \
    configuracion.h \
    dado.h \
    ficha.h \
    formulario.h \
    idiomas.h \
    inicio.h \
    jugador.h \
    mainwindow.h \
    pregunta.h \
    preguntasdialog.h \
    selectplayer.h \
    soundplayer.h \
    tablero.h \
    temario.h

FORMS += \
    acercade.ui \
    casilla.ui \
    configuracion.ui \
    dado.ui \
    formulario.ui \
    idiomas.ui \
    inicio.ui \
    mainwindow.ui \
    preguntasdialog.ui \
    selectplayer.ui \
    tablero.ui \
    temario.ui

TRANSLATIONS += \
    Juego-OCA_es.ts \
    Juego-OCA_en.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Recursos.qrc

