#include "Notes.h"
#include "Manager.h"

using namespace TIME;

/**< CONSTRUCTEUR DE RECOPIE DE LA CLASS NOTE */

Note::Note(Note& n){
    ID = n.ID;
    titre = n.titre;
    dateCrea = n.dateCrea;
    dateModif = QDateTime::currentDateTime();
    etat = n.etat;
    actuelle = true;
    n.setAncienne();
}

/**< METHODES D'AFFICHAGE DES DIFFERENTES NOTES */

//QVBoxLayout afficherSpecifique() const = 0;

/*
void Article::afficherSpecifique(std::ostream& f) const {
    f<<"\nTexte : "<<texte;
}

void Tache::afficherSpecifique(std::ostream& f) const {
    f<<"\nAction : "<<action;
    f<<"\nStatut : ";
    switch(statut){
        case 0: f<<"Attente"; break;
        case 1: f<<"En cours"; break;
        case 2: f<<"Terminee"; break;}
    if (priorite!=0){
    f<<"\nPriorite : "<<priorite;
    }
    if (echeance.getAnnee()!=0 || echeance.getMois()!=1 || echeance.getJour()!=1  ){
    f<<"\nEcheance : "<<echeance;
    }
}

void Multimedia::afficherSpecifique(std::ostream& f) const {
    f<<"\nAdresseFichier : "<<adresseFichier;
    f<<"\nDescription : "<<description;
    f<<"\nType : ";
    switch(type){
        case 0: f<<"image"; break;
        case 1: f<<"video"; break;
        case 2: f<<"audio"; break;}
}
*/

/**< DEMANDES D'EDITION DES DIFFERENTS NOTES */
/**< MODIFIER LES CIN/COUT LORS DE LA MISE EN PLACE DE QT */

/*
void Manager::editNote(Note& n){
    Note& n2=n.edit();
    ajouterNote(n2);
}

Article& Article::edit(){
    QString newTitle;
    QString newText;
    std::cout<<"\nAncien titre : "<<this->getTitre()<<"\tNouveau titre : ";
    std::cin>>newTitle;
    std::cout<<"\nAncien texte : "<<this->getTexte()<<"\tNouveau texte : ";
    std::cin>>newText;
    Article* a=new Article(*this);
    a->setTitre(newTitle);
    a->setTexte(newText);
    return *a;
}
*/

/*

Tache& Tache::edit(){
    QString newTitle;
    std::string newAction;
    int newPriorite;
    TIME::Date newEcheance;
    std::cout<<"\nAncien titre : "<<this->getTitre()<<"\tNouveau titre : ";
    std::cin>>newTitle;
    std::cout<<"\nAncienne action : "<<this->getAction()<<"\tNouvelle action : ";
    std::cin>>newAction;
    std::cout<<"\nAncienne priorite : "<<this->getPriorite()<<"\tNouvelle priorite : ";
    std::cin>>newPriorite;
    std::cout<<"\nAncienne date d'echeance : "<<this->getEcheance()<<"\tNouvelle date d'echeance : ";
    std::cin>>newEcheance;
    Tache* t=new Tache(*this);
    t->setTitre(newTitle);
    t->setAction(newAction);
    t->setPriorite(newPriorite);
    t->setEcheance(newEcheance);
    return *t;
}

Multimedia& Multimedia::edit(){
    QString newTitle;
    std::string newAdresseFichier;
    std::string newTypeString;
    TypeMultimedia newType;
    std::string newDescription;
    std::cout<<"\nAncien titre : "<<this->getTitre()<<"\tNouveau titre : ";
    std::cin>>newTitle;
    std::cout<<"\nAncienne adresse fichier : "<<this->getAdresseFichier()<<"\tNouvelle adresse fichier : ";
    std::cin>>newAdresseFichier;
    do{
        std::cout<<"\nAncienne type : "<<this->getType()<<"\tNouveau type (choisir entre image/video/audio) : ";
        std::cin>>newTypeString;
    }while(newTypeString!="image" && newTypeString!="video" && newTypeString!="audio");
    if(newTypeString=="image") newType=image;
    if(newTypeString=="video") newType=video;
    if(newTypeString=="audio") newType=audio;
    std::cout<<"\nAncienne description : "<<this->getDescription()<<"\tNouvelle description : ";
    std::cin>>newDescription;
    Multimedia* m=new Multimedia(*this);
    m->setTitre(newTitle);
    m->setAdresseFichier(newAdresseFichier);
    m->setType(newType);
    m->setDescription(newDescription);
    return *m;
*/

//changer la boucle for

void Article::saveNote(QXmlStreamWriter& stream)const{
    stream.writeStartElement("article");
    stream.writeTextElement("id",QString::number(getID()));
    stream.writeTextElement("datecrea",getDateCrea().toString(formatDateTime));
    //stream.writeTextElement("horairecrea",getHoraireCrea().HorairetoQString());
    stream.writeTextElement("datemodif",getDateModif().toString(formatDateTime));
    //stream.writeTextElement("horairemodif",getHoraireModif().HorairetoQString());
    stream.writeTextElement("etat",NoteEtattoQString());
    stream.writeTextElement("actuel",ActueltoQString());
    stream.writeTextElement("titre",getTitre());
    stream.writeTextElement("texte",getTexte());
    stream.writeEndElement();
}

void Tache::saveNote(QXmlStreamWriter& stream)const{
    stream.writeStartElement("tache");
    stream.writeTextElement("id",QString::number(getID()));
    stream.writeTextElement("datecrea",getDateCrea().toString(formatDateTime));
    //stream.writeTextElement("horairecrea",getHoraireCrea().HorairetoQString());
    stream.writeTextElement("datemodif",getDateModif().toString(formatDateTime));
    //stream.writeTextElement("horairemodif",getHoraireModif().HorairetoQString());
    stream.writeTextElement("etat",NoteEtattoQString());
    stream.writeTextElement("actuel",ActueltoQString());
    stream.writeTextElement("titre",getTitre());
    stream.writeTextElement("action",getAction());
    stream.writeTextElement("priorite",QString::number(getPriorite()));
    stream.writeTextElement("echeance",getEcheance().toString(formatDate));
    stream.writeTextElement("statut",TacheStatuttoQString());
    stream.writeEndElement();
}

void Multimedia::saveNote(QXmlStreamWriter& stream)const{
    stream.writeStartElement("tache");
    stream.writeTextElement("id",QString::number(getID()));
    stream.writeTextElement("datecrea",getDateCrea().toString(formatDateTime));
    //stream.writeTextElement("horairecrea",getHoraireCrea().HorairetoQString());
    stream.writeTextElement("datemodif",getDateModif().toString(formatDateTime));
    //stream.writeTextElement("horairemodif",getHoraireModif().HorairetoQString());
    stream.writeTextElement("etat",NoteEtattoQString());
    stream.writeTextElement("actuel",ActueltoQString());
    stream.writeTextElement("titre",getTitre());
    stream.writeTextElement("adressefichier",getAdresseFichier());
    stream.writeTextElement("type",TypeMultimediatoQString());
    stream.writeTextElement("description",getDescription());
    stream.writeEndElement();
}


QString Note::NoteEtattoQString()const{
    QString str="";
    if (etat==active){str="active";}
    if (etat==archivee){str="archivee";}
    if (etat==corbeille){str="corbeille";}
    return str;
}


QString Tache::TacheStatuttoQString()const{
    QString str="";
    if (statut==attente){str="attente";}
    if (statut==encours){str="encours";}
    if (statut==terminee){str="terminee";}
    return str;
}


QString Multimedia::TypeMultimediatoQString() const{
        QString str="";
        if (type==image){str="image";}
        if (type==video){str="video";}
        if (type==audio){str="audio";}
        return str;
}

QString Note::ActueltoQString()const{
    QString str="";
    if (actuelle==true){str="Actuelle";}
    else{str="Ancienne";}
    return str;
}

NoteEtat Note::QStringtoNoteEtat(const QString& str){
    if (str=="active") return active;
    else if (str=="archivee") return archivee;
    else return corbeille;
}

TacheStatut Tache::QStringtoTacheStatut(const QString & str){
    if (str=="attente") return attente;
    else if (str=="terminee") return terminee;
    else return encours;

 }

TypeMultimedia Multimedia::QStringtoTypeMultimedia(const QString & str){
    if (str=="video") return video;
    if (str=="audio") return audio;
    else return image;
  }

bool Note::QStringtoActuel(const QString & str){
    if (str=="true") return true;
    else return false;
}

// Ajout de toutes les references contenues dans les champs de texte d'une notes avec Template Method

void Note::AddRefs(Manager& m){
    long ID=findRefID(this->getTitre(), 0);
    int pos=0;
    while (ID!=-1){
        Note* N=m.searchID(ID);
        if (N!=nullptr) {
            Couple* C=new Couple(this,N,"");
            m.addCoupleReference(*C);
        }
        else throw NoteException("l'ID ne correspond a aucune Note");
        pos+=getPosition(this->getTitre(), pos);
    }
    AddRefsSpecifique(m);
}

//AddrefsSpeacifique(Manager& m) Specifique a chaque sous class de Note

void Tache::AddRefsSpecifique(Manager& m){
    long ID=findRefID(this->getAction(), 0);
    int pos=0;
    while (ID!=-1){
        Note* N=m.searchID(ID);
        if (N!=nullptr) {
            Couple* C=new Couple(this,N,"");
            m.addCoupleReference(*C);
        }
        else throw NoteException("l'ID ne correspond a aucune Note");
        pos+=getPosition(this->getAction(), pos);
        ID=findRefID(this->getAction(), pos);
    }
}

void Article::AddRefsSpecifique(Manager& m){
    long ID=findRefID(this->getTexte(), 0);
    int pos=0;
    while (ID!=-1){
        Note* N=m.searchID(ID);
        if (N!=nullptr) {
            Couple* C=new Couple(this,N,"");
            m.addCoupleReference(*C);
        }
        else throw NoteException("l'ID ne correspond a aucune Note");
        pos+=getPosition(this->getTexte(), pos);
        ID=findRefID(this->getTexte(), pos);
    }
}

void Multimedia::AddRefsSpecifique(Manager& m){
    long ID=findRefID(this->getDescription(), 0);
    int pos=0;
    while (ID!=-1){
        Note* N=m.searchID(ID);
        if (N!=nullptr) {
            Couple* C=new Couple(this,N,"");
            m.addCoupleReference(*C);
        }
        else throw NoteException("l'ID ne correspond a aucune Note");
        pos+=getPosition(this->getDescription(), pos);
        ID=findRefID(this->getDescription(), pos);
    }
}

// Fonction qui trouve dans tout string en partant de la position p si il y a une reference, dans ce cas, renvoie son ID, sinon, renvoie 0

long findRefID(const QString& s, int p){
    int l=s.length();
    QStringRef r=QStringRef(&s,p,l-p);
    int i=s.indexOf("\ref{")+4;
    int j=i;
    if (i!=-1){
        QChar c;
        c=r.at(i);
        if (!c.isDigit()) return -1;
        int idlength=0;
        while (c!='}' && i<l-p) {
            idlength++;
            if (!c.isDigit()) return -1;
            i++;
            c=r.at(i);
        }
        if(i==l-p) return -1;
        else{
            QString f=r.toString();
            QStringRef x=QStringRef(&f,j,idlength);
            int id=x.toInt();
            return id;
        }
    }
    return -1;
}


/*
unsigned long findRefID(const std::string& s, int p){

    unsigned long i=s.find("ref{", p);

    if(i==p) return 0;
    else {
        i+=4;
        char c=s[i];
        if (!isdigit(c)) {return 0;}
        else{
            std::stringstream t;
            while (isdigit(c)){
                t<<c;
                i++;
                c=s[i];
            }
            unsigned long id;
            t>>id;
            if (c=='}') return id;
            else return 0;
        }
    }
}*/

//Fonction qui renvoie la position du "}" fermant la reference à partir de la position p passé en argument si une reference existe dans le string s, sinon renvoie 0

int getPosition(const QString& s, int p){
    int l=s.length();
    QStringRef r=QStringRef(&s,p,l-p);
    int i=s.indexOf("\ref{")+4;
    int j=i;
    if (i!=-1){
        QChar c=r.at(i);
        if (!c.isDigit()) return -1;
        int idlength=0;
        while (c!='}' && i<l-p){
            idlength++;
            if (!c.isDigit()) return -1;
            i++;
            c=r.at(i);
        }
        if(i==l-p) return -1;
        else return p+j+idlength+3;
    }
    return -1;
}

/*
int getPosition(const std::string s, int p){
    int i=s.find("ref{", p);
    if (i==p) return 0;
    else {
        i+=4;
        char c=s[i];
        if (!isdigit(c)) {return 0;}
        else{
            while (isdigit(c)){
                i++;
                c=s[i];
            }
            if (c=='}') return i;
            else return 0;
        }
    }

}
*/