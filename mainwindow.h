#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**********************************************dali********************************************************************/
#include <QMainWindow>
#include "matriels.h"
#include <QPrinter>
#include <QPainter>
#include <QDate>
#include <QTextStream>
#include <QTextDocument>
#include "notification.h"
// Inclure le fichier d'en-tête pour la vue de graphique QtCharts
#include <QtCharts/QChartView>
// Inclure le fichier d'en-tête pour la série de diagramme circulaire QtCharts
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
// Inclure le fichier d'en-tête pour la gestion de la disposition horizontale
#include <QHBoxLayout>
#include <QtCharts/QLegend>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include "qrcode.h"
#include <QLayout>
#include <QVector>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include "arduino.h"
#include <QPalette>
/**************************************************************yesmine*****************************************************/
#include <QMainWindow>
#include"norme.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include<QtMultimedia>
#include<QtMultimediaWidgets>
#include<QTCore>
#include<QtWidgets>
#include<QtGui>

/*********************sabaa*******************************/
#include "employer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**********************************ddali*************************************************************/
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void statmatriels();
    /**************************yesmine**************************************************/
     void statistiqueNorme();
private slots:
/*******************************dali*************************************************/

    void on_btn_ajouter_clicked();

    void on_btn_supprimer_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_modifier_clicked();




    void on_trimatrielsComboBox_currentIndexChanged(const QString &arg1);

    void on_rechercheBar_textChanged(const QString &arg1);


    void on_PDF_clicked();




    void on_statistique_clicked();

    void on_pushButton_call_clicked();

    void message();

    void on_excel_clicked();

    void on_clear_clicked();
/***********************************************yesmine*************************************************/
   // void on_btn_modifier_clicked();

    void on_btn_ajouter_normes_clicked();

    void on_btn_modifier_normes_clicked();

    void on_tableViewnormes_clicked(const QModelIndex &index);

void on_supprimernormes_clicked();

    void on_tri_normes_currentIndexChanged(const QString &arg1);

    void on_rechercher_normes_textChanged(const QString &arg1);

    void on_PDF_normes_clicked();


    void on_statnormes_clicked();

    void sendMessage();
    void on_SendButton_normes_clicked();
    void fetchTriviaQuestion(const QString& apiUrl);
    int checkCondition(const QString& lowercaseMessage);

    void on_apprendre_normes_clicked();





    void on_pushButton_video_2_clicked();

/****************sabaa************************************************/
    void on_Boutton_sup_clicked();

    void on_Boutton_Ajouter_clicked();

    void on_Boutton_Modifier_clicked();

    void on_Boutton_tri_nom_clicked();

    void on_Boutton_tri_suivi_clicked();

    void on_Boutton_tri_ID_clicked();

    void on_Boutton_rechecher_clicked();

    void on_Button_statistique_clicked();

    void on_Button_PDF_clicked();

    void on_Button_emp_mois_clicked();

    void on_pushButton_clicked();

private:
    /****************************************dali****************************************************/
    Matriels etmp;
    Ui::MainWindow *ui;
     notification notif;
     Arduino A;

     QByteArray data;
     QString test1;
/***************************************yesmine**********************************************/
     QMediaPlayer *Player;
      QVideoWidget *Video;



      norme  etmp2;
   //  Ui::MainWindow *ui;
     QString generateChatbotReply(const QString& message);
     QString getRandomJoke();
     QString m_lastJoke;
     QNetworkAccessManager* networkManager;

     struct Question {
         QString question;
         QStringList options;
         QString correctAnswer;
         bool isValid;

         Question()
             : isValid(false) {}

         void clear()
         {
             question.clear();
             options.clear();
             correctAnswer.clear();
             isValid = false;
         }
     };

     Question m_currentQuestion;
      /*******************sabaa***************************************************/
      Employer E;
      Employer E1;
      Employer Et;
      Employer m;
};
#endif // MAINWINDOW_H
