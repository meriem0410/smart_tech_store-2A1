#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->N_fact->setValidator (new QIntValidator (0,9999,this));
    ui->num_fact2->setValidator (new QIntValidator (0,9999,this));
    ui->tab_com->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int NUM_FACTURE=ui->N_fact->text().toInt();
    int QTE_PRODUIT=ui->Qte->text().toUInt();
    QString DATE_ACHAT=ui->Dt_ach->text();
    Commande C(NUM_FACTURE,QTE_PRODUIT,DATE_ACHAT);
    bool test=C.ajouter();
    QMessageBox msgBox;
        if (test)
        {
            msgBox.setText("ajouter avec succes");
            ui->tab_com->setModel(C.afficher());
            ui->Qte->clear();
            ui->N_fact->clear();
            ui->Dt_ach->clear();
        }
        else
            msgBox.setText("Echec");
            msgBox.exec();
}

void MainWindow::on_supprimer_clicked()
{
    Commande C1; C1.setNUM_FACTURE(ui->num_sup->text().toUInt());
    bool test=C1.supprimer(C1.getNUM_FACTURE());
    QMessageBox msgBox;
        if (test)
        {
            msgBox.setText("supprimer avec succes");
            ui->tab_com->setModel(C.afficher());
            ui->num_sup->clear();
        }
        else
            msgBox.setText("Echec");
            msgBox.exec();
}

void MainWindow::on_modifier_clicked()
{
    int NUM_FACTURE=ui->num_fact2->text().toInt();
    QString DATE_ACHAT=ui->Dt_ach2->text();
    int QTE_PRODUIT=ui->Qte2->text().toInt();
    //Commande C(NUM_FACTURE,DATE_ACHAT,QTE_PRODUIT);
    Commande C(NUM_FACTURE,QTE_PRODUIT,DATE_ACHAT);
    {
        bool test=C.modifier(NUM_FACTURE,QTE_PRODUIT,DATE_ACHAT);
        QMessageBox msgBox;
        if (test)
        {
            ui->tab_com->setModel(C.afficher());
            msgBox.setText("modifier avec succes");
            ui->Qte2->clear();
            ui->num_fact2->clear();
            ui->Dt_ach2->clear();
        }
        else
            msgBox.setText("Echec");
            msgBox.exec();
}

    }


