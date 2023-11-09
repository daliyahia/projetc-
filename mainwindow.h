#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Employer E;
    Employer E1;
     Employer Et;
};
#endif // MAINWINDOW_H
