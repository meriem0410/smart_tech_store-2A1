#ifndef PRODUIT_H
#define PRODUIT_H
#include<QSqlQuery>
#include<QSqlQueryModel>

class produit
{

public:
    //costracteur
    produit();
    produit(QString,QString,int,QString,QString);
    //Getters
    QString getref();
    QString getlib();
    int getprix();
    QString getseuil();
    QString getdescr();
    //Seteers
    void setref(QString );
    void setlib(QString );
    void setprix(int );
    void setrseuil(QString );
    void setdescr(QString );
    //fonction de base
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* combo();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel* trier(QString,QString);
    QSqlQueryModel* recherche(QString);

private:
    QString ref,lib,seuil,descr;
    int prix;

};

#endif // PRODUIT_H
