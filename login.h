#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
//*************************
#include <QMainWindow>
#include <archive.h>
#include <QFileDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

  //*****************
    void setdata();
    void remplirListeArchive();


private slots:

    void on_Boutton_sup_clicked();

    void on_Boutton_Ajouter_clicked();

    void on_Boutton_Modifier_clicked();

    void on_Boutton_tri_nom_clicked();

    void on_Boutton_tri_suivi_clicked();

    void on_Boutton_tri_ID_clicked();

    void on_Boutton_rechecher_clicked();

    void on_Button_statistique_clicked();

    void on_Button_PDF_clicked();

    void on_Button_emp_mois_clicked();

    void on_pushButton_clicked();
 //*************************************
    void on_pushButton_2_clicked();
    void on_bouton_supp_clicked();

    void on_pushButton_3_clicked();

    void on_searchButton_clicked();

    void on_ImportButton_clicked();

    void on_historique_clicked();

    void on_id_clicked();


    void on_statistique_clicked();

    void on_PDF_clicked();

    void on_arduino_clicked();

    void on_e_idE_cursorPositionChanged(int arg1, int arg2);

    void on_e_id_cursorPositionChanged(int arg1, int arg2);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::login *ui;
    Employer E;
    Employer E1;
     Employer Et;
     Employer m;
 //**************************
     int selectedId;
     QString etatformulaire;
     int endusavec;
};

#endif // LOGIN_H
