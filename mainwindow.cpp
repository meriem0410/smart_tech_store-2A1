#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_fournisseur->setModel(F.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int idF=ui->id->text().toInt();
    QString Nom=ui->nom->text();
    int num_tel=ui->num_tel->text().toInt();
    QString E_mail=ui->e_mail->text();
            Fournisseur F(idF,Nom,num_tel,E_mail);
    bool test=F.ajouter();
    QMessageBox msgBox;
    if (test)
    {
        ui->tab_fournisseur->setModel(F.afficher());
        msgBox.setText("ajout avec succes");
}
    else
        msgBox.setText("Echec");
        msgBox.exec();
}



void MainWindow::on_supprimer_clicked()
{
Fournisseur F1; F1.setidF(ui->id_sup->text().toInt());
bool test=F1.supprimer(F1.getidF());

        QMessageBox msgBox;
        if (test)
        {
        msgBox.setText("Succes");
        ui->tab_fournisseur->setModel(F.afficher());
        }
        else
            msgBox.setText("Echec");
            msgBox.exec();
}


void MainWindow::on_modifier_clicked()
{
    int idF=ui->id_3->text().toInt();
    QString Nom=ui->nom_3->text();
    int num_tel=ui->num_tel_2->text().toInt();
    QString E_mail=ui->mail_2->text();


 Fournisseur f (idF,Nom,num_tel,E_mail);


     {
     bool test=f.modifier(idF,Nom,num_tel,E_mail);
      if(test)
     {

           ui->tab_fournisseur->setModel(f.afficher());
     QMessageBox::information(nullptr, QObject::tr("modifier "),
                       QObject::tr("Modification effectuée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
     ui->statusbar->showMessage("compte modifié");
//     d.notifications_modifierdemande();
     }
       else
         {  QMessageBox::critical(nullptr, QObject::tr("modifier "),
                       QObject::tr("Echec de la modification  \n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
      ui->statusbar->showMessage("compte non modifié");
}
}
}






void MainWindow::on_pushButton_4_clicked()
{
    Fournisseur f;

        int idF=ui->id_rech->text().toInt();


             bool test=f.chercher(idF);

             if(test)
             {
                 QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                         QObject::tr("fournisseur a chercher existe\n"
                                                     "Cliquez sur cancel Pour Quitter."), QMessageBox::Cancel);
             ui->statusbar->showMessage("recherche terminée");
             //d.notifications_trouverdemande();
             }
             else
             {  QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                     QObject::tr("Echec de la recherche.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
}






