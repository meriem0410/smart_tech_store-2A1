#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,int,QString/*,QString,int*/);
    int getidF();
    QString getNom();
    int getnum_tel();
    QString getE_mail();
    //QString getcontrat();
    //int getnote();

    void setidF(int);
    void setNom(QString);
    void setnum_tel(int);
    void setE_mail(QString);
    //void setcontrat(QString);
    //void setnote(int);
    bool ajouter();
    QSqlQueryModel* afficher ();
    bool supprimer(int);
    bool modifier(int,QString,int,QString);
    bool chercher(int );
private:
    int idF,num_tel;//,note;
    QString Nom,E_mail;//,contrat;
};

#endif // FOURNISSEUR_H
