#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>


produit::produit(){
    ref="0"; lib=""; prix=0; seuil=""; descr="";
}
produit::produit(QString ref,QString lib,int prix,QString seuil,QString descr)
{
    this->ref=ref;
    this->lib=lib;
    this->prix=prix;
    this->seuil=seuil;
    this->descr=descr;
}

QString produit::getref(){return ref;}
QString produit::getlib(){return lib;}
int produit::getprix(){return prix;}
QString produit::getseuil(){return seuil;}
QString produit::getdescr(){return descr;}
//Seteers
void produit::setref(QString ref){this->ref=ref;}
void produit::setlib(QString lib){this->lib=lib;}
void produit::setprix(int prix){this->prix=prix;}
void produit::setrseuil(QString seuil){this->seuil=seuil;}
void produit::setdescr(QString descr){this->descr=descr;}



bool produit::ajouter()
{

QSqlQuery query;
QString prix_string= QString::number(prix);
     query.prepare("INSERT INTO PRODUIT (REF, LIB, PRIX, SEUIL,DESCR) "
                   "VALUES (:ref, :lib, :prix, :seuil, :descr)");
     query.bindValue(":ref", ref);
     query.bindValue(":lib", lib);
     query.bindValue(":prix", prix);
     query.bindValue(":seuil", seuil);
     query.bindValue(":descr", descr);
    return query.exec();


}

bool produit::supprimer(QString ref){
    QSqlQuery query;
         query.prepare("Delete from produit where ref=:ref");
         query.bindValue(0, ref);

        return query.exec();

}

bool produit::modifier()
{
    QSqlQuery query;
      query.prepare("update produit set lib=:lib,prix=:prix,seuil=:seuil,descr=:descr where ref=:ref");
      query.bindValue(":lib",lib);
      query.bindValue(":prix",prix);
      query.bindValue(":seuil",seuil);
      query.bindValue(":descr",descr);
      query.bindValue(":ref",ref);

      return query.exec();
  }


