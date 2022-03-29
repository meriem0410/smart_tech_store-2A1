#ifndef STOCK_H
#define STOCK_H
#include<QSqlQuery>
#include<QSqlQueryModel>

class stock
{

public:
    //costracteur
    stock();
    stock(QString,int,QString);
    //Getters
    QString getlot();
    QString getref_p();
    int getnbr();

    //Seteers
    void setlot(QString );
    void setref_p(QString );
    void setnbr(int );

    //fonction de base
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();


private:
    QString lot,ref_p;
    int nbr;

};
#endif // STOCK_H
