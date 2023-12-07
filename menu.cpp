#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "menu.h"
#include "login.h"
#include "employerui.h"
#include "ui_mainwindow.h"


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}



void menu::on_Button_employer_clicked()
{

    //this->hide();
   // employerui E;
    //E.exec();

    MainWindow *mainWin = new MainWindow(this);
     mainWin->show();
}

void menu::on_Button_Quitter_clicked()
{

        int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur esque tu est sur tu veux quitter?", QMessageBox ::Yes | QMessageBox::No);

            if (reponse == QMessageBox::Yes)
            {
                QMessageBox::critical(this, "bayy bayy", "Ala pouchane !");
                close();
            }
            else if (reponse == QMessageBox::No)
            {

                 QMessageBox::information(this, "Helloo", "Alors bienvenue!");
            }

}






