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
//*********************************************************

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
