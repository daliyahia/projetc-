#include "login.h"
#include "ui_login.h"
#include "admin.h"
#include "employer.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include "menu.h"
#include "connection.h"
#include "dialog.h"
#include "arduino.h"
#include "archive.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* int ret=A.connect_arduino();
               // lancer la connexion à arduino
              switch(ret){
              case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                  break;
              case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                 break;
              case(-1):qDebug() << "arduino is not available";
              }
               QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_valider_clicked()
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

            if  ( (rolee=="ADMIN") || (rolee=="admin") /*&& rfidd == ui->RFID->text()*/ ) {

                this->hide();
                menu m;
                m.exec();
     
            } 
            else if(rolee=="archiviste")
            {
                /*this->hide();
                Archive a;*/

            }
            
            
            else {
                this->hide();
                login l;
                l.exec();
            }

        } else {
            QMessageBox::critical(this, "Erreur de connexion", "Nom d'utilisateur ou mot de passe incorrects");
        }

}


void MainWindow::on_Scan_clicked()
{
    QString at=A.read_from_arduino();

    at=at.simplified();
    at.replace(" ","");

    if (at!="") ui->RFID->setText(at);
}
//
