#include "mainwindow.h"
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
#include "QMainWindow"
#include "ui_mainwindow.h"
#include "employerui.h"
#include "normeui.h"
#include "archiveui.h"
#include "auditui.h"
#include "matrielui.h"
#include "ui_matrielui.h"
#include "matriels.h"
login::login(QWidget *parent):
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}
void login::on_Button_valider_clicked()
{
 QSqlQueryModel model;
  QString at="";

  QString nom = ui->la_login_nom->text();
      //int id = ui->la_login_mdp->text().toInt();
         QString role = ui->la_login_nom->text();
         QString rfid = ui->RFID->text();


         // rfid=A.read_from_arduino();

        //QString id_string=QString::number(id);
        QSqlQuery query;
       /* query.prepare("SELECT * FROM AUDITEURS WHERE nom=:NOM AND prenom=:PRENOM AND id=:ID  ");
        query.bindValue(":NOM", nom);
        query.bindValue(":ID",id);
        query.bindValue(":ROLE",role);
        //query.bindValue(":RFID",rfid);*/
        model.setQuery("SELECT * FROM AUDITEURS WHERE (NOM  LIKE '"+ui->la_login_nom->text()+"');");
        QString mdp=model.data(model.index(0, 0)).toString();
        QString Nom=model.data(model.index(0, 1)).toString();
        QString rolee=model.data(model.index(0, 4)).toString();
        QString rfidd=model.data(model.index(0, 7)).toString();


       // at=A.read_from_arduino();


    /* if (at=="")

             at = ui->RFID->text();


             model.setQuery(query);

      qInfo() << "RFID= "<<rfidd<<" "<<Nom;*/


        if (/*(query.exec()) && (query.next()) && (rfidd==ui->RFID->text()) &&*/ (mdp==ui->la_login_mdp->text()))
        {


           // at=Nom;



          // A.write_to_arduino(at);

            if  ( rolee=="ADMIN" /*&& rfidd == ui->RFID->text()*/ ) {

                this->hide();
                menu m;
                m.exec();

            } else if (rolee=="auditeur")
            {
                this->hide();
                //employerui E;
               // E.exec();

                 normeui k;
                 k.exec();

            }
            else if(rolee=="archiviste")
            {   this->hide();
                archiveui r;
                r.exec();

            }

            else if(rolee=="superviseur")
            {  this->hide();
               auditui p;
               p.exec();
            }
            else if(rolee=="gestionaire")
            {  this->hide();
               matrielui M;
               M.exec();
            }
            // Assuming rolee is a variable containing the role

           /* switch(QString rolee) {
                case "ADMIN":
                     this->hide();
                    menu m;
                    m.exec();

                    break;
                case "auditeur":
                    this->hide();
                    // employerui E;
                    // E.exec();
                    normeui k;
                    k.exec();
                    break;
                case "archiviste":
                    this->hide();
                    archiveui r;
                    r.exec();
                    break;
                case "supervieur":
                    this->hide();
                    auditui p;
                    p.exec();
                    break;
                default:
                    // Handle the case if rolee doesn't match any of the specified roles
                    break;
            }*/


        }
        else {
            QMessageBox::critical(this, "Erreur de connexion", "Nom d'utilisateur ou mot de passe incorrects");
        }

}


void login::on_Scan_clicked()
{
    QString at=A.read_from_arduino();

    at=at.simplified();
    at.replace(" ","");

    if (at!="") ui->RFID->setText(at);
}




