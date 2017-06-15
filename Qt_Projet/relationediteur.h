#ifndef RELATIONEDITEUR_H
#define RELATIONEDITEUR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>

#include "Manager.h"
#include "Relations.h"

///Qwidget permettant de créer des relations, il s'affiche au milieu de l'application
class RelationEditeur : public QWidget{
    Q_OBJECT
private:
    QListWidget* listNotesGauche;
    QListWidget* listNotesDroite;
    QListWidget* listRelation;
    QVBoxLayout* layer;
    QScrollArea* scroller;
    QPushButton* ajouter;
    QLineEdit* LineCouple;
    QLabel* Lab;
    //QPushButton* addNotOriented;
    QPushButton* Bquit;
///Deux QListWidgets pour lister toutes les notes présentes dans notesManager, un bouton pour ajouter une relation, un autre bouton pour ajouter une relation non orientée ainsi qu'un bouton pour quitter l'éditeur.
public:
    RelationEditeur(QWidget* parent=0);
    QListWidget* getListGauche(){return listNotesGauche;}
    QListWidget* getListDroite(){return listNotesDroite;}
    QListWidget* getRelation(){return listRelation;}
    QPushButton* getajouterButton(){ return ajouter; }
    //QPushButton* getAddNotOrientedButton() { return addNotOriented; }
///Slots permettant de relier les boutons aux actions
public slots :
    void addCouple();
    void returnToAffichageNote();
    //void addRelationNotOriented();
    //void updateRelationManager();
    //void enablePushButons();
   void setEmptyCentralWidget();
};


#endif // RELATIONEDITEUR_H
