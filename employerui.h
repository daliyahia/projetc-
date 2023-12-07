#ifndef EMPLOYERUI_H
#define EMPLOYERUI_H

#include <QDialog>

namespace Ui {
class employerui;
}

class employerui : public QDialog
{
    Q_OBJECT

public:
    explicit employerui(QWidget *parent = nullptr);
    ~employerui();

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
    Ui::employerui *ui;
};

#endif // EMPLOYERUI_H
