#include "archiveui.h"
#include "ui_archiveui.h"
#include "archive.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "archive.h"
#include <QMessageBox>
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

archiveui::archiveui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::archiveui)
{
    ui->setupUi(this);
}

archiveui::~archiveui()
{
    delete ui;
}

void archiveui::on_pushButton_ajouter_m_clicked()
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
void archiveui::setdata(){

    Archive a;
   ui->le_tab->setModel(a.Afficher());

}
void archiveui::on_bouton_supp_clicked() {
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




void archiveui::on_pushButton__modifier_m_clicked()
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
void archiveui::on_searchButton_clicked()
{
   Archive a;
  QString rech=ui->lineEdit->text();
  ui->le_tab->setModel(a.MultiSearch(rech));


}






void archiveui::on_ImportButton_clicked() {

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
void archiveui::on_historique_clicked()
{
    Archive *archive = new Archive();


            archive->afficherHistorique();

}

void archiveui::on_id_clicked()
{
    Archive a;
    ui->le_tab->setModel(a.tri_ID());
}






void archiveui::on_statistique_mariem_clicked()
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
void archiveui::on_PDF_mariem_clicked()
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

void archiveui::on_arduino_clicked()
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

