#define OLDPOS 1
#define POS_Y 180
#define SPACE 10

#include "widget.h"
#include "card.h"
#include "ui_widget.h"
#include "lcdrange.h"

#include <QDebug>
#include <QList>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimeLine>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>

#include <cstdlib> 
#include <ctime> 
#include "../base/poker.h"
#include "../modes_jeu/cinq_cartes.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//menu
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    ui->menu->addWidget(quit, 0, 0);
//scene tapis
    scene = new QGraphicsScene(0,0,700,450);
     connect(scene, SIGNAL(selectionChanged()), this, SLOT(selection()));
    ui->graphicsView->setScene( scene );
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
//menu jeu playgame
    QPushButton *Cancel = new QPushButton(tr("Cancel"));
    Cancel->setFont(QFont("Times", 18, QFont::Bold));
    connect(Cancel, SIGNAL(clicked()), this, SLOT(recup_cards()));
    ui->playgame->addWidget(Cancel, 0, 0);

    LCDRange *mise = new LCDRange;
    ui->playgame->addWidget(mise, 0, 1);

    QPushButton *OK = new QPushButton(tr("OK"));
    OK->setFont(QFont("Times", 18, QFont::Bold));
    connect(OK, SIGNAL(clicked()), this, SLOT(change_cards()));
    ui->playgame->addWidget(OK, 0, 2);

// compte du joueur
    initJoueur(&joueur);

//lancement
    createHelp();
 
    initPaquet(&jeu);
    this->createCards();
    creerJeu(&jeu);  /* cree un jeu de 52 carte (complet) */
    melangerPaquet(&jeu);
    restartGame();

}


Widget::~Widget()
{
    delete ui;
    testamentPaquet(&jeu);
    testamentJoueur(&joueur);
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::createCards( void ) {
   int i;

   Card *tmp;

//pique
   for( i = 1; i < 10; i++ ) {
      QString filename = QString("./img/00%1.svg").arg(i);
      tmp = new Card( filename );
      tmp->setPos(-500,500);
      m_cards.insert(i,tmp);

      scene->addItem(tmp);
      tmp->setData( OLDPOS , i );
   }
   for( i = 10; i < 14; i++ ) {
      QString filename = QString("./img/0%1.svg").arg(i);
      tmp = new Card( filename );
      tmp->setPos(-500,500);
      m_cards.insert(i,tmp);

      scene->addItem(tmp);
      tmp->setData( OLDPOS , i );
   }
//treffle
   for( i = 101; i < 114; i++ ) {
      QString filename = QString("./img/%1.svg").arg(i);
      tmp = new Card( filename );
      tmp->setPos(-500,500);
      m_cards.insert(i,tmp);

      scene->addItem(tmp);
      tmp->setData( OLDPOS , i );
   }
//carreau
   for( i = 201; i < 214; i++ ) {
      QString filename = QString("./img/%1.svg").arg(i);
      tmp = new Card( filename );
      tmp->setPos(-500,500);
      m_cards.insert(i,tmp);

      scene->addItem(tmp);
      tmp->setData( OLDPOS , i );
   }
//coeur
   for( i = 301; i < 314; i++ ) {
      QString filename = QString("./img/%1.svg").arg(i);
      tmp = new Card( filename );
      tmp->setPos(-500,500);

      scene->addItem(tmp);
      m_cards.insert(i,tmp);
      tmp->setData( OLDPOS , i );
   }

}

void Widget::resizeEvent ( QResizeEvent * /*event*/ ) {
   qDebug() << "resize";
   ui->graphicsView->fitInView( this->scene->sceneRect(), Qt::KeepAspectRatio);
}

void Widget::keyPressEvent ( QKeyEvent * event ) {
   int col = event->key() - 48;
   if( col >= 1 && col <= MAX_CARDS)
   {if(!chg.contains(conventionCarte(&joueur.main, col)))
	 { chg.push_back(conventionCarte(&joueur.main, col));
	   }
   }
   else if(event->key() == Qt::Key_R )
      restartGame();
}


// slots
void Widget::change_cards(void) 
{
	int c=0;
	unsigned int i;

run++;
qDebug() << "run" << run;
if( run >= MAX_RUN ) { endOfGame();}

/*! \todo automatiszer lees autres modes de jeux*/
else {
  while (!chg.isEmpty()) 
	 { c=chg.takeLast();
	   for (i=0;i < nbElementsPaquet(&joueur.main);i++)
	    if (c == conventionCarte(&joueur.main, i+1))
	    {
	      popMain(&joueur , i+1, &jeu);
	      pushMain(&joueur , &jeu);
	      switch_cards(c,-1);
	    }
	   }
  recup_cards();
}
}

void Widget::selection() {
	int i,r=0;

for (i=0 ; i < scene->selectedItems().size() ; i++)
    { r=scene->selectedItems().at(0)->data(1).toInt();
      if(!chg.contains(r))
	 { chg.push_back(r);
	   }

      qDebug() << "selection" << scene->selectedItems().size() << r ;;
      }
qDebug() << chg.size();;
}

void Widget::moveByX( int x) {
   card->setPos( x, card->y() );;
}

void Widget::moveByY( int y ) {
   card->setPos( card->x(), y);
}

Card * Widget::findCardOnPos( int key ) {
   Card *returncard = NULL;

   returncard=m_cards.value(key);
//returncard->data( OLDPOS ).toInt() = key;
   if( !returncard )
      qDebug () << "FATAL: Pas de carte - nr:" << key ;
   return returncard;
}

void Widget::endOfGame( void ) 
{
  clean_cards();
  calcul_qualite_main(&joueur);
  qDebug () << "Qualite main :" << joueur.qualite ;
  while( nbElementsPaquet(&joueur.main) > 0 )
  {
    popMain(&joueur,0, &jeu);
  }
//  echangeCellule ( &joueur.main,0, &jeu );
//  pushPaquet(&jeu, popPaquet(&joueur.main));
  qDebug () << "endOfGame - nbelements:" << nbElementsPaquet(&joueur.main) ;
/*  while (!chg.isEmpty()) 
	 { chg.removeLast();}*/
  restartGame();
}

void Widget::restartGame( void ) {
   run = 0;
   donner( &jeu, &joueur, MAX_CARDS);
   recup_cards();
}

void Widget::createHelp( void ) 
{
   QGraphicsTextItem *helpText = scene->addText("Choisir les cartes a changer");
   helpText->moveBy( 150, 50 );
}

/*! \fn Widget::switch_cards( int out, int pos )
 *  \param [in] out carte a enlever
 *  \param [in] pos position ou mettre la nouvelle
 *  \brief -1 pour desactiver un des deux 
 */
void Widget::switch_cards( int out, int pos ) //position dans la main
{
	Card *tmp=NULL;
	int x;

//enleve la carte (pas si -1)
if (out!=-1)
   {tmp = findCardOnPos( out );
    tmp->moveAnimated( -500, 500 );}
/*
qDebug()<<"switch : carte enlevee :" << conventionCarte(&joueur.main, pos+1);
*/
if (pos!=-1)
   {
//met la nouvelle (pas si -1)
    tmp = findCardOnPos( conventionCarte(&joueur.main, pos+1) );
    x= pos * (tmp->boundingRect().width() + SPACE);
    tmp->moveAnimated( x, POS_Y );
    tmp->setFlags( QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable );
    }
/*
qDebug()<<"switch : carte ajoutee :" << pos;
*/
 }

void Widget::recup_cards(void)
{
for(unsigned int i=0;i<nbElementsPaquet(&joueur.main);i++)
	{switch_cards(-1,i);}
while (!chg.isEmpty()) 
	 { chg.removeLast();}
 }
 
void Widget::clean_cards(void)
{
   foreach( Card *tmpCard, m_cards ) {
      tmpCard->setPos(-500,500);
//      tmpCard->scale( SCALE, SCALE );
   }
 }
