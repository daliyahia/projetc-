#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "norme.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_ajouter_clicked()
{
    QString id_n=ui->Line_Edit_id_n->text();
   QString version =ui->comboBox_version->currentText();
   QString principe =ui->Line_Edit_principe->text();
   QString objectifs =ui->Line_Edit_objectifs->text();
 norme  n(id_n,version,principe,objectifs);
bool test=n.ajouter();
if (test)
{
    ui->tableView->setModel(etmp.afficher());//afichage

    QMessageBox::information(nullptr, QObject::tr("add"),
               QObject::tr(" successful.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);


}
else{
    QMessageBox::critical(nullptr, QObject::tr("add"),
                QObject::tr(" failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

}

void MainWindow::on_btn_supprimer_clicked()
{
    int i;
    QModelIndex index=ui->tableView->currentIndex();
     i=index.row();
    QModelIndex in=index.sibling(i,0);

    QString val=ui->tableView->model()->data(in).toString();
    //int id=ui->lineEdit_idsup->text().toInt();
    bool test=etmp.supprimer(val);
    if (test)
    {
        ui->tableView->setModel(etmp.afficher());
}
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
   QModelIndex in=index.sibling(i,0);
   QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select id_n,version,principe,objectifs from norme where id_n='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->Line_Edit_id_n->setText(qry.value(0).toString());
            ui->comboBox_version->setCurrentText(qry.value(1).toString());
            ui->Line_Edit_principe->setText(qry.value(2).toString());
            ui->Line_Edit_objectifs->setText(qry.value(3).toString());

        }
}
}
void MainWindow::on_btn_modifier_clicked()
{
    QString id_n=ui->Line_Edit_id_n->text();
    QString version =ui->comboBox_version->currentText();
    QString principe=ui->Line_Edit_principe->text();
    QString objectifs=ui->Line_Edit_objectifs->text();
    norme n(id_n,version,principe,objectifs);
     bool test=n.modifier(id_n);
       ui->tableView->setModel(etmp.afficher());
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

void MainWindow::on_clear_clicked()
{
     ui->Line_Edit_id_n->clear();
     ui->comboBox_version->clear();
     ui->Line_Edit_principe->clear();
     ui->Line_Edit_objectifs->clear();

}
