#ifndef COMMANDE_H
#define COMMANDE_H

#include<QString>
#include<QSqlQueryModel>
class Commande
{
public:
    Commande();
    Commande(int,int,QString);
    int getNUM_FACTURE();
    int getQTE_PRODUIT();
    QString getDATE_ACHAT();
    void setNUM_FACTURE(int);
    void setQTE_PRODUIT(int);
    void setDATE_ACHAT(QString);
    bool ajouter ();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int,QString);
private:
    int NUM_FACTURE;
    int QTE_PRODUIT;
    QString DATE_ACHAT;
};

#endif // COMMANDE_H
