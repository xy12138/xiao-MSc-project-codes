# Qt project file - qmake uses his to generate a Makefile

QT       += core gui

CONFIG          += qt warn_on debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = zx_go

LIBS += -lqwt -lm

HEADERS += window.h adcreader.h \
    zx.h \
    qcustomplot.h

SOURCES += main.cpp window.cpp adcreader.cpp \
    zx.cpp \
    qcustomplot.cpp

QWT_ROOT += /usr/local/qwt-6.1.3

include ( $${QWT_ROOT}/features/qwt.prf )

FORMS += \
    zx.ui

DISTFILES += \
    zx_go.pro.user.6b9327c
