######################################################################
# Automatically generated by qmake (2.01a) Sun Jan 9 22:43:43 2011
######################################################################

TEMPLATE = app
TARGET = 
QT += svg
DEPENDPATH += . base modes_jeu qt_gui
INCLUDEPATH += . qt_gui base

# Input
HEADERS += base/carte.h \
           base/joueur.h \
           base/liste.h \
           base/paquet.h \
           base/poker.h \
           base/utils.h \
           modes_jeu/cinq_cartes.h \
           qt_gui/card.h \
           qt_gui/lcdrange.h \
           qt_gui/widget.h
FORMS += qt_gui/widget.ui
SOURCES += main.cpp \
           base/carte.c \
           base/joueur.c \
           base/liste.c \
           base/paquet.c \
           base/poker.c \
           modes_jeu/cinq_cartes.c \
           qt_gui/card.cpp \
           qt_gui/lcdrange.cpp \
           qt_gui/widget.cpp