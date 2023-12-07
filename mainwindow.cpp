/***********************************dali***************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
#include "norme.h"

/*****************************************ysmine*******************************/

/****************amal********************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audits.h"
#include <QMessageBox>
#include <QtDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QMessageBox>
#include <QIntValidator>
#include <QObject>
#include <QtDebug>
#include <QTabWidget>
#include<QSqlQuery>
#include <QDate>
#include <QDateEdit>
#include <QSqlTableModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QTextDocument>
//
#include <QDesktopServices>
#include <QTextDocument>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>


#include <QPainter>
#include <QDebug>



#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPainter>
#include <QApplication>
#include <QTextBrowser>
#include <QtCharts/QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include<QSqlRecord>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QSqlQueryModel>
#include <QDebug>
#include "calendrier.h"
#include <QDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>



#include <QPdfWriter>
#include <QPainter>
//**************************************************
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
//********************************************
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entreprise.h"
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


using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
     break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
   case(-1):qDebug() << "arduino is not available";
}
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(message()));

     ui->tableView->setModel(etmp.afficher());
     ui->Line_Edit_quantite->setValidator(new QIntValidator(0,9999,this));//cs
      ui->numero->setValidator(new QIntValidator(0,99999999,this));//cs
     QRegularExpressionValidator *stringValidator = new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this);
     ui->Line_Edit_nom->setValidator(stringValidator);

     ui->la_id->setValidator( new QIntValidator(0, 9999, this));

     ui->tab_employer->setModel(Et.afficher());
     //************************************************
     selectedId = -1;
     etatformulaire = "add";
     endusavec = 0;


     // controle de saisie sur les champs


     ui->e_id->setValidator(new QIntValidator(0,9999999,this)) ;
     ui->e_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,20}"), this)); // les lettre seulement  entre 1 et 20
     ui->e_type->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,20}"), this)); // les lettre seulement  entre 1 et 20
     ui->e_version->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_]{1,20}"), this)); // version accepter entre 1 et 20 caractéres composé des lettres et chiffres

//*****************************************
     ui->id_entreprise->setValidator (nullptr);
     // Populate the domain combo box
         ui->domaine_entreprise->addItem("Alimentaire");
         ui->domaine_entreprise->addItem("Automobile");
         ui->domaine_entreprise->addItem("Sport");
         ui->domaine_entreprise->addItem("Technology");

     ui->tab_entreprise->setModel(e.afficher());
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




void MainWindow::on_btn_ajouter_clicked()
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

void MainWindow::on_btn_supprimer_clicked()
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

void MainWindow::on_tableView_clicked(const QModelIndex &index)
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


void MainWindow::on_trimatrielsComboBox_currentIndexChanged(const QString &arg1)
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

void MainWindow::on_rechercheBar_textChanged(const QString &arg1)
{
    if(arg1!="")
    ui->tableView->setModel(etmp.recherchermatriels(arg1));
    else
        ui->tableView->setModel(etmp.recherchermatriels(arg1));}


void MainWindow::on_PDF_clicked()
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




void MainWindow::statmatriels()
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
void MainWindow::on_statistique_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    ui->tabWidget->setCurrentIndex(4);
    statmatriels();
}



void MainWindow::on_pushButton_call_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    QByteArray num=ui->numero->text().toUtf8();
        qDebug()<<num<<endl;
        A.write_to_arduino(num);
}


QString test;
void MainWindow::message()
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
}

void MainWindow::on_excel_clicked()
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

void MainWindow::on_clear_clicked()
{
    QSound *sound = new QSound("C:/Users/victo/OneDrive/Documents/Gestion_matriels/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();
    ui->Line_Edit_referance->clear();
    ui->Line_Edit_nom->clear();
  //  ui->comboBox_etat->clear();
    ui->Line_Edit_quantite->clear();

}
/********************************************************yesmine**********************************************/
QString MainWindow::generateChatbotReply(const QString& message)
{
    QString replyMessage;
    QString lowercaseMessage = message.toLower();

    switch (checkCondition(lowercaseMessage))
    {
        case 1:  // Audit
            replyMessage = "\n Les audits internes, parfois appeles audits de premiere partie, sont realises par, ou pour le compte de l’organisme lui-meme."
                           "Les audits externes comprennent les audits appeles audits de seconde et de tierce partie. ";
            break;

        case 2:  // Principe 9001
            replyMessage = "Orientation client, Responsabilite de la direction, Implication du personnel, Approche processus, Amélioration, Prise de decision fondee sur des preuves, Management des relations avec les parties interessées";
            break;

        case 3:  // Principe 19011
            replyMessage = "1- \nDeontologie: le fondement du professionnalisme,\n"
                           "2- Restitution impartiale: l’obligation de rendre compte de maniere sincere et precise,\n"
                           "3- Conscience professionnelle: l’attitude diligente et avisee au cours de l’audit,\n"
                           "4- Confidentialite: securite des informations,\n"
                           "5- Indépendance: le fondement de l’impartialite de l’audit et de l’objectivite des conclusions d’audit,\n"
                           "6- Approche fondée sur la preuve,\n"
                           "7- Approche par les risques: approche d’audit prenant en consideration les risques et les opportunites\n";
            break;

        case 4:  // Principe 14001
            replyMessage = "\n Les principes de la norme ISO 14001 comprennent :\n"
                           "1- Engagement de la direction,\n"
                           "2- Politique environnementale,\n"
                           "3- Planification,\n"
                           "4- Mise en œuvre et fonctionnement,\n"
                           "5- Surveillance et mesure,\n"
                           "6- Évaluation de la performance,\n"
                           "7- Revue de direction";
            break;

        default:  // Default
            replyMessage = "|I didn't quite understand. Can you please rephrase your message?";
            break;
    }

    return replyMessage;
}

int MainWindow::checkCondition(const QString& lowercaseMessage)
{     // Vérifie la condition à chaque réponse possible

    if (lowercaseMessage.contains("audit"))
        return 1;
    else if (lowercaseMessage.contains("principe 9001"))
        return 2;
    else if (lowercaseMessage.contains("principe 19011"))
        return 3;
    else if (lowercaseMessage.contains("principe 14001"))
        return 4;
    else if (lowercaseMessage.contains("ok"))
        return 5;
    else
        return 0;
}

void MainWindow::on_SendButton_normes_clicked()
{
    sendMessage();
}

void MainWindow::sendMessage()
{   // Récupère le message entré par l'utilisateur
    QString message = ui->messageTextEdit_2->toPlainText();

    message = message.trimmed();

    // Vérifie si le message est vide
    if (message.isEmpty())
    {
        ui->messageTextEdit_2->clear();
        return;
    }

    ui->chatDisplayTextEdit_2->append("Question: " + message); //afficher dans le widget de l'historique

    ui->messageTextEdit_2->clear();

    if (m_currentQuestion.isValid && !m_currentQuestion.options.isEmpty())
    {
       // Vérifie la validité de la réponse fournie par l'utilisateur
        bool isValidAnswer = false;
        int selectedOption = message.toInt(&isValidAnswer);

        if (isValidAnswer && selectedOption >= 1 && selectedOption <= m_currentQuestion.options.size())
        {
            QString userAnswer = m_currentQuestion.options[selectedOption - 1];

            if (userAnswer == m_currentQuestion.correctAnswer)
            {
                ui->chatDisplayTextEdit_2->append("Chatbot: Correct answer!");
            }
            else
            {
                ui->chatDisplayTextEdit_2->append("Chatbot: Incorrect answer. The correct answer is: " + m_currentQuestion.correctAnswer);
            }
        }
        else
        {
            ui->chatDisplayTextEdit_2->append("Chatbot: Invalid answer. Please provide a valid option number.");
        }

        m_currentQuestion.clear(); // Clear the current question for the next quiz
    }
    else
    {
        QString reply = generateChatbotReply(message);
        if (!reply.isEmpty())
        {
            ui->chatDisplayTextEdit_2->append("Chatbot: " + reply);
        }
    }
}

// ...

void MainWindow::fetchTriviaQuestion(const QString& apiUrl)
{
    QNetworkRequest request;

    request.setUrl(QUrl(apiUrl));

    QNetworkReply* reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, [=]() {

        if (reply->error() == QNetworkReply::NoError) {

            QByteArray response = reply->readAll();
            //reponse

           QJsonDocument jsonDoc(QJsonDocument::fromJson(response));//analyse les données brutes

           QJsonObject jsonObject = jsonDoc.object();

           QJsonArray results = jsonObject["results"].toArray();
            if (!results.isEmpty()) {
                QJsonObject triviaQuestion = results[0].toObject();
                m_currentQuestion.question = triviaQuestion["question"].toString();
                m_currentQuestion.correctAnswer = triviaQuestion["correct_answer"].toString();
                QJsonArray incorrectAnswers = triviaQuestion["incorrect_answers"].toArray();
                for (const QJsonValue& value : incorrectAnswers)
                {
                    m_currentQuestion.options.append(value.toString());
                }

                // Add the correct answer to the options list
                m_currentQuestion.options.append(m_currentQuestion.correctAnswer);

                // Shuffle the options to randomize their order
                std::random_device rd;
                std::mt19937 gen(rd());
                std::shuffle(m_currentQuestion.options.begin(), m_currentQuestion.options.end(), gen);


                ui->chatDisplayTextEdit_2->append("Chatbot: " + m_currentQuestion.question);

                for (int i = 0; i < m_currentQuestion.options.size(); ++i)
                {
                    QString optionNumber = QString::number(i + 1);
                    QString optionText = m_currentQuestion.options[i];
                    ui->chatDisplayTextEdit_2->append(optionNumber + ". " + optionText);
                }

                m_currentQuestion.isValid = true;
            }
            else {
                ui->chatDisplayTextEdit_2->append("Chatbot: Sorry, I couldn't fetch a trivia question.");
            }
        } else {
            QString error = reply->errorString();
            qDebug() << "Network error:" << error;
            ui->chatDisplayTextEdit_2->append("Chatbot: Sorry, I couldn't fetch a trivia question. Error: " + error);
        }
        reply->deleteLater();
    });
}

// ...


void MainWindow::on_btn_ajouter_normes_clicked()
{
    QSound *sound = new QSound("C:/Users/Yassmine/Documents/ProjetCpp/media/button.wav"); // Replace "click.wav" with the actual sound file path
           sound->play();
    QString id_n=ui->Line_Edit_id_n_2->text();
   QString version =ui->comboBox_version_2->currentText();
   QString principe =ui->Line_Edit_principe_2->text();
   QString objectifs =ui->Line_Edit_objectifs_2->text();
 norme  n(id_n,version,principe,objectifs);
bool test=n.ajouter();
if (test)
{
    ui->tableViewnormes->setModel(etmp2.afficher());//afichage

   /* QMessageBox::information(nullptr, QObject::tr("add"),
               QObject::tr(" successful.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);*/


    ui->Line_Edit_id_n_2->clear();
    ui->comboBox_version_2->clear();
    ui->Line_Edit_principe_2->clear();
    ui->Line_Edit_objectifs_2->clear();


}
/*else{
    QMessageBox::critical(nullptr, QObject::tr("add"),
                QObject::tr(" failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}*/

}

void MainWindow::on_supprimernormes_clicked()
{
    int i;
    QModelIndex index=ui->tableViewnormes->currentIndex();
     i=index.row();
    QModelIndex in=index.sibling(i,0);

    QString val=ui->tableViewnormes->model()->data(in).toString();
    //int id=ui->lineEdit_idsup->text().toInt();
    bool test=etmp2.supprimer(val);
    if (test)
    {
        ui->tableViewnormes->setModel(etmp2.afficher());
}
}

void MainWindow::on_tableViewnormes_clicked(const QModelIndex &index)
{
    int i;
       i=index.row();
      QModelIndex in=index.sibling(i,0);
      QString val=ui->tableViewnormes->model()->data(in).toString();


       QSqlQuery qry;
       qry.prepare("select id_n,version,principe,objectifs from norme where id_n='"+val+"' " );


       if(qry.exec())
       {
           while(qry.next())
           {
               ui->Line_Edit_id_n_2->setText(qry.value(0).toString());
               ui->comboBox_version_2->setCurrentText(qry.value(1).toString());
               ui->Line_Edit_principe_2->setText(qry.value(2).toString());
               ui->Line_Edit_objectifs_2->setText(qry.value(3).toString());
}
}
}
void MainWindow::on_btn_modifier_normes_clicked()
{
    QString id_n=ui->Line_Edit_id_n_2->text();
    QString version =ui->comboBox_version_2->currentText();
    QString principe=ui->Line_Edit_principe_2->text();
    QString objectifs=ui->Line_Edit_objectifs_2->text();
    norme n(id_n,version,principe,objectifs);
     bool test=n.modifier(id_n);
       ui->tableViewnormes->setModel(etmp2.afficher());
     /* if(test){
          QMessageBox::information(nullptr, QObject::tr("update"),
                QObject::tr(" successful.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);

}
      else
      {
     QMessageBox::critical(nullptr, QObject::tr("update"),
                 QObject::tr(" failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
     }*/
}


void MainWindow::on_tri_normes_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "par défaut")
        {
           ui->tableViewnormes->setModel( etmp2.triNorme(arg1));
        }
        else if(arg1 == "id_n")
        {
            ui->tableViewnormes->setModel(etmp2.triNorme(arg1));
        }
        else if(arg1 == "version")
        {
            ui->tableViewnormes->setModel(etmp2.triNorme(arg1));
        }
        else
        {
            ui->tableViewnormes->setModel(etmp2.triNorme(arg1));
        }
}



void MainWindow::on_rechercher_normes_textChanged(const QString &arg1)
{
    if(arg1!="")
        ui->tableViewnormes->setModel(etmp2.rechercherNorme(arg1));
        else
            ui->tableViewnormes->setModel(etmp2.rechercherNorme(arg1));
}

void MainWindow::on_PDF_normes_clicked()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation );
            filePath = QDir(filePath).filePath("ProjetCpp/listeNorme.pdf");// stocker du chemin du fichier


            QPdfWriter pdf(filePath);    //objet utilisé pour créer le fichier PDF

               QPainter painter(&pdf);// pour dessiner le pdf
               int i = 4100;

                      QColor dateColor(0x4a5bcf);// dessin des informations d'en_tete
                      painter.setPen(dateColor);

                      painter.setFont(QFont("Montserrat SemiBold", 11));
                      QDate cd = QDate::currentDate();
                      painter.drawText(8400,250,cd.toString("Tunis"));   // dessin des informations de date
                      painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                      QColor titleColor(0x341763);
                      painter.setPen(titleColor);
                      painter.setFont(QFont("Montserrat SemiBold", 25));

                      painter.drawText(3000,2700,"Liste des Normes");// dessin de titre en haut du PDF :

                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Time New Roman", 15));  // dessin de l'en_ tete du tableau
                      painter.drawRect(100,3300,9400,500);

                      painter.setFont(QFont("Montserrat SemiBold", 10));

                      painter.drawText(500,3600,"id_n");
                      painter.drawText(2000,3600,"version");
                      painter.drawText(3300,3600,"principe");
                      painter.drawText(7500,3600,"objectifs");
                      painter.setFont(QFont("Mime New Roman", 10));
                      painter.drawRect(100,3300,9400,9000);
//exécute une requête SQL pour sélectionner tous les enregistrements de la table "norme".
//Pour chaque enregistrement, il dessine une ligne horizontale et les valeurs des champs dans les colonnes correspondantes
                      QSqlQuery query;
                      query.prepare("select * from norme");
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



void MainWindow::statistiqueNorme()
{
    QLayout* layoutTest = ui->statistique_normes->layout();// verifier layout dans le widget interface de statistique
        if (layoutTest) {
            delete layoutTest;
}

        QVector<int> stat = etmp2.statNorme(); // Obtient les statistiques des normes

         // Crée un ensemble de barres et remplit avec les statistiques
        QBarSet *set = new QBarSet("version");
        for(int i=0; i <stat.size(); i++)
        {
            * set << stat[i];
        }
        // Crée une série de barres et y ajoute l'ensemble de barres
        QBarSeries *series = new QBarSeries();
        series->append(set);

        // Crée un objet QChart et y ajoute la série de barres
        QChart *chart = new QChart();
        chart->addSeries(series); // Ajoute la série de barres au graphique.
        chart->setTitle("statistique");
        chart->setAnimationOptions(QChart::AllAnimations);//activer
        QStringList list;
            list << "2015" << "2018";
        QValueAxis *axisY = new QValueAxis();
        chart->setAxisY(axisY,series);
//         chart->setAxisY(axisY, s eries);
        QBarCategoryAxis *axisX = new QBarCategoryAxis();

        axisX->append(list); //Ajoute les années à l'axe de catégories.
        chart->createDefaultAxes();
        chart->setAxisX(axisX,series);
       //chart->setAxisX(axisX, series);

        QPalette pal = qApp->palette();
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
        qApp->setPalette(pal);  //Applique la palette à l'application.
        QChartView * chartView= new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); //rendre le graphique plus lisse
        chartView->setMinimumSize(801,311);
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        ui->statistique_normes->setLayout(layout);


}




/*void MainWindow::on_pushButton_clicked()
{
    Dialogvideo d;
    d.exec();
}*/

void MainWindow::on_statnormes_clicked()
{
    statistiqueNorme();
    ui->tabWidget->setCurrentIndex(4);

}




void MainWindow::on_apprendre_normes_clicked()
{

    QSqlQuery query;
   QString mot = ui->messageTextEdit_2->toPlainText();
    query.prepare("INSERT INTO dictionnaire (mot) VALUES (:mot)");
    query.bindValue(":mot",mot);
    query.exec();

}

void MainWindow::on_pushButton_video_2_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File "),"", tr("MP4 File (*MP4)"));
     QMediaPlayer *player = new QMediaPlayer();
     QVideoWidget * video = new QVideoWidget();

     video->setGeometry(20, 20, 600, 380);

     player ->setVideoOutput(video);
     player->setMedia(QUrl (FileName));
     video ->show();
     player-> play ();
}
/*********************amal**************************************************/
void MainWindow::on_pb_ajouter_clicked()
{
  qDebug() << "Setting background color to magenta.";
    ui->table_checklist->repaint();
    ui->table_checklist_2->repaint();

    ui->table_checklist_3->repaint();
    ui->table_checklist->setAutoFillBackground(true);
    ui->table_checklist_2->setAutoFillBackground(true);
     ui->table_checklist_3->setAutoFillBackground(true);
    qDebug() << "Setting background color to magenta.";
    ui->table_checklist->repaint();
    ui->table_checklist->setAutoFillBackground(true);
    ui->table_checklist_2->repaint();
    ui->table_checklist_2->setAutoFillBackground(true);
    ui->table_checklist_3->repaint();
    ui->table_checklist_3->setAutoFillBackground(true);
    int NUM_D = ui->le_numd->text().toInt();
       QString ACTION = ui->le_action->currentText();
       QString DATE_AUDIT = ui->la_date->text();

       // Utilisez qDebug() pour imprimer la valeur d'action dans la console de débogage
       qDebug() << "Action: " << ACTION;


       AUDITS A(NUM_D, ACTION, DATE_AUDIT);

       // Ajouter les données à la base de données
       bool insertionSuccess = A.ajouter();

       // Mettre à jour le modèle de la table avec les données nouvellement ajoutées
       ui->table_audits->setModel(A.afficher());
       QPalette palette = ui->table_checklist->palette();
       QPalette palette_2 = ui->table_checklist_2->palette();
       QPalette palette_3= ui->table_checklist_3->palette();
       palette.setColor(QPalette::Background, Qt::magenta);
       palette_2.setColor(QPalette::Background, Qt::magenta);
       palette_3.setColor(QPalette::Background, Qt::magenta);
       ui->table_checklist->setAutoFillBackground(true);
       ui->table_checklist->setPalette(palette);
       ui->table_checklist->setVisible(true);
       ui->table_checklist_2->setAutoFillBackground(true);
       ui->table_checklist_2->setPalette(palette_2);
       ui->table_checklist_2->setVisible(true);
       ui->table_checklist_3->setAutoFillBackground(true);
       ui->table_checklist_3->setPalette(palette_3);
       ui->table_checklist_3->setVisible(true);
       if (ACTION.toLower() == "conformer") {
           ui->table_checklist->setStyleSheet("background-color:magenta;");
           ui->table_checklist_3->setStyleSheet("background-color: magenta;");
       } else {
           // Rétablir la couleur par défaut si nécessaire
           ui->table_checklist->setStyleSheet(""); // Cela réinitialise la feuille de style
       }
       if (ACTION.toLower() == "criditation") {
           ui->table_checklist_2->setStyleSheet("background-color:magenta;");
           ui->table_checklist->setStyleSheet("background-color: magenta;");
           ui->table_checklist_3->setStyleSheet("background-color:magenta;");
       } else {
           // Rétablir la couleur par défaut si nécessaire
           ui->table_checklist_2->setStyleSheet(""); // Cela réinitialise la feuille de style
           ui->table_checklist_3->setStyleSheet("background-color:magenta;");
       }
       if (ACTION.toLower() == "analyser") {
           ui->table_checklist_3->setStyleSheet("background-color: magenta;");
       } else {
           // Rétablir la couleur par défaut si nécessaire
          // ui->table_checklist_3->setStyleSheet(""); // Cela réinitialise la feuille de style
       }


       QMessageBox messageBox;

       if (insertionSuccess) {
          // messageBox.setText("Data added to the database successfully!");

           // Mettre à jour la couleur du table_checklist si l'action est conforme
           if (ACTION.toLower() == "conforme") {
               // Utilisez qDebug() pour imprimer un message dans la console de débogage
               qDebug() << "Setting background color to magenta.";
               if (ACTION.toLower() == "criditation") {

             if (ACTION.toLower() == "analyser"){
                  qDebug() << "Setting background color to magenta.";
                  // Utilisez qDebug() pour imprimer un message dans la console de débogage
                  qDebug() << "Setting background color to magenta.";
                 qDebug() << "Setting background color to magenta.";
                 qDebug() << "Setting background color to magenta.";
               // Créer une palette
               QPalette palette = ui->table_checklist->palette();
               QPalette palette_2 = ui->table_checklist_2->palette();
               QPalette palette_3 = ui->table_checklist_3->palette();
               // Définir la couleur d'arrière-plan en vert
               palette.setColor(QPalette::Background, Qt::magenta);
               palette_2.setColor(QPalette::Background, Qt::magenta);
               palette_3.setColor(QPalette::Background, Qt::magenta);
               // Activer l'arrière-plan automatique
               ui->table_checklist->setAutoFillBackground(true);
               ui->table_checklist_2->setAutoFillBackground(true);
               ui->table_checklist_3->setAutoFillBackground(true);
               // Appliquer la palette au widget
               ui->table_checklist_2->setPalette(palette);
              // ui->table_checklist_3->setPalette(palette);
           }
       } /*else {
           messageBox.setText("Failed to add data to the database.");
       }*/

      // messageBox.exec();
   }



}
}

void MainWindow::on_bt_supp_clicked()
{
   AUDITS A;
        int NUM_D_to_delete = ui->le_numd->text().toInt();
        bool test = A.supprimer(NUM_D_to_delete);
        if(test)
        {

            ui->table_audits->setModel(A.afficher());
           // QMessageBox::information(this,QObject::tr("ok"),
           // QObject::tr("suppression effectuée\nClick OK to exit."),QMessageBox::Ok);
        }

        /*else
        {
        QMessageBox::information(this, tr("Not OK"), tr("Deletion was not successful. Click OK to exit."), QMessageBox::Ok);
        }*/

}


void MainWindow::on_pushButton_2_clicked()
{

        int NUM_D = ui->le_numd->text().toInt();

        // Récupérer la valeur sélectionnée dans le QComboBox
        QString ACTION = ui->le_action->currentText();

        QString DATE_AUDIT = ui->la_date->text();

        // Créer un objet AUDITS avec les paramètres
        AUDITS A(NUM_D, ACTION, DATE_AUDIT);

        // Ajouter les données à la base de données
        bool insertionSuccess = A.ajouter();

        // Mettre à jour le modèle de la table avec les données nouvellement ajoutées
        ui->table_audits->setModel(A.afficher());
      //  QMessageBox messageBox;


       // if (insertionSuccess) {
         //   messageBox.setText("Data added to the database successfully!");
        //} else {
          //  messageBox.setText("Failed to add data to the database.");
       // }

       // messageBox.exec();
    }

void MainWindow::on_stat_clicked()
{


    QSqlQueryModel *model = Am.afficher();

        if (!model) {
            qDebug() << "Error: QSqlQueryModel is null.";
            return;
        }

        int totalEmployes = model->rowCount();
        int controlerCount = 0;
        int analyserCount = 0;
        int conformerCount = 0;
        int criditationCount = 0;

        // Assuming 'action' is an attribute in the employe class
        int actionColumnIndex = model->record().indexOf("action");

        // Count actions
        for (int row = 0; row < totalEmployes; ++row) {
            QString action = model->data(model->index(row, actionColumnIndex)).toString().toLower();
            if (action == "controler") {
                controlerCount++;
            } else if (action == "analyser") {
                analyserCount++;
            } else if (action == "conformer") {
                conformerCount++;
            } else if (action == "criditation") {
                criditationCount++;
            }
        }

        // Calculate percentages
        double pourcentageControler = (totalEmployes > 0) ? ((double)controlerCount / totalEmployes) * 100 : 0;
        double pourcentageAnalyser = (totalEmployes > 0) ? ((double)analyserCount / totalEmployes) * 100 : 0;
        double pourcentageConformer = (totalEmployes > 0) ? ((double)conformerCount / totalEmployes) * 100 : 0;
        double pourcentageCriditation = (totalEmployes > 0) ? ((double)criditationCount / totalEmployes) * 100 : 0;

        // Create QPieSeries
        QPieSeries *series = new QPieSeries();

        // Add slices
        if (pourcentageControler > 0) {
            QPieSlice *sliceControler = new QPieSlice(QString("Controler (%1%)").arg(pourcentageControler), pourcentageControler);
            sliceControler->setColor(QColor("lightblue")); // Change color to lightblue
            series->append(sliceControler);
        }

        if (pourcentageAnalyser > 0) {
            QPieSlice *sliceAnalyser = new QPieSlice(QString("Analyser (%1%)").arg(pourcentageAnalyser), pourcentageAnalyser);
            sliceAnalyser->setColor(QColor("lightgreen")); // Change color to lightgreen
            series->append(sliceAnalyser);
        }

        if (pourcentageConformer > 0) {
            QPieSlice *sliceConformer = new QPieSlice(QString("Conformer (%1%)").arg(pourcentageConformer), pourcentageConformer);
            sliceConformer->setColor(QColor("lightcoral")); // Change color to lightcoral
            series->append(sliceConformer);
        }

        if (pourcentageCriditation > 0) {
            QPieSlice *sliceCriditation = new QPieSlice(QString("Criditation (%1%)").arg(pourcentageCriditation), pourcentageCriditation);
            sliceCriditation->setColor(QColor("lightyellow")); // Change color to lightyellow
            series->append(sliceCriditation);
        }

        // Create QChart
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique ACTIONS");

        // Customize legend
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);

        // Create QChartView
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Add rotation animation
        QPropertyAnimation *animation = new QPropertyAnimation(series, "slicesAngle");
        animation->setStartValue(0.0);
        animation->setEndValue(360.0);
        animation->setDuration(2000); // Animation duration in milliseconds

        // Set chart animation
        chart->setAnimationOptions(QChart::AllAnimations);
        chartView->setChart(chart);

        // Create QDialog
        chartDialog = new QDialog(this);
        chartDialog->setFixedSize(1080, 720);
        QVBoxLayout *layout = new QVBoxLayout(chartDialog);
        layout->addWidget(chartView);

        // Close button
        QPushButton *closeButton = new QPushButton("Fermer", chartDialog);
        connect(closeButton, &QPushButton::clicked, chartDialog, &QDialog::accept);
        layout->addWidget(closeButton);

        // Display the window
        chartDialog->exec();
    }

void MainWindow::on_tri_clicked()
{
   AUDITS A;
     QSqlQueryModel * result =A.tri_NUM_D();
     ui->table_audits->setModel(result);
}

void MainWindow::on_tri_2_clicked()
{
    AUDITS A;
      QSqlQueryModel * result =A.tri_DATE_AUDIT();
      ui->table_audits->setModel(result);
}

void MainWindow::on_chercher_textChanged(const QString &arg1)
{
    if(arg1!="")
           ui->table_audits->setModel(Am.rechercherAUDITS(arg1));
           else
               ui->table_audits->setModel(Am.rechercherAUDITS(arg1));
}
void MainWindow::on_le_pdf_clicked()
{

        QPdfWriter pdf("C:/Users/hammemi/Downloads/AUDITS(1)/AUDITS/AUDITS.pdf");
        QPainter painter(&pdf);
        int i = 4000;

        painter.setPen(Qt::darkCyan);
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(3000, 1400, "AUDITS");

        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(100, 100, 9400, 2500);
        painter.drawRect(100, 3000, 9400, 500);
        painter.setFont(QFont("Time New Roman", 9));
        painter.drawText(4400, 3300, "NUM_D");
        painter.drawText(400, 3300, "ACTION");
        painter.drawText(1750, 3300, "DATE_AUDIT");

        painter.drawRect(100, 3000, 9400, 9000);

        QSqlQuery query;
        query.prepare("SELECT * FROM AUDITS");
        query.exec();
        while (query.next())
        {
            painter.drawText(1350, i, query.value("NUM_D").toString());
            painter.drawText(2300, i, query.value("ACTION").toString());
            painter.drawText(3400, i, query.value("DATE_AUDIT").toString());
            i = i + 350;
        }

       // QMessageBox::information(this, QObject::tr("PDF Saved Successfully!"),
         //                        QObject::tr("PDF Saved Successfully!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }

void MainWindow::on_BtnEnregistrer_clicked()

        {
            QString dir = "C:/Users/Amal/Downloads/ddd/AUDITS(1)/AUDITS/AUDITS.pro";
            QDir().mkpath(dir);
            QString fileName = dir + "/AUDITS.pdf";
            QPdfWriter pdf(fileName);
            QPainter painter(&pdf);
            int i = 4000;

            painter.drawPixmap(QRect(100, 100, 2000, 2000), QPixmap("C:/Users/msi/Downloads/logo_p.png"));

            painter.setPen(Qt::red);
            painter.setFont(QFont("Time New Roman", 25));
            painter.drawText(3000, 1450, "Liste des AUDITS");

            painter.setPen(Qt::black);
            painter.setFont(QFont("Time New Roman", 15));
            painter.drawRect(100, 100, 9400, 2500);
            painter.drawRect(100, 3000, 9400, 500);
            painter.setFont(QFont("Time New Roman", 10));
            painter.drawText(4400, 3300, "NUM_D");
            painter.drawText(400, 3300, "ACTION");
            painter.drawText(1350, 3300, "DATE_AUDIT");

            painter.drawRect(100, 3000, 9400, 10700);

            QSqlQuery query;
            query.prepare("SELECT NUM_D, ACTION, DATE_AUDIT FROM AUDITS");
            query.exec();
            while (query.next())
            {
                painter.drawText(300, i, query.value("NUM_D").toString());
                painter.drawText(1500, i, query.value("ACTION").toString());
                painter.drawText(3000, i, query.value("DATE_AUDIT").toString());

                i = i + 500;
            }

            /*int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez-vous afficher le PDF ?",
                                                QMessageBox::Yes | QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir + "/AUDITS.pdf"));
            }*/

            painter.end();
        }



void MainWindow::on_calendarWidget_activated(const QDate &)
{


    QDate selectedDate = ui->calendarWidget->selectedDate();
       qDebug() << "Selected date: " << selectedDate.toString("yyyy-MM-dd");

       QSqlQuery query;
       query.prepare("SELECT * FROM AUDITS WHERE DATE_AUDIT = :date");
       query.bindValue(":date", selectedDate.toString("yyyy-MM-dd"));

       if (query.exec()) {
           qDebug() << "Query executed successfully.";

           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery(query);

           // Vous pouvez également définir des noms de colonnes plus conviviaux
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_D"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("ACTION"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_AUDIT"));

           ui->calendrier->setModel(model);
       } else {
           qDebug() << "Error in SQL query: " << query.lastError().text();
       }
   }
/**************************************************sabaa***********************************************************/

void MainWindow::on_Boutton_sup_clicked()
{
    Employer E1;
    E1.setid((ui->la_id->text().toInt()));
    bool test=E1.supprimer(E1.getid());
    ui->tab_employer->setModel(E.afficher());

   // QMessageBox msgBox;
   /* if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Suppression effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_employer->setModel(E.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("Suppression non  effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/
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
    float salaire=ui->la_salaire->text().toFloat();

   Employer E(id,nom,prenom,adresse,role,suivi,salaire);
   bool test=E.ajouter();
   ui->tab_employer->setModel(E.afficher());
   /*if(test)
   {

       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("Ajouter effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_employer->setModel(E.afficher());
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                   QObject::tr("Ajouter non  effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);*/


}

void MainWindow::on_Boutton_Modifier_clicked()
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
       ui->tab_employer->setModel(E1.afficher());


       /*if(test)
    {

                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("update successful.\n"
                                        "update effectuer."), QMessageBox::Cancel);
                ui->tab_employer->setModel(E1.afficher());



    }
            else

                QMessageBox::critical(nullptr, QObject::tr("nope"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
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



void MainWindow::on_Button_PDF_clicked()
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

void MainWindow::on_Button_statistique_clicked()
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

void MainWindow::on_Button_emp_mois_clicked()
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
        if (E.g  etrole() == UserRole::ADMIN) {
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






void MainWindow::on_pushButton_clicked()
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
//***********************************************************
void MainWindow::on_pushButton_ajouter_m_clicked()
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
void MainWindow::setdata(){

    Archive a;
   ui->le_tab->setModel(a.Afficher());

}
void MainWindow::on_bouton_supp_clicked() {
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




void MainWindow::on_pushButton__modifier_m_clicked()
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
void MainWindow::on_searchButton_clicked()
{
   Archive a;
  QString rech=ui->lineEdit->text();
  ui->le_tab->setModel(a.MultiSearch(rech));


}






void MainWindow::on_ImportButton_clicked() {

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
void MainWindow::on_historique_clicked()
{
    Archive *archive = new Archive();


            archive->afficherHistorique();

}

void MainWindow::on_id_clicked()
{
    Archive a;
    ui->le_tab->setModel(a.tri_ID());
}






void MainWindow::on_statistique_mariem_clicked()
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
void MainWindow::on_PDF_mariem_clicked()
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

void MainWindow::on_arduino_clicked()
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

//***************************************************************
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
       // QMessageBox::warning(this, "Numéro Invalide", "Entrer une valeur numérique valide pour le numéro.");
        return; // Stop the function if the number is missing
    }

    // Convert the number input to an integer
    int Numero = NumeroText.toInt();

    // Email validation using a regular expression
    QRegExp emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    if (!emailRegex.exactMatch(Adresse_mail))
    {
        // Notify the user about invalid email
     //   QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return; // Stop the function if the email is invalid
    }

    Entreprise e(Ide, Nom, Adresse, Adresse_mail, Numero, Domaine);
    bool test = e.ajouter();

    QMessageBox msgBox;
   /* if (test)
        msgBox.setText("Ajout avec succès.");
    else
        msgBox.setText("Échec d'ajout.");*/

    msgBox.exec();

    // Update the model after adding a new record
    ui->tab_entreprise->setModel(e.afficher());

}


void MainWindow::on_supprimer1_clicked()
{
    Entreprise e1;
    e1.setIde(ui->id_entreprise->text());

    bool test = e1.supprimer(e1.getIde());

    QMessageBox msgBox;
   /* if (test)
    {
        msgBox.setText("Suppression avec succès.");
    }
    else
    {
        msgBox.setText("Suppression échouée.");
    }*/

    // Update the model after deletion
    ui->tab_entreprise->setModel(e1.afficher());

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
        if (!e.idExists(IdeToModify))
        {
           // QMessageBox::warning(this, "ID Not Found", "ID pas trouvé.");
            return;
        }

        // Check if the number input is empty
       /* if (NumeroText.isEmpty() || !NumeroText.toInt())
        {
            // Notify the user about the missing number
            QMessageBox::warning(this, "Numéro Invalide", "Entrer une valeur numérique valide pour le numéro.");
            return; // Stop the function if the number is missing
        }*/

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
       /* if (updateSuccess)
            msgBox.setText("Modification réussie.");
        else
            msgBox.setText("Échec de la modification.");*/

        msgBox.exec();

        // Disable editing after modification
        ui->nom_entreprise->setReadOnly(true);
        ui->adresse_entreprise->setReadOnly(true);
        ui->adresse_mail_entreprise->setReadOnly(true);
        ui->numero_entreprise->setReadOnly(true);
        ui->domaine_entreprise->setEnabled(false);
        ui->id_entreprise->setReadOnly(false);

        // Update the model after modifying the data
        ui->tab_entreprise->setModel(e.afficher());
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
           // QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête: " + queryError.text());
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

          //  QMessageBox::information(this, "Impression réussie", "La liste des entreprises a été imprimée avec succès au format PDF.");
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
    //QMessageBox::information(this, "Email réussie", "Email envoyé.");
}









void MainWindow::on_stat_said_clicked()
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















void MainWindow::on_chercher_entreprise_clicked()
{
    QString nomCherche = ui->chercher_box->text();
    QString domaineFiltre = ui->chercher_domaine->currentText();

    QString queryStr2 = "SELECT * FROM ENTREPRISE WHERE nom LIKE '%" + nomCherche + "%'";

    // Ajoutez le filtre de domaine si un domaine est sélectionné
    /*if (domaineFiltre != "Tous les domaines") {
        queryStr += " AND domaine = '" + domaineFiltre + "'";
    }*/

    QSqlQueryModel* modelChercher = new QSqlQueryModel();
    modelChercher->setQuery(queryStr2);

    /*if (modelChercher->rowCount() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucune entreprise trouvée avec ce nom et ce domaine.");
    }*/

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
    /*if (modelChercher->rowCount() == 0) {
       QMessageBox::information(this, "Aucun résultat", "Aucune entreprise trouvée avec ce nom et ce domaine.");
    }*/

    // Update the view with the new search results
    ui->tab_entreprise->setModel(modelChercher);

}
