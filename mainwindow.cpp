#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entreprise.h"
#include <QMessageBox>
#include <QValidator>
#include <QString>
#include <QComboBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <memory>

#include <QSharedPointer>

#include <QMessageBox>
#include "smtp.h"
#include <QApplication>


#include <QtWidgets/QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino.h"



#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id_entreprise->setValidator (nullptr);
    // Populate the domain combo box
        ui->domaine_entreprise->addItem("Alimentaire");
        ui->domaine_entreprise->addItem("Automobile");
        ui->domaine_entreprise->addItem("Sport");
        ui->domaine_entreprise->addItem("Technology");

    ui->tab_entreprise->setModel(E.afficher());
    ui->chercher_domaine->addItem("Tous les domaines");
    ui->chercher_domaine->addItem("Alimentaire");
    ui->chercher_domaine->addItem("Automobile");
    ui->chercher_domaine->addItem("Sport");
    ui->chercher_domaine->addItem("Technology");



    resize(1680, 900);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btajouter_clicked()
{
    QString Ide = ui->id_entreprise->text();
    QString Nom = ui->nom_entreprise->text();
    QString Adresse = ui->adresse_entreprise->text();
    QString Adresse_mail = ui->adresse_mail_entreprise->text();
    QString NumeroText = ui->numero_entreprise->text();
    QString Domaine = ui->domaine_entreprise->currentText();
    // Check if the number input is empty
    if (NumeroText.isEmpty() || !NumeroText.toInt())
    {
        // Notify the user about the missing number
        QMessageBox::warning(this, "Numéro Invalide", "Entrer une valeur numérique valide pour le numéro.");
        return; // Stop the function if the number is missing
    }

    // Convert the number input to an integer
    int Numero = NumeroText.toInt();

    // Email validation using a regular expression
    QRegExp emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    if (!emailRegex.exactMatch(Adresse_mail))
    {
        // Notify the user about invalid email
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return; // Stop the function if the email is invalid
    }

    Entreprise E(Ide, Nom, Adresse, Adresse_mail, Numero, Domaine);
    bool test = E.ajouter();

    QMessageBox msgBox;
    if (test)
        msgBox.setText("Ajout avec succès.");
    else
        msgBox.setText("Échec d'ajout.");

    msgBox.exec();

    // Update the model after adding a new record
    ui->tab_entreprise->setModel(E.afficher());

}


void MainWindow::on_supprimer1_clicked()
{
    Entreprise E1;
    E1.setIde(ui->id_entreprise->text());

    bool test = E1.supprimer(E1.getIde());

    QMessageBox msgBox;
    if (test)
    {
        msgBox.setText("Suppression avec succès.");
    }
    else
    {
        msgBox.setText("Suppression échouée.");
    }

    // Update the model after deletion
    ui->tab_entreprise->setModel(E1.afficher());

    // Show the message box after updating the model
    msgBox.exec();
}



void MainWindow::on_valide_modif_clicked()
{
 QString IdeToModify = ui->id_entreprise->text();
    QString Ide = ui->id_entreprise->text();
        QString Nom = ui->nom_entreprise->text();
        QString Adresse = ui->adresse_entreprise->text();
        QString Adresse_mail = ui->adresse_mail_entreprise->text();
        QString NumeroText = ui->numero_entreprise->text();
        QString Domaine = ui->domaine_entreprise->currentText();
        // Check if the entered ID exists in the database
        if (!E.idExists(IdeToModify))
        {
            QMessageBox::warning(this, "ID Not Found", "ID pas trouvé.");
            return;
        }

        // Check if the number input is empty
        if (NumeroText.isEmpty() || !NumeroText.toInt())
        {
            // Notify the user about the missing number
            QMessageBox::warning(this, "Numéro Invalide", "Entrer une valeur numérique valide pour le numéro.");
            return; // Stop the function if the number is missing
        }

        // Convert the number input to an integer
        int Numero = NumeroText.toInt();

        // Email validation using a regular expression
        QRegExp emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
        if (!emailRegex.exactMatch(Adresse_mail))
        {
            // Notify the user about invalid email
            QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
            return; // Stop the function if the email is invalid
        }

        Entreprise modifiedData(Ide, Nom, Adresse, Adresse_mail, Numero, Domaine);

        // Update the data in the database
        bool updateSuccess = modifiedData.updateData();

        QMessageBox msgBox;
        if (updateSuccess)
            msgBox.setText("Modification réussie.");
        else
            msgBox.setText("Échec de la modification.");

        msgBox.exec();

        // Disable editing after modification
        ui->nom_entreprise->setReadOnly(true);
        ui->adresse_entreprise->setReadOnly(true);
        ui->adresse_mail_entreprise->setReadOnly(true);
        ui->numero_entreprise->setReadOnly(true);
        ui->domaine_entreprise->setEnabled(false);
        ui->id_entreprise->setReadOnly(false);

        // Update the model after modifying the data
        ui->tab_entreprise->setModel(E.afficher());
}

void MainWindow::on_chercher_clicked()
{
    QString nomCherche = ui->chercher_box->text();
        QString domaineFiltre = ui->chercher_domaine->currentText();

        QString queryStr = "SELECT * FROM ENTREPRISE WHERE nom LIKE '%" + nomCherche + "%'";

        // Ajoutez le filtre de domaine si un domaine est sélectionné
        if (domaineFiltre != "Tous les domaines") {
            queryStr += " AND domaine = '" + domaineFiltre + "'";
        }

        QSqlQueryModel* modelChercher = new QSqlQueryModel();
        modelChercher->setQuery(queryStr);

        if (modelChercher->rowCount() == 0) {
            QMessageBox::information(this, "Aucun résultat", "Aucune entreprise trouvée avec ce nom et ce domaine.");
        }

        ui->tab_entreprise->setModel(modelChercher);

}
void MainWindow::on_trier_clicked()
{
    // Retrieve the current search criteria
    QString nomCherche = ui->chercher_box->text();
    QString domaineFiltre = ui->chercher_domaine->currentText();

    // Construct the SQL query with the selected domain and order by "nom"
    QString queryStr = "SELECT * FROM ENTREPRISE WHERE 1=1"; // Dummy condition to always start with WHERE

    // Add the domain filter if a domain is selected
    if (domaineFiltre != "Tous les domaines") {
        queryStr += " AND domaine LIKE '%" + domaineFiltre + "%'";
    }

    // Add the search criteria if provided
    if (!nomCherche.isEmpty()) {
        queryStr += " AND nom LIKE '%" + nomCherche + "%'";
    }

    // Order the results by "nom" in ascending order
    queryStr += " ORDER BY nom ASC";

    // Create and execute the query
    QSqlQueryModel* modelChercher = new QSqlQueryModel();
    modelChercher->setQuery(queryStr);

    // Show a message if no results are found
    if (modelChercher->rowCount() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucune entreprise trouvée avec ce nom et ce domaine.");
    }

    // Update the view with the new search results
    ui->tab_entreprise->setModel(modelChercher);

}


void MainWindow::on_Imprimer_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", "C:/Users/aslemaa/Desktop/4/entreprise_projet/pdf imprimer", "Fichiers PDF (*.pdf)");

    if (!filePath.isEmpty()) {
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(filePath);

        QPainter painter(&printer);

        // Fetch data directly from the database
        QSqlQueryModel* model = new QSqlQueryModel();

        // Set up your query
        QSqlQuery query;
        query.prepare("SELECT ide, nom, addresse, email, numero, domaine FROM ENTREPRISE");

        // Execute the query
        if (!query.exec()) {
            // Handle the error
            QSqlError queryError = query.lastError();
            qDebug() << "Query failed:" << queryError.text();
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête: " + queryError.text());
        } else {
            qDebug() << "Query executed successfully";

            // Set the query result to the model
            model->setQuery(query);

            // Add content to the PDF
            int rowCount = model->rowCount();
            int colCount = model->columnCount();

            // Draw headers
            for (int col = 0; col < colCount; ++col) {
                QString header = model->headerData(col, Qt::Horizontal).toString();
                painter.drawText(col * 100, 16, header);
            }

            // Draw data
            for (int row = 0; row < rowCount; ++row) {
                for (int col = 0; col < colCount; ++col) {
                    QString data = model->index(row, col).data().toString();
                    painter.drawText(col * 100, (row + 2) * 16, data); // Adjusted the position of each column
                }
            }

            // Close the PDF file
            painter.end();

            QMessageBox::information(this, "Impression réussie", "La liste des entreprises a été imprimée avec succès au format PDF.");
        }
    }
}



void MainWindow::on_send_email_clicked()
{
    // Retrieve information from QLineEdit widgets
    QString emailAddress = ui->email->text();
    QString subject = ui->sujet->text();
    QString body = ui->objet->text();

    // Check for empty fields
    if (emailAddress.isEmpty() || subject.isEmpty() || body.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'envoyer l'email.");
        return;
    }

    // Create an instance of the Smtp class
    Smtp* smtp = new Smtp("said.doghri@esprit.tn", "221JMT7702", "smtp.gmail.com", 465);

    // Compose the email
    QStringList attachments;  // Add file paths if you have attachments

    // Set the sender and recipient email addresses
    QString senderEmail = "said.doghri@esprit.tn";  // Replace with your sender email
    QString senderName = "said";
    QString recipientEmail = emailAddress;
    QString recipientName = "entreprise";

    // Set the email subject and body
    QString emailSubject = subject;
    QString emailBody = body;

    // Connect the status signal to a lambda function
    connect(smtp, &Smtp::status, [this](QString status) {
        // Disconnect the status signal
        QObject::disconnect(sender(), SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    });

    // Send the email
    smtp->sendMail(senderEmail, recipientEmail, emailSubject, emailBody, attachments);
    QMessageBox::information(this, "Email réussie", "Email envoyé.");
}









void MainWindow::on_stat_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT COUNT(*) FROM ENTREPRISE WHERE domaine = 'Technology'");
    float id = model->data(model->index(0, 0)).toFloat();

    model->setQuery("SELECT COUNT(*) FROM ENTREPRISE WHERE domaine = 'Alimentaire'");
    float idd = model->data(model->index(0, 0)).toFloat();

    model->setQuery("SELECT COUNT(*) FROM ENTREPRISE WHERE domaine = 'Automobile'");
    float iddd = model->data(model->index(0, 0)).toFloat();



    model->setQuery("SELECT COUNT(*) FROM ENTREPRISE WHERE domaine = 'Sport'");
    float sport = model->data(model->index(0, 0)).toFloat();

        float total = id + idd + iddd+sport;

        QString a = QString("technology " + QString::number((id * 100) / total, 'f', 2) + "%");
        QString b = QString("alimentaire " + QString::number((idd * 100) / total, 'f', 2) + "%");
        QString c = QString("automobile " + QString::number((iddd * 100) / total, 'f', 2) + "%");


        QString f = QString("sport " + QString::number((sport * 100) / total, 'f', 2) + "%");
        // Create the pie chart series
        QPieSeries *series = new QPieSeries();

        // Append data and set custom colors for each slice
        QPieSlice *slice1 = series->append(a, id);
        slice1->setBrush(QColor("#3498db"));  // Set color for the first slice

        QPieSlice *slice2 = series->append(b, idd);
        slice2->setBrush(QColor("#2ecc71"));  // Set color for the second slice

        QPieSlice *slice3 = series->append(c, iddd);
        slice3->setBrush(QColor("#e74c3c"));  // Set color for the third slice


        QPieSlice *slice5 = series->append(f, sport);
        slice5->setBrush(QColor("#e74c3c"));  // Set color for the third slice

        // Set label visibility and appearance for the first slice
        if (id != 0) {
            slice1->setLabelVisible();
            slice1->setPen(QPen());
        }

        if (idd != 0) {
            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice2 = series->slices().at(1);
            //slice2->setExploded();
            slice2->setLabelVisible();
        }

        if (iddd != 0) {
            // Add labels to rest of slices
            QPieSlice *slice3 = series->slices().at(2);
            //slice3->setExploded();
            slice3->setLabelVisible();
        }

        if (sport != 0) {
            // Add labels to rest of slices
            QPieSlice *slice5 = series->slices().at(4);
            //slice3->setExploded();
            slice5->setLabelVisible();
        }

        // Create the chart widget
        QChart *chart = new QChart();

        // Add the series to the chart
        chart->addSeries(series);

        // Set the chart title and hide the legend
        chart->setTitle("Pourcentage Par Domaine :Nombre D'entreprises " + QString::number(total));
        chart->legend()->hide();

        // Create the chart view
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(651,341);
        chartView->show();


}



