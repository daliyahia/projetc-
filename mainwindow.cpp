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


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->la_id->setValidator( new QIntValidator(0, 9999, this));

    ui->tab_employer->setModel(Et.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Boutton_sup_clicked()
{
    Employer E1;E1.setid((ui->la_id_supp->text().toInt()));
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

void MainWindow::on_Boutton_Ajouter_clicked()
{
    QMessageBox msgBox;
    int id=ui->la_id->text().toInt();
    QString nom=ui->la_nom->text();
    QString prenom=ui->la_prenom->text();
    QString adresse=ui->la_adresse->text();
    QString role=ui->la_role->text();
    int suivi=ui->la_suivi->text().toInt();
   Employer E(id,nom,prenom,adresse,role,suivi);
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

void MainWindow::on_Boutton_Modifier_clicked()
{

        QString nom=ui->la_nom->text();
        QString prenom=ui->la_prenom->text();
        int id=ui->la_id->text().toInt();
        int suivi=ui->la_suivi->text().toInt();
        QString adresse=ui->la_adresse->text();
        QString role=ui->la_role->text();


      Employer E1 (id,nom,prenom,adresse,role,suivi);
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



void MainWindow::on_Boutton_tri_nom_clicked()
{
   Employer E1;
   ui->tab_employer->setModel(E1.tri_nom());
  }

void MainWindow::on_Boutton_tri_suivi_clicked()
{
    Employer E1;
    ui->tab_employer->setModel(E1.tri_suivi());
}

void MainWindow::on_Boutton_tri_ID_clicked()
{
    Employer E1;
    ui->tab_employer->setModel(E1.tri_ID());
}

void MainWindow::on_Boutton_rechecher_clicked()
{
     QString rech=ui->la_chercher_nom->text();
      ui->tab_employer->setModel(E1.chercher_nom(rech));

}

/*void MainWindow::on_Button_statistique_clicked()
{
    ui->G_employer->setCurrentIndex(2);
    ui->progressBar->setValue(0);
}*/

void MainWindow::on_Button_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/melli/Desktop/sarra.pdf");

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




                    i = i + 350;
                 }
                 QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                 QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}
