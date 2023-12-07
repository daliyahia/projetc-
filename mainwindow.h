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
/*********************amal*********************************************************/
#include <QMainWindow>
#include "audits.h"
#include "calendrier.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
/****************************************************/
#include <QMainWindow>
#include <archive.h>
#include <QFileDialog>
#include "employer.h"
//*****************************************
#include "entreprise.h"
#include <QMainWindow>
#include <QComboBox>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSortFilterProxyModel>

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
/******************************amal****************************************************/
     void setdata();
     void remplirListeArchive();
     //*******************************************
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
/*****************amal************************************/
    void on_pb_ajouter_clicked();



    void on_bt_supp_clicked();



    void on_pushButton_2_clicked();

    void on_stat_clicked();

    void on_tri_clicked();

    void on_tri_2_clicked();

    void on_chercher_textChanged(const QString &arg1);

   // void on_cherch_clicked();



    void on_BtnEnregistrer_clicked();

    void on_le_pdf_clicked();



    void on_calendarWidget_activated(const QDate &date);
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
    //********************************************
    void on_pushButton_ajouter_m_clicked();
    void on_bouton_supp_clicked();

    void on_pushButton_3_clicked();

    void on_searchButton_clicked();

    void on_ImportButton_clicked();

    void on_historique_clicked();

    void on_id_clicked();


    void on_statistique_mariem_clicked();

    void on_PDF_mariem_clicked();

    void on_arduino_clicked();

    void on_e_idE_cursorPositionChanged(int arg1, int arg2);

    void on_e_id_cursorPositionChanged(int arg1, int arg2);




    void on_pushButton_4_clicked();

    void on_pushButton__modifier_m_clicked();

    //void on_pushButton_ajouter_m_clicked();

    //void on_statistique_mariem_clicked();

   // void on_PDF_mariem_clicked();
 //******************************************************
    void on_btajouter_clicked();



    void on_supprimer1_clicked();


    void on_valide_modif_clicked();




void on_Imprimer_clicked();



void on_send_email_clicked();



void on_trier_clicked();

void on_stat_said_clicked();



void on_tab_employer_activated(const QModelIndex &index);

void on_chercher_entreprise_clicked();

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
     /**************************************amal************************************/
     //Ui::MainWindow *ui;
     QDialog *chartDialog;
      AUDITS Am;
      /*******************sabaa***************************************************/

      Employer E;
      Employer E1;
       Employer Et;
       Employer m;
      // Ui::MainWindow *ui;
       int selectedId;
       QString etatformulaire;
       int endusavec;
       //***************************************
       Qt::SortOrder sortOrder;
        QSortFilterProxyModel* proxyModelChercher;
        static bool customSort(const QModelIndex &left, const QModelIndex &right);

       QStringList files;
           Entreprise e,e1;

       //QByteArray data;
       Arduino *arduino;
};
#endif // MAINWINDOW_H
