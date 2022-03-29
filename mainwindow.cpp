#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QDesktopServices>
#include <QApplication>
#include <QMessageBox>
#include "produit.h"
#include <QIntValidator>
#include <QObject>
#include "connection.h"
#include "stock.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pr_prix->setValidator(new QIntValidator(0, 99999, this));
    ui->pr_seuil->setValidator(new QIntValidator(0, 99999, this));
    ui->lineEdit_prix->setValidator(new QIntValidator(0, 99999, this));
    ui->lineEdit_seuil->setValidator(new QIntValidator(0, 99999, this));
    ui->lineEdit_lib->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
     ui->pr_lib->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->tab_produit->setModel(p.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pr_ajouter_clicked()
{

    QString ref= ui->pr_ref->text();
    QString lib= ui->pr_lib->text();
    int prix= ui->pr_prix->text().toInt();
    QString seuil= ui->pr_seuil->text();
    QString descr= ui->pr_descr->text();
    produit p(ref,lib,prix,seuil,descr);
    bool test=p.ajouter();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("PRODUIT ADD "),
                                      QObject::tr("PRODUIT ADDED SUCCESSFULLY.\n"), QMessageBox::Ok);
        ui->tab_produit->setModel(p.afficher());


    }

}
QSqlQueryModel* produit::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM PRODUIT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEUIL"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));







    return model;
}
QSqlQueryModel* produit::trier(QString attribute , QString croissance){
    QSqlQueryModel* model = new QSqlQueryModel();
    if(attribute == "Reference" && croissance == "croissante")
        model->setQuery("SELECT * FROM PRODUIT ORDER BY REF ASC ");
    else if (attribute == "Prix" && croissance == "croissante")
        model->setQuery("SELECT * FROM PRODUIT ORDER BY PRIX ASC ");
    else if(attribute == "Reference" && croissance == "decroissante")
        model->setQuery("SELECT * FROM PRODUIT ORDER BY REF DESC ");
    else if(attribute == "Prix" && croissance == "decroissante")
        model->setQuery("SELECT * FROM PRODUIT ORDER BY PRIX DESC ");

    return model;
}

QSqlQueryModel* produit::recherche(QString ref_r){
   QSqlQueryModel* model = new QSqlQueryModel();
   QString search = "%"+ref_r+"%";
    model->setQuery("SELECT * FROM PRODUIT WHERE REF like '"+search+"'");
    return model ;
}


QSqlQueryModel* produit::combo(){
    QSqlQueryModel* model = new QSqlQueryModel();

     model->setQuery("SELECT REF FROM PRODUIT ");
     return model ;

}

void MainWindow::on_pr_supp_clicked()
{
    produit p; p.setref(ui->lineEdit_ref->text());
    bool test=p.supprimer(p.getref());
    if (test){
        QMessageBox::information(nullptr, QObject::tr("PRODUIT DELETED "),
                                      QObject::tr("PRODUIT DELETED SUCCESSFULLY.\n"), QMessageBox::Ok);
        ui->tab_produit->setModel(p.afficher());

    }

}

void MainWindow::on_tab_produit_activated(const QModelIndex &index)
{
    QString value=ui->tab_produit->model()->data(index).toString();
         Connection c;
        // c.closeConnection();
         QSqlQuery qry;

         qry.prepare("select * from produit where ref='"+value+"'");
         if(qry.exec())
         {
             while(qry.next()){
                ui->lineEdit_ref->setText(qry.value(0).toString());
             ui->lineEdit_lib->setText(qry.value(1).toString());
              ui->lineEdit_prix->setText(qry.value(2).toString());
              ui->lineEdit_seuil->setText(qry.value(3).toString());
              ui->lineEdit_descr->setText(qry.value(4).toString());


             }
}
}

void MainWindow::on_pushButton_clicked()
{
    produit p;
    p.setref(ui->lineEdit_ref->text());
    p.setlib(ui->lineEdit_lib->text());
    p.setprix(ui->lineEdit_prix->text().toInt());
    p.setrseuil(ui->lineEdit_seuil->text());
    p.setdescr(ui->lineEdit_descr->text());


    bool check=p.modifier();

    if (check)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification"),
        QObject::tr("Modification avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::information(nullptr, QObject::tr("Modification"),
        QObject::tr("Modification échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tab_produit->setModel(p.afficher());
}

void MainWindow::on_TriBTN_clicked()
{
    QString attribute = ui->attributeBox->currentText();
        QString croissance = ui->croissanceBox->currentText();
        ui->tab_produit->setModel(p.trier(attribute,croissance));
}

void MainWindow::on_RechercheBTN_clicked()
{
    QString ref_r = ui->Ref_rech->text();
    ui->tab_produit->setModel(p.recherche(ref_r));
}

void MainWindow::on_actualiser_clicked()
{
    QString attribute = ui->attributeBox->currentText();
        QString croissance = ui->croissanceBox->currentText();
        ui->tab_produit->setModel(p.trier(attribute,croissance));
}



void MainWindow::on_actualiser_2_clicked()
{
    QString attribute = ui->attributeBox->currentText();
        QString croissance = ui->croissanceBox->currentText();
        ui->tab_produit->setModel(p.trier(attribute,croissance));

}

void MainWindow::on_pushButton_2_clicked()
{
    QString attribute = ui->attributeBox->currentText();
        QString croissance = ui->croissanceBox->currentText();
        ui->tab_produit->setModel(p.trier(attribute,croissance));
}

void MainWindow::on_pushButton_3_clicked()
{
stock s;

 ui->ref_p->setModel(p.combo());
 ui->tab_Stock->setModel(s.afficher());

}




QSqlQueryModel* stock::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM STOCK");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("LOT"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBR"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("REF_P"));







    return model;
}


void MainWindow::on_ajouter_stock_clicked()
{
    QString lot= ui->st_lot->text();
    QString ref_p= ui->ref_p->currentText();
    int nbr= ui->st_nbr->text().toInt();

    stock s(lot,nbr,ref_p);
    bool test=s.ajouter();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("STOCK ADD "),
                                      QObject::tr("STOCK ADDED SUCCESSFULLY.\n"), QMessageBox::Ok);
        ui->tab_Stock->setModel(s.afficher());

}
}

void MainWindow::on_tab_Stock_activated(const QModelIndex &index)
{
    QString value=ui->tab_Stock->model()->data(index).toString();
         Connection c;
        // c.closeConnection();
         QSqlQuery qry;
         QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT ref_p FROM STOCK where lot='"+value+"'");
         qry.prepare("select * from stock where lot='"+value+"'");
         if(qry.exec())
         {
             while(qry.next()){
                ui->line_lot->setText(qry.value(0).toString());
             ui->combo_ref->setModel(model);
              ui->line_nbr->setText(qry.value(1).toString());



             }
}
}

void MainWindow::on_pushButton_4_clicked()
{
    stock s;
    s.setlot(ui->line_lot->text());
    s.setref_p(ui->combo_ref->currentText());
    s.setnbr(ui->line_nbr->text().toInt());



    bool check=s.modifier();

    if (check)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification"),
        QObject::tr("Modification avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_Stock->setModel(s.afficher());
    }
    else{
        QMessageBox::information(nullptr, QObject::tr("Modification"),
        QObject::tr("Modification échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
