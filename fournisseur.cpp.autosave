#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Fournisseur::Fournisseur()
{
idF=0; Nom=" "; num_tel=0; E_mail=" "; /*contrat=""; note=0;*/
}
Fournisseur :: Fournisseur(int idF,QString Nom, int num_tel ,QString E_mail/*,QString contrat, int note*/)
{this->idF=idF ;this->Nom=Nom;this->num_tel=num_tel;this->E_mail=E_mail;/*this->contrat=contrat;this->note=note;*/}
int Fournisseur :: getidF(){return idF;}
QString Fournisseur :: getNom(){return Nom;}
int Fournisseur :: getnum_tel(){return num_tel;}
QString Fournisseur :: getE_mail(){return E_mail;}
/*QString Fournisseur :: getcontrat(){return contrat;}
int Fournisseur :: getnote(){return note;}*/

void Fournisseur ::setidF(int idF){this->idF=idF;}
void Fournisseur ::setNom(QString Nom){this->Nom=Nom;}
void Fournisseur ::setnum_tel(int num_tel){this->num_tel=num_tel;}
void Fournisseur ::setE_mail(QString E_mail){this->E_mail=E_mail;}
/*void Fournisseur ::setcontrat(QString contrat){this->contrat=contrat;}
void Fournisseur ::setnote(int note){this->note=note;}*/


bool Fournisseur::ajouter()
{
    QString res= QString::number(idF);
    QString tel= QString::number (num_tel);
    QSqlQuery query;
query.prepare ("INSERT INTO fournisseur (idF, Nom ,num_tel, E_mail)" "VALUES (:idF, :Nom, :num_tel, :E_mail)");
query.bindValue (0, res);
query.bindValue (1, Nom);
query.bindValue (2, tel);
query.bindValue (3, E_mail);
return query.exec ();

}
bool Fournisseur::supprimer(int idF)
{
    QSqlQuery query;
query.prepare ("DELETE from fournisseur where idF=:IdF");
query.bindValue (0, idF);
return query.exec ();
}


QSqlQueryModel* Fournisseur::afficher()
{

  QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("SELECT* FROM fournisseur");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_tel"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("E_mail"));

      return model;
}
bool Fournisseur::modifier(int idF,QString Nom,int num_tel,QString E_mail)
{
QSqlQuery query;
//QString id_string= QString::number(idF);
//QString num_string= QString::number(num_tel);

query.prepare("UPDATE Fournisseur SET idF=:idF, Nom=:nom,num_tel=:num_tel,E_mail:E_mail" " WHERE idF=:idF");
query.bindValue(":idF", idF);
query.bindValue(":Nom", Nom);
query.bindValue(":num_tel", num_tel);
query.bindValue(":E_mail", E_mail);

return    query.exec();
}
bool Fournisseur::chercher(int idF)
   {
       QSqlQuery query;
       QString idF_string= QString::number(idF);
       query.exec("SELECT * FROM Fournisseur WHERE idF='"+idF_string+"'");


       while (query.next()) {
           return  true;

       }
       return false;

   }

