#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "affichage.h"
#include "modes_jeu/cinq_cartes.h"


int main(int argc, char ** argv)
{
  
 
#ifdef QT_GUI

#include <QtGui/QApplication>
#include "widget.h"
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    w.showFullScreen();
    return a.exec();

#else
 jouer_cinq_cartes(0);
 
 return 0;
#endif
 
}