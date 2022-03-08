#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


Commande::Commande()
{
    NUM_FACTURE=0; QTE_PRODUIT=0; DATE_ACHAT="";
}
    Commande::Commande(int NUM_FACTURE,int QTE_PRODUIT,QString DATE_ACHAT)
    {this ->NUM_FACTURE=NUM_FACTURE; this ->QTE_PRODUIT=QTE_PRODUIT; this ->DATE_ACHAT=DATE_ACHAT;}
    int Commande::getNUM_FACTURE(){return NUM_FACTURE;}
    int Commande::getQTE_PRODUIT(){return QTE_PRODUIT;}
    QString Commande::getDATE_ACHAT(){return DATE_ACHAT;}
    void Commande::setNUM_FACTURE(int NUM_FACTURE){this ->NUM_FACTURE=NUM_FACTURE;}
    void Commande::setQTE_PRODUIT(int QTE_PRODUIT){this ->QTE_PRODUIT=QTE_PRODUIT;}
    void Commande::setDATE_ACHAT(QString DATE_ACHAT){this ->DATE_ACHAT=DATE_ACHAT;}
    bool Commande::ajouter()
    {

        QString num_string= QString ::number(NUM_FACTURE) ;
        QString qte_string= QString ::number(QTE_PRODUIT) ;
        QSqlQuery query;
        query.prepare("INSERT INTO COMMANDE (NUM_FACTURE, DATE_ACHAT, QTE_PRODUIT) "
                            "VALUES (:NUM_FACTURE, :QTE_PRODUIT, :DATE_ACHAT)");
              query.bindValue(0, num_string);
              query.bindValue(1, DATE_ACHAT);
              query.bindValue(2, qte_string);

             return query.exec();


    }
    bool Commande::supprimer(int NUM_FACTURE)
    {
              QSqlQuery query;
              query.prepare("delete from COMMANDE where NUM_FACTURE=:NUM_FACTURE");
              query.bindValue(0, NUM_FACTURE);


              return query.exec();
    }
    QSqlQueryModel* Commande::afficher()
    {
      QSqlQueryModel *model=new QSqlQueryModel();

           model->setQuery("SELECT* FROM COMMANDE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("N°Facture"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Achat"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("Qte produit"));
      return model ;
    }
    bool Commande::modifier(int NUM_FACTURE,int QTE_PRODUIT,QString DATE_ACHAT)
        {
        QSqlQuery query;
        QString num_string= QString::number(NUM_FACTURE);
        QString qte_string= QString::number(QTE_PRODUIT) ;
        query.prepare("UPDATE COMMANDE set NUM_FACTURE=:NUM_FACTURE,QTE_PRODUIT=:QTE_PRODUIT,DATE_ACHAT=:DATE_ACHAT WHERE NUM_FACTURE=:NUM_FACTURE");
        query.bindValue(":NUM_FACTURE", num_string);
        query.bindValue(":QTE_PRODUIT", qte_string);
        query.bindValue(":DATE_ACHAT", DATE_ACHAT);

        return    query.exec();
        }



