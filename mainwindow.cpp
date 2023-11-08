#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include<matriels.h>
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(etmp.afficher());
     ui->Line_Edit_quantite->setValidator(new QIntValidator(0,9999,this));//cs
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_ajouter_clicked()
{
    QString ref=ui->Line_Edit_referance->text();
QString nom=ui->Line_Edit_nom->text();
QString etat=ui->comboBox_etat->currentText();

int quantite=ui->Line_Edit_quantite->text().toInt();
Matriels m(ref,nom,etat,quantite);
bool test=m.ajouter();
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

    bool test=etmp.supprimer(val);
    if (test)
    {
        ui->tableView->setModel(etmp.afficher());




}}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select reference,nom,etat,quantite from matriels where reference='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->Line_Edit_referance->setText(qry.value(0).toString());
            ui->Line_Edit_nom->setText(qry.value(1).toString());
            ui->comboBox_etat->setCurrentText(qry.value(2).toString());
            ui->Line_Edit_quantite->setText(qry.value(3).toString());

//
        }
}
}

void MainWindow::on_btn_modifier_clicked()
{
    QString ref=ui->Line_Edit_referance->text();
QString nom=ui->Line_Edit_nom->text();
QString etat=ui->comboBox_etat->currentText();

int quantite=ui->Line_Edit_quantite->text().toInt();
Matriels m(ref,nom,etat,quantite);
bool test=m.modifier(ref);
    ui->tableView->setModel(etmp.afficher());
 if(test){
     QMessageBox::information(nullptr, QObject::tr("update"),
                QObject::tr(" successful.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);



}else{
     QMessageBox::critical(nullptr, QObject::tr("update"),
                 QObject::tr(" failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);



 }


}
