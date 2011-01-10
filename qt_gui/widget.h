#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>
#include <QUrl>
#include <QTimeLine>
#include <QStack>
#include "../base/poker.h"

class QGraphicsSvgItem;
class QGraphicsRectItem;

class QGraphicsScene;
class QTimeLine;

class Card;

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    Paquet jeu;
    Joueur joueur;

 public slots:
    void moveByX( int );
    void moveByY( int );
    void recup_cards(void); /* montre le jeu (le recupere de la pile en C) */
    void change_cards(void);
    void selection();
    void switch_cards(int out, int pos);/* pos = index pr la nouvelle carte */

protected:
    void changeEvent(QEvent *e);
    void resizeEvent ( QResizeEvent * event );
    void keyPressEvent ( QKeyEvent * event );
    void clean_cards(void);

private:
    Ui::Widget *ui;

    QMap<int,Card*> m_cards;
    Card *card;
    QList<int> chg ;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectItem;

    int run;

    void createHelp( void );
    void createCards( void );
    void endOfGame( void );
    void restartGame( void );
    Card * findCardOnPos( int pos );

};

#endif // WIDGET_H
