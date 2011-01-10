
#include <QtGui/QApplication>
#include "qt_gui/widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.show();
//    w.showFullScreen();
//    jouer_cinq_cartes(0);
    return  a.exec();
}
