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
//*************************
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "archive.h"
#include <QDate>
#include <QRegularExpression>
#include <QUuid>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QtCharts>
#include <QSqlError>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QPainter>
#include"generateurpdf.h"


login::login(QWidget *parent):
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->la_id->setValidator( new QIntValidator(0, 9999, this));
    ui->tab_employer->setModel(Et.afficher());

    selectedId = -1;
    etatformulaire = "add";
    endusavec = 0;


    // controle de saisie sur les champs


    ui->e_id->setValidator(new QIntValidator(0,9999999,this)) ;
    ui->e_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,20}"), this)); // les lettre seulement  entre 1 et 20
    ui->e_type->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,20}"), this)); // les lettre seulement  entre 1 et 20
    ui->e_version->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_]{1,20}"), this)); // version accepter entre 1 et 20 caractéres composé des lettres et chiffres





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


//***********************archive****************************************

void login::on_pushButton_2_clicked()
{
    int id = ui->e_id->text().toInt();
    QString nom = ui->e_nom->text();
    QDateTime dateTime = ui->e_Date->dateTime();
    QString type = ui->e_type->text();
    QString version = ui->e_version->text();
    QDate convertedDate = dateTime.date(); // Get the date part


    Archive A;

    qDebug() << "Date String: " << dateTime;
    qDebug() << "Converted Date: " << convertedDate.toString("dd-MMM-yy");

    // Vérifier si un champ est vide
    if (nom.isEmpty() || type.isEmpty() || version.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Champs vides"),
            QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Cancel);
        return; // Ne pas continuer avec l'opération d'ajout
    }

    // Create Archive instance
    Archive C(id, nom, convertedDate, type, version);

    // Perform the addition
    bool test = C.ajouter();



    // Show the appropriate message
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Ajout effectué.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
            QObject::tr("Ajout non effectué.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

    // Clear the input fields
    ui->e_nom->clear();
    ui->e_Date->clear();
    ui->e_type->clear();
    ui->e_version->clear();

    // Refresh the displayed data
    setdata();
}

// Add comments and move setdata logic here if applicable
void login::setdata(){

    Archive a;
   ui->le_tab->setModel(a.Afficher());

}
void login::on_bouton_supp_clicked() {
    QString idStr = ui->e_id->text(); // Get the text from le_id_supp

    bool ok; // Used to check if conversion to int was successful
    int id = idStr.toInt(&ok);

    if (ok) {
        Archive archive; // Create an instance of your Archive class
        if (archive.supprimer(id)) {
            // The record was deleted successfully
            QMessageBox::information(this, tr("Success"), tr("The record was deleted successfully."), QMessageBox::Ok);
            // You can add more handling code here if needed
        } else {
            // There was an error during the deletion
            QMessageBox::warning(this, tr("Error"), tr("An error occurred while deleting the record."), QMessageBox::Ok);
            // You can add more handling code here if needed
        }
    } else {
        // The entered ID is not a valid integer
        QMessageBox::warning(this, tr("Invalid ID"), tr("Please enter a valid integer ID."), QMessageBox::Ok);
        // You can add more handling code here if needed
    }

    setdata();

}




void login::on_pushButton_3_clicked()
{
    int id = ui->e_id->text().toInt(); // Retrieve the ID from the QLineEdit

       if (id != 0) { // Check if a valid ID is entered
           QString nom = ui->e_nom->text();
           QDateTime dateTime = ui->e_Date->dateTime(); // Retrieve selected date and time
           QString type = ui->e_type->text();
           QString version = ui->e_version->text();
           QDate convertedDate = dateTime.date(); // Get the date part

           qDebug() << "Date String: " << dateTime;
           qDebug() << "Converted Date: " << convertedDate.toString("dd-MMM-yy");

           Archive a;


           bool success = a.update(id, nom, convertedDate, type, version);

           if (success) {
               QMessageBox::information(this, "Success", "Update successful!");
           } else {
               QMessageBox::critical(this, "Error", "Update failed!");
           }
       } else {
           QMessageBox::warning(this, "Warning", "Please enter a valid ID.");
       }

       setdata();
}




// methode recherche multi
void login::on_searchButton_clicked()
{
   Archive a;
  QString rech=ui->lineEdit->text();
  ui->le_tab->setModel(a.MultiSearch(rech));


}






void login::on_ImportButton_clicked() {

    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier", "", "Tous les fichiers (*.*)");
    if (!filePath.isEmpty()) {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        if(fileName==""){
            QMessageBox::information (nullptr, QObject::tr("Not OK"),
                                       QObject::tr("Valier sélectionner un fichier \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }else{QSqlQuery query;

            query.prepare("INSERT INTO FICHIER (NOM,CHEMIN) VALUES (:NOM, :CHEMIN)");
            query.bindValue(":NOM", fileName);
            query.bindValue(":CHEMIN", filePath);
            bool reqett=query.exec();
            if(reqett){
          QMessageBox::information (nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
          QMessageBox::information (nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Ajout non effectué \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}


}
}
void login::on_historique_clicked()
{
    Archive *archive = new Archive();


            archive->afficherHistorique();

}

void login::on_id_clicked()
{
    Archive a;
    ui->le_tab->setModel(a.tri_ID());
}






void login::on_statistique_clicked()
{
    Archive a;
    QSqlQueryModel *model = a.Afficher();

    if (!model) {
        qDebug() << "Error: QSqlQueryModel is null.";
        return;
    }

    int total = model->rowCount();
    int pdfCount = 0;
    int excelCount = 0;

    // Assuming an attribute in the archive class
    int typeIndex = model->record().indexOf("TYPE");

    // Count PDF and Excel files
    for (int row = 0; row < total; ++row) {
        QString fileType = model->data(model->index(row, typeIndex)).toString().toLower();
        if (fileType == "pdf") {
            pdfCount++;
        } else if (fileType == "excel") {
            excelCount++;
        }
    }

    // Calculate percentages
    double pdfPercentage = (total > 0) ? ((double)pdfCount / total) * 100 : 0;
    double excelPercentage = (total > 0) ? ((double)excelCount / total) * 100 : 0;

    // Create QPieSeries
    QPieSeries *series = new QPieSeries();

    // Add slices
    if (pdfPercentage > 0) {
        QPieSlice *slicePdf = new QPieSlice("PDF", pdfPercentage);
        slicePdf->setColor(QColor("violet"));
        series->append(slicePdf);
    }

    if (excelPercentage > 0) {
        QPieSlice *sliceExcel = new QPieSlice("EXCEL", excelPercentage);
        sliceExcel->setColor(QColor("lightblue"));
        series->append(sliceExcel);
    }

    // Create QChart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique PDF, EXCEL");

    // Customize legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Create QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create QDialog
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setFixedSize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);

    // Close button
    QPushButton *closeButton = new QPushButton("Fermer", chartDialog);
    connect(closeButton, &QPushButton::clicked, chartDialog, &QDialog::close);
    layout->addWidget(closeButton);

    // Display the window
    chartDialog->exec();

    // Deallocate memory
    delete chartDialog;
}
void login::on_PDF_clicked()
{
    QString nomFichierPDF = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "Fichiers PDF (*.pdf)");

            if (!nomFichierPDF.isEmpty()) {
                QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->le_tab->model());

                if (model) {
                    GenerateurPDF::genererPDF(model, nomFichierPDF);
                } else {
                    QMessageBox::warning(this, "Erreur", "Le modèle n'est pas de type QSqlQueryModel.");
                }
            }
}

void login::on_arduino_clicked()
{
    // Simulate movement detection
       bool movementDetected = true; // Replace this with actual logic

       if (movementDetected) {
           // Get current time
           QDateTime currentDateTime = QDateTime::currentDateTime();
           QString currentTime = currentDateTime.toString("yyyy-MM-dd HH:mm");  // Adjusted the format

           // Save the time to the database
           QSqlQuery query;
           query.prepare("INSERT INTO ButtonClicks (ClickTime) VALUES (TO_DATE(:time, 'YYYY-MM-DD HH24:MI'))");
           query.bindValue(":time", currentTime);

           if (!query.exec()) {
               qDebug() << "Error: Failed to insert button click time into the database.";
               qDebug() << "Query error: " << query.lastError().text();
           }

           // Display the time on the label
           ui->labelTime->setText("Movement Detected at " + currentTime);
       }
}






