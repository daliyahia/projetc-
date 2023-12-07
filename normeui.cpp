#include "normeui.h"
#include "ui_normeui.h"
#include "norme.h"
#include <QtCharts/QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>


normeui::normeui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::normeui)
{
    ui->setupUi(this);
}

normeui::~normeui()
{
    delete ui;
}

QString normeui::generateChatbotReply(const QString& message)
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

int normeui::checkCondition(const QString& lowercaseMessage)
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

void normeui::on_SendButton_normes_clicked()
{
    sendMessage();
}

void normeui::sendMessage()
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

void normeui::fetchTriviaQuestion(const QString& apiUrl)
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


void normeui::on_btn_ajouter_normes_clicked()
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

void normeui::on_supprimernormes_clicked()
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

void normeui::on_tableViewnormes_clicked(const QModelIndex &index)
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
void normeui::on_btn_modifier_normes_clicked()
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


void normeui::on_tri_normes_currentIndexChanged(const QString &arg1)
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



void normeui::on_rechercher_normes_textChanged(const QString &arg1)
{
    if(arg1!="")
        ui->tableViewnormes->setModel(etmp2.rechercherNorme(arg1));
        else
            ui->tableViewnormes->setModel(etmp2.rechercherNorme(arg1));
}

void normeui::on_PDF_normes_clicked()
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



void normeui::statistiqueNorme()
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

void normeui::on_statnormes_clicked()
{
    statistiqueNorme();
    ui->tabWidget->setCurrentIndex(4);

}




void normeui::on_apprendre_normes_clicked()
{

    QSqlQuery query;
   QString mot = ui->messageTextEdit_2->toPlainText();
    query.prepare("INSERT INTO dictionnaire (mot) VALUES (:mot)");
    query.bindValue(":mot",mot);
    query.exec();

}

void normeui::on_pushButton_video_2_clicked()
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
