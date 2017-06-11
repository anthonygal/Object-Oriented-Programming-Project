#ifndef MANAGER_H
#define MANAGER_H

#include "Notes.h"
#include "Relations.h"

/**< CLASS MANAGER QUI GERE TOUT */
class Manager{
private:
    static Manager* InstanceUnique; /**< L'unique Manager : Singleton */
    static unsigned long nextNoteID; /**< La prochaine note qui sera crée se verra attribuer cet ID */
    unsigned int nbNotes; /**< Tableau de Notes */
    unsigned int nbNotesMax;
    Note** notes;
    unsigned int nbRelations; /**< Tableau de Relations */
    unsigned int nbRelationsMax;
    Relation** relations;
    Manager(): nbNotes(0), nbNotesMax(5), notes(new Note*[nbNotesMax]), nbRelations(0), nbRelationsMax(5), relations(new Relation*[100]){} /**< Constructeur de Manager */
    Manager(const Manager&); /**< Constructeur de recopie de Manager */
    void operator=(const Manager&); /**< Surcharge de l'operateur = pour affecter un Manager */
    ~Manager(); /**< Destructeur Manager */
    mutable QString filename;
public:
    /**< Template Method Singleton */
    static Manager& donneInstance();
    static void libereInstance();
    /**< Iterateur de notes actives */
    class IteratorNotes{
    private:
        friend class Manager;
        Note** currentN;
        int remain;
        IteratorNotes(Note** t, int n):currentN(t),remain(n){}
    public:
        bool isDone() const {return !remain;}
        void next();
        Note& current() const;
    };
    IteratorNotes getIteratorNotes() const{return IteratorNotes(notes, nbNotes);}
    /**< Iterateur de notes actives */
    class IteratorNotesActive{
    private:
        friend class Manager;
        Note** currentN;
        int remain;
        IteratorNotesActive(Note** t, int n);
    public:
        bool isDone() const {return !remain;}
        void next();
        Note& current() const;
    };
    IteratorNotesActive getIteratorNotesActive() const{return IteratorNotesActive(notes, nbNotes);}
    /**< Iterateur de notes archivees */
    class IteratorNotesArchivee{
    private:
        friend class Manager;
        Note** currentN;
        int remain;
        IteratorNotesArchivee(Note** t, int n);
    public:
        bool isDone() const {return !remain;}
        void next();
        Note& current() const;
    };
    IteratorNotesArchivee getIteratorNotesArchivee() const{return IteratorNotesArchivee(notes, nbNotes);}
    /**< Iterateur de notes dans l'etat corbeille */
    class IteratorNotesCorbeille{
    private:
        friend class Manager;
        Note** currentN;
        int remain;
        IteratorNotesCorbeille(Note** t, int n);
    public:
       bool isDone() const {return !remain;}
       void next();
       Note& current() const;
    };
    IteratorNotesCorbeille getIteratorNotesCorbeille() const{return IteratorNotesCorbeille(notes, nbNotes);}
    /**< Iterateur pour relations */
    class IteratorRelations{
    private:
        friend class Manager;
        Relation** currentR;
        int remain;
        IteratorRelations(Relation** t, int n): currentR(t), remain(n){}
    public:
        bool isDone() const { return !remain; }
        void next();
        Relation& current() const;
    };
    IteratorRelations getIteratorRelations() const {return IteratorRelations(relations, nbRelations);}
    /**< Iterateur constant pour relations  */
    class ConstIteratorRelations{
    private:
        friend class Manager;
        Relation** currentR;
        int remain;
        ConstIteratorRelations(Relation** t, int n): currentR(t), remain(n){}
    public:
        bool isDone() const { return !remain; }
        void next();
        const Relation& current() const;
    };
    ConstIteratorRelations getConstIteratorRelations() const {return ConstIteratorRelations(relations, nbRelations);}
    /**< Je sais pas quoi ecrire */
    int getNbNotes()const {return nbNotes;}
    int getNbRelations() const {return nbRelations;}
    Reference& getReference();
    Note* searchID(unsigned long id);
    /**< Methode pour afficher les notes */
    //void afficherNote() const;
    void afficherTout() const;
    /**< Methode pour ajouter une Note, utilisee dans les methodes de creation et d'edition d'article/tache/multimedia */
    void ajouterNote(Note& n);
    /**< Methodes pour ajouter un Article/Tache/Multimedia au tableau de notes*/
    void newArticle(const QString& ti, const QString& te=""); /**< creation d'un article */
    void newTache(const QString& ti, const QString& act, int prio=0, const QDate& d=QDate()); /**< creation d'une tache */
    void newMultimedia(const QString& ti, const QString& adr, const QString& desc="", TypeMultimedia ty=image); /**< creation d'un multimedia */
    /**< Methode pour editer une note */
    void editNote(Note& n);
    /**< Methodes d'edition inutiles pour l'instant mais je prefere garder au cas ou */
    Article& editTexteArticle(Article& A, const QString& s);
    Tache& editActionTache(Tache& T, const QString& s);
    Tache& editStatutTache(Tache& T, TacheStatut s);
    Tache& editPrioriteTache(Tache& T, int p);
    Tache& editEcheanceTache(Tache& T, const QDate& d);
    Multimedia& editFichierMultimedia(Multimedia& M, const QString s);
    /**< Methodes d'ajout de Relation/Reference */
   void addRelation(Relation& r);
  void addCoupleRelation(Relation& r, Couple& c);
  void addCoupleReference(Couple& c);
    void AddRefsFromNote(Note& N);
    //Methode permettant de savoir si une note est referencee
    bool isReferenced(const Note& N) const;
    //Supression ou Archivage de Note
    void supprimer(Note& N);
    void viderCorbeille();

    void save()const;
    void load();
    //void loadArticle();
    //void loadTache();
    //void loadMultimedia();
    void addArticle(const int id, const QString& ti, const QDateTime& dc, const QDateTime& dm, bool act, NoteEtat e,const QString& te);
    void addTache(const int id, const QString& ti, const QDateTime& dc, const QDateTime& dm, bool act, NoteEtat e,const QString& acti, const int prio, const QDate& eche, const TacheStatut ts);
    void addMultimedia(const int id, const QString& ti, const QDateTime& dc, const QDateTime& dm, bool act, NoteEtat e,const QString& af, const TypeMultimedia ty,const QString& dec);

    void setFilename(const QString& f) { filename=f; }
};

#endif // MANAGER_H
