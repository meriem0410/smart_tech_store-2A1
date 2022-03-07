#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_8_clicked();

    void on_supprimer_clicked();

    void on_pushButton_4_clicked();

    void on_modifier_clicked();

    void on_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur F;
};
#endif // MAINWINDOW_H
