#include "matrielui.h"
#include "ui_matrielui.h"
#include <QIntValidator>
#include<matriels.h>
#include<QString>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QPrinter>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>
#include <QLayout>
#include <QVector>
#include <QStringList>
#include <QPalette>
#include <QApplication>
#include <QBarSet>
#include <QSound>
#include <QSoundEffect>
#include "exportexcelobject.h"
#include <QMainWindow>
#include "matriels.h"

matrielui::matrielui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrielui)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
    ui->Line_Edit_quantite->setValidator(new QIntValidator(0,9999,this));//cs
     ui->numero->setValidator(new QIntValidator(0,99999999,this));//cs
    QRegularExpressionValidator *stringValidator = new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this);
    ui->Line_Edit_nom->setValidator(stringValidator);
}

matrielui::~matrielui()
{
    delete ui;
}
void matrielui::on_btn_ajouter_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    QString ref=ui->Line_Edit_referance->text();
QString nom=ui->Line_Edit_nom->text();
QString etat=ui->comboBox_etat->currentText();

int quantite=ui->Line_Edit_quantite->text().toInt();
Matriels m(ref,nom,etat,quantite);
bool test=m.ajouter();
ui->tableView->setModel(etmp.afficher());//afichage
/*if (test)
{

    ui->tableView->setModel(etmp.afficher());//afichage


    QMessageBox::information(nullptr, QObject::tr("add"),
               QObject::tr(" successful.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);*/
    notif.notifAjouterMateriels();
    ui->Line_Edit_referance->clear();
    ui->Line_Edit_nom->clear();
   // ui->comboBox_etat->clear();
    ui->Line_Edit_quantite->clear();

//}
/*else{

    QMessageBox::critical(nullptr, QObject::tr("add"),
                QObject::tr(" failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}*/

}

void matrielui::on_btn_supprimer_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    int i;
    QModelIndex index=ui->tableView->currentIndex();
i=index.row();
QModelIndex in=index.sibling(i,0);

QString val=ui->tableView->model()->data(in).toString();

    bool test=etmp.supprimer(val);
    if (test)
    {

        ui->tableView->setModel(etmp.afficher());
        notif.notifSupprimerMatereils();
        ui->Line_Edit_referance->clear();
        ui->Line_Edit_nom->clear();
       // ui->comboBox_etat->clear();
        ui->Line_Edit_quantite->clear();




}}

void matrielui::on_tableView_clicked(const QModelIndex &index)
{
    int i;
    QString qrCodeData;
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
            qrCodeData ="REFERENCE : "+qry.value(0).toString()+" | NOM : "+qry.value(1).toString()+" | ETAT : "+qry.value(2).toString()+" | QUANTITE : "+qry.value(3).toString();


//
        }
}
    //QR CODE
    using namespace qrcodegen;
    // Create the QR Code object
      QrCode qr = QrCode::encodeText( qrCodeData.toUtf8().data(), QrCode::Ecc::MEDIUM );
      // Obtenir la taille du QR Code
      qint32 sz = qr.getSize();
      // Créer une image avec la taille du QR Code
      QImage im(sz,sz, QImage::Format_RGB32);

      QRgb black = qRgb(  0,  0,  0);
      QRgb white = qRgb(255,255,255);
   for (int y = 0; y < sz; y++)
        for (int x = 0; x < sz; x++)
             im.setPixel(x,y,qr.getModule(x, y) ? black : white );
   // Afficher l'image du QR Code dans un QLabel
   ui->qrCodeLabel->setPixmap( QPixmap::fromImage(im.scaled(150,150,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
}

void matrielui::on_btn_modifier_clicked()
{
    QString ref=ui->Line_Edit_referance->text();
QString nom=ui->Line_Edit_nom->text();
QString etat=ui->comboBox_etat->currentText();

int quantite=ui->Line_Edit_quantite->text().toInt();
Matriels m(ref,nom,etat,quantite);
bool test=m.modifier(ref);
    ui->tableView->setModel(etmp.afficher());
 if(test){
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
    sound->play();
     /*QMessageBox::information(nullptr, QObject::tr("update"),
                QObject::tr(" successful.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);*/
     notif.notifModifierMateriels();
     ui->Line_Edit_referance->clear();
     ui->Line_Edit_nom->clear();
    // ui->comboBox_etat->clear();
     ui->Line_Edit_quantite->clear();



}/*else{
     QMessageBox::critical(nullptr, QObject::tr("update"),
                 QObject::tr(" failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);



 }*/


}


void matrielui::on_trimatrielsComboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "par défaut")
    {
       ui->tableView->setModel(etmp.trimatriels(arg1));
    }
    else if(arg1 == "reference")
    {
        ui->tableView->setModel(etmp.trimatriels(arg1));
    }
    else if(arg1 == "nom")
    {
        ui->tableView->setModel(etmp.trimatriels(arg1));
    }
    else
    {
        ui->tableView->setModel(etmp.trimatriels(arg1));
    }

}

void matrielui::on_rechercheBar_textChanged(const QString &arg1)
{
    if(arg1!="")
    ui->tableView->setModel(etmp.recherchermatriels(arg1));
    else
        ui->tableView->setModel(etmp.recherchermatriels(arg1));}


void matrielui::on_PDF_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        filePath = QDir(filePath).filePath("Gestion_matriels/listeMatriels.pdf");//stocker du shemin du fichier
        QPdfWriter pdf(filePath);//creation de fichier PDF

           QPainter painter(&pdf);//dessiner de fichier PDF
           int i = 4100;

                  QColor dateColor(0x4a5bcf);//dessin des informations
                  painter.setPen(dateColor);

                  painter.setFont(QFont("Montserrat SemiBold", 11));
                  QDate cd = QDate::currentDate();
                  painter.drawText(8400,250,cd.toString("Tunis"));//dessiner entete de date
                  painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                  QColor titleColor(0x341763);
                  painter.setPen(titleColor);
                  painter.setFont(QFont("Montserrat SemiBold", 25));

                  painter.drawText(3000,2700,"Liste des matriels");// dessiner le titre

                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  //painter.drawRect(100,100,9400,2500);
                  painter.drawRect(100,3300,9400,500);//dessiner le cadre de tab
//dessiner les informations de tab
                  painter.setFont(QFont("Montserrat SemiBold", 10));

                  painter.drawText(500,3600,"reference");
                  painter.drawText(2000,3600,"nom");
                  painter.drawText(3300,3600,"etat");
                  painter.drawText(7500,3600,"quantite");
                  painter.setFont(QFont("Time New Roman", 10));
                  painter.drawRect(100,3300,9400,9000);
//requête SQL pour sélectionner tous les enregistrements de la table "matriels".
                  QSqlQuery query;
                  query.prepare("select * from matriels");
                  query.exec();
                  int y=4300;
                  while (query.next())
                  {
                      painter.drawLine(100,y,9490,y);
                      y+=500;
                      painter.drawText(500,i,query.value(0).toString());
                      painter.drawText(2000,i,query.value(1).toString());
                      painter.drawText(3300,i,query.value(3).toString());
                      painter.drawText(7500,i,query.value(2).toString());

                     i = i + 500;
                  }

                  QMessageBox::information(nullptr,QObject::tr("Pdf created"),
                  QObject::tr("File created with seccess.\n"
                              ""),QMessageBox::Ok);

    }




void matrielui::statmatriels()
{
    // Obtient le layout actuel de ui->MaterielsStatContainer
    QLayout* layoutTest = ui->MaterielsStatContainer->layout();
    if (layoutTest) {
        delete layoutTest;  // Delete the existing layout object
    }
     // Appelle la fonction statmatriels() de l'objet etmp pour récupérer les statistiques
    QVector<int> stat = etmp.statmatriels();
     // Crée un ensemble de barres pour les données statistiques
    QBarSet *set = new QBarSet("quantite");


    for(int i=0; i <stat.size(); i++)
    {
        *set << stat[i];
    }
    // Crée une série de barres et y ajoute l'ensemble de barres
    QBarSeries *series = new QBarSeries();
    //yajouter fiha
    series->append(set);
     // Crée un objet de graphique
    QChart *chart = new QChart();
     // Ajoute la série de barres au graphique
    chart->addSeries(series);
    chart->setTitle("statistique");
     // Active les options d'animation pour le graphique
    chart->setAnimationOptions(QChart::AllAnimations);
    // Définit les étiquettes de l'axe Y
    QStringList list;
        list << "quantite +10" << "quantite -10";
        // Crée un axe de valeur pour l'axe Y
    QValueAxis *axisY = new QValueAxis();
    chart->setAxisY(axisY,series);
    // Crée un axe de catégorie pour l'axe X et y ajoute les étiquettes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(list);//y7ot Q-10 w Q+10 ml lota
     // Ajoute les axes par défaut au graphique
    chart->createDefaultAxes();
   // Définit l'axe X pour le graphique
    chart->setAxisX(axisX,series);
    // Configure la palette de l'application pour les couleurs du graphique
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    qApp->setPalette(pal);
     // Crée une vue de graphique basée sur le graphique
    QChartView * chartView= new QChartView(chart);
    // Configure l'antialiasing pour la vue de graphique
    chartView->setRenderHint(QPainter::Antialiasing);
    // Définit la taille minimale de la vue de graphique
    chartView->setMinimumSize(801,311);
    // Crée un layout vertical, y ajoute la vue de graphique
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    ui->MaterielsStatContainer->setLayout(layout);
    }
void matrielui::on_statistique_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
  ui->tab;
  statmatriels();
}



/*void matrielui::on_pushButton_call_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    QByteArray num=ui->numero->text().toUtf8();
        qDebug()<<num<<endl;
        A.write_to_arduino(num);
}


QString test;
void matrielui::message()
{

    data=A.read_from_arduino();
    qDebug()<<data;
            test1=data;
            test=test1.left(test1.length()-2);
           qDebug()<<test1.left(test1.length()-2);
        if ( test[0]!="+"&& test!="" && test!="OK"  )
        {
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

           notifyIcon->show();
            notifyIcon->showMessage("Massege for Arduino",test,QSystemTrayIcon::Information,15000);
            srand (time(NULL));
         QSqlQuery query;

     //QDate res=QDate::currentDate();
     QDateTime t = QDateTime::currentDateTime();


     query.prepare("insert into logs (log,time )""values(:log,:time)");
     query.bindValue(":log", test);
     query.bindValue(":time", t);

     query.exec();
        }
}*/

void matrielui::on_excel_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "matriels", ui->tableView);

    //colums to export
    obj.addField(0, "REFERENCE", "char(20)");
    obj.addField(1, "NOM", "char(20)");
    obj.addField(2, "ETAT", "char(20)");
    obj.addField(3, "QUANTITE", "int");



   // int retVal = obj.export2Excel();
   //if( retVal > 0)
    {
      //  ui->label_done->show();
        //ui->pushButton_hide->show();

    }

}

void matrielui::on_clear_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    ui->Line_Edit_referance->clear();
    ui->Line_Edit_nom->clear();
  //  ui->comboBox_etat->clear();
    ui->Line_Edit_quantite->clear();

}
