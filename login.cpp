#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QSqlQuery>
#include<QPixmap>
#include<QListWidget>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QDesktopServices>
#include"login.h"
#include "menu.h"
#include<QDialog>
#include "ui_login.h"


login::login(QWidget *parent):
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->la_id->setValidator( new QIntValidator(0, 9999, this));

    ui->tab_employer->setModel(Et.afficher());
}

login::~login()
{
    delete ui;
}




void login::on_Boutton_sup_clicked()
{
    Employer E1;E1.setid((ui->la_id->text().toInt()));
    bool test=E1.supprimer(E1.getid());

    QMessageBox msgBox;
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Suppression effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_employer->setModel(E.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("Suppression non  effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void login::on_Boutton_Ajouter_clicked()
{
    QMessageBox msgBox;
    int id=ui->la_id->text().toInt();
    QString nom=ui->la_nom->text();
    QString prenom=ui->la_prenom->text();
    QString adresse=ui->la_adresse->text();
    QString role=ui->la_role->text();
    int suivi=ui->la_suivi->text().toInt();
    float salaire=ui->la_salaire->text().toFloat();

   Employer E(id,nom,prenom,adresse,role,suivi,salaire);
   bool test=E.ajouter();
   if(test)
   {

       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("Ajouter effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_employer->setModel(E.afficher());

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                   QObject::tr("Ajouter non  effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


}

void login::on_Boutton_Modifier_clicked()
{

        QString nom=ui->la_nom->text();
        QString prenom=ui->la_prenom->text();
        int id=ui->la_id->text().toInt();
        int suivi=ui->la_suivi->text().toInt();
        QString adresse=ui->la_adresse->text();
        QString role=ui->la_role->text();
        float salaire=ui->la_salaire->text().toFloat();


      Employer E1 (id,nom,prenom,adresse,role,suivi,salaire);
       bool test=E1.modifier(id);


       if(test)
    {

                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("update successful.\n"
                                        "update effectuer."), QMessageBox::Cancel);
                ui->tab_employer->setModel(E1.afficher());



    }
            else

                QMessageBox::critical(nullptr, QObject::tr("nope"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }



void login::on_Boutton_tri_nom_clicked()
{
   Employer E1;
   ui->tab_employer->setModel(E1.tri_nom());
  }

void login::on_Boutton_tri_suivi_clicked()
{
    Employer E1;
    ui->tab_employer->setModel(E1.tri_suivi());
}

void login::on_Boutton_tri_ID_clicked()
{
    Employer E1;
    ui->tab_employer->setModel(E1.tri_ID());
}

void login::on_Boutton_rechecher_clicked()
{
     QString rech=ui->la_chercher_nom->text();
      ui->tab_employer->setModel(E1.chercher_nom(rech));

}



void login::on_Button_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/melli/Desktop/auditeurs.pdf");

          QPainter painter(&pdf);
          int i = 4000;
                 painter.setPen(Qt::darkCyan);
                 painter.setFont(QFont("Time New Roman", 25));
                 painter.drawText(3000,1400,"Employe");
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Time New Roman", 15));
                 painter.drawRect(100,100,9400,2500);
                 painter.drawRect(100,3000,9400,500);
                 painter.setFont(QFont("Time New Roman", 9));
                 painter.drawText(4400,3300," ID");
                 painter.drawText(400,3300,"NOM");
                 painter.drawText(1350,3300,"PRENOM");
                 painter.drawText(2200,3300,"ADRESSE");
                 painter.drawText(3400,3300,"ROLE");
                 painter.drawText(4400,3300,"SUIVI");
                 painter.drawText(4400,3300,"SALAIRE");

                 painter.drawRect(100,3000,9400,9000);

                 QSqlQuery query;
                 query.prepare("select * from AUDITEURS");
                 query.exec();
                 while (query.next())
                 {

                     painter.drawText(1350,i,query.value(1).toString());
                     painter.drawText(2300,i,query.value(2).toString());
                     painter.drawText(3400,i,query.value(3).toString());
                     painter.drawText(4400,i,query.value(4).toString());
                     painter.drawText(6200,i,query.value(5).toString());
                     painter.drawText(6200,i,query.value(6).toString());




                    i = i + 350;
                 }
                 QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                 QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void login::on_Button_statistique_clicked()
{
    Employer E;
        float s;
        QString m;
        QString role=ui->la_stat_role->text();
        s=E.statistique(role);
        m="Statistique pour le role " + role+":";

            // Affichez le message dans le QLabel
            ui->la_msg->setText(m);
            ui->progressBar->setValue(s);
            QLineEdit *LineEdit1 =ui->la_stat_role;
            LineEdit1->clear();
}

void login::on_Button_emp_mois_clicked()
{
    Employer E;

    Employer employeDuMois = E.employer_du_mois();
    employeDuMois=E.employer_du_mois();
    int newsuivi=(employeDuMois.getsuivi()-20)*50;
    if ( newsuivi>20)
    {
        QString newsuivi_string=QString::number(newsuivi);
        QString m="L'employe du mois est  " + employeDuMois.getnom() + " " + employeDuMois.getprenom() +"  "+"\n"+ "! Felicitations ! vous aurez un prime" +"  "+ newsuivi_string + " "+ "DT";

            ui->la_msg_emp_mois->setText(m);
    }
    else
    {
        QString m2="Desole il n'ya pas d'employe fidele pour ce mois";
        ui->la_msg_emp_mois->setText(m2);
    }

}

/*void checkLogin(const QString& username, const QString& password) {
    // Récupérer les informations de l'utilisateur depuis la base de données ou autre source
    Employer E; // Récupérer les détails de l'utilisateur depuis une source de données

    if (username == E.getnom() && password == E.getid()) {
        if (E.getrole() == UserRole::ADMIN) {
            // Rediriger vers l'interface de l'administrateur (menu.ui)
            // ...
        } else {
            // Rediriger vers l'interface de l'employé (login.ui)
            // ...
        }
    } else {
        // Afficher un message d'erreur pour une connexion invalide
        // ...
    }*/






void login::on_pushButton_clicked()
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
