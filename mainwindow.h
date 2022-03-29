#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pr_ajouter_clicked();

    void on_pr_supp_clicked();

    void on_tab_produit_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_TriBTN_clicked();

    void on_RechercheBTN_clicked();

    void on_pushButton_2_clicked();

    void on_actualiser_clicked();

    void on_actualiser_2_clicked();

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_toolButton_clicked();

    void on_pushButton_3_clicked();

    void on_ajouter_stock_clicked();

    void on_tab_Stock_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    produit p;
};

#endif // MAINWINDOW_H
