#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void statistiqueNorme();

private slots:
    void on_btn_modifier_clicked();

    void on_btn_ajouter_clicked();

    void on_btn_supprimer_clicked();

    void on_tableView_clicked(const QModelIndex &index);



    void on_comboBox_tri_currentIndexChanged(const QString &arg1);

    void on_rechercher_textChanged(const QString &arg1);

    void on_PDF_clicked();

    void on_pushButton_clicked();

    void on_stat_clicked();

    void sendMessage();
    void on_SendButton_clicked();
    void fetchTriviaQuestion(const QString& apiUrl);
    int checkCondition(const QString& lowercaseMessage);

    void on_apprendre_clicked();



    void on_pushButton_video_clicked();

private:

    QMediaPlayer *Player;
     QVideoWidget *Video;



     norme  etmp;
    Ui::MainWindow *ui;
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
    //QString decodeHtmlEntities(const QString& text);
};
#endif // MAINWINDOW_H
