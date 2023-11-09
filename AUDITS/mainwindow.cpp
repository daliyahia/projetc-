#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audits.h"
#include <QMessageBox>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui ->le_numd->setValidator(new QIntValidator(0,9999999,this));
    ui->table_audits->setModel(A.afficher());

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

        int NUM_D = ui->le_numd->text().toInt();
        QString ACTION=ui->le_action->text();
        QString DATE_AUDIT=ui->la_date->text();
        ui->table_audits->setModel(A.afficher());

      AUDITS A (NUM_D, ACTION,DATE_AUDIT);

        bool insertionSuccess = A.ajouter();
        ui->table_audits->setModel(A.afficher());


        QMessageBox messageBox;

        if (insertionSuccess) {
            messageBox.setText("Data added to the database successfully!");
        } else {
            messageBox.setText("Failed to add data to the database.");
        }
        messageBox.exec();
    }




void MainWindow::on_bt_supp_clicked()
{
   AUDITS A;
        int NUM_D_to_delete = ui->le_numd->text().toInt();
        bool test = A.supprimer(NUM_D_to_delete);
        if(test)
        {

            ui->table_audits->setModel(A.afficher());
            QMessageBox::information(this,QObject::tr("ok"),
            QObject::tr("suppression effectuée\nClick OK to exit."),QMessageBox::Ok);
        }

        else
        {
        QMessageBox::information(this, tr("Not OK"), tr("Deletion was not successful. Click OK to exit."), QMessageBox::Ok);
        }

}


void MainWindow::on_pushButton_2_clicked()
{
    int NUM_D =ui->le_numd->text().toInt();
     QString ACTION=ui->le_action->text();
     QString DATE_AUDIT=ui->la_date->text();
     AUDITS A (NUM_D, ACTION,DATE_AUDIT);
     bool test=A.modifier(NUM_D);
          ui->table_audits->setModel(A.afficher());
              if(test){
                  QMessageBox::information(nullptr, QObject::tr("update"),
                        QObject::tr(" successful.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }
              else
              {
             QMessageBox::critical(nullptr, QObject::tr("update"),
                         QObject::tr(" failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             }

}
