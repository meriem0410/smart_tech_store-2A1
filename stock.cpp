#include "stock.h"
#include <QSqlQuery>
#include <QtDebug>


stock::stock(){
    lot="0"; ref_p="0"; nbr=0;
}
stock::stock(QString lot,int nbr,QString ref_p)
{
    this->lot=lot;
    this->ref_p = ref_p;
    this->nbr=nbr;

}

QString stock::getlot(){return lot;}
QString stock::getref_p(){return ref_p;}
int stock::getnbr(){return nbr;}

//Seteers
void stock::setlot(QString lot){this->lot=lot;}
void stock::setref_p(QString ref_p){this->ref_p=ref_p;}
void stock::setnbr(int nbr){this->nbr=nbr;}




bool stock::ajouter()
{

QSqlQuery query;
QString nbr_string= QString::number(nbr);
     query.prepare("INSERT INTO stock (lot, ref_p, nbr) "
                   "VALUES (:lot, :ref_p, :nbr)");
     query.bindValue(":lot", lot);
     query.bindValue(":ref_p", ref_p);
     query.bindValue(":nbr", nbr);

    return query.exec();


}

bool stock::supprimer(QString lot){
    QSqlQuery query;
         query.prepare("Delete from stock where lot=:lot");
         query.bindValue(0, lot);

        return query.exec();

}

bool stock::modifier()
{
    QSqlQuery query;
      query.prepare("update stock set ref_p=:ref_p,nbr=:nbr where lot=:lot");
      query.bindValue(":ref_p",ref_p);
      query.bindValue(":nbr",nbr);

      query.bindValue(":lot",lot);

      return query.exec();
  }


