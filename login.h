#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();



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

private:
    Ui::login *ui;
    Employer E;
    Employer E1;
     Employer Et;
     Employer m;
};

#endif // LOGIN_H
