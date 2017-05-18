TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Analizador/Numero.cpp \
    Analizador/Conector.cpp \
    Analizador/Variable.cpp \
    MotordeInferencia/BaseDeHechos.cpp \
    MotordeInferencia/Hecho.cpp

HEADERS += \
    Analizador/Numero.h \
    Analizador/Conector.h \
    Analizador/Variable.h \
    MotordeInferencia/BaseDeHechos.h \
    MotordeInferencia/Hecho.h
