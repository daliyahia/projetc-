#ifndef NORMEUI_H
#define NORMEUI_H

#include "norme.h"
#include <QDialog>
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

namespace Ui {
class normeui;
}

class normeui : public QDialog
{
    Q_OBJECT

public:
    explicit normeui(QWidget *parent = nullptr);
    ~normeui();

private slots:
    QString generateChatbotReply(const QString& message);
    void on_btn_ajouter_normes_clicked();

    void on_btn_modifier_normes_clicked();

    void on_tableViewnormes_clicked(const QModelIndex &index);
    void statistiqueNorme();

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

private:
    Ui::normeui *ui;
    QMediaPlayer *Player;
     QVideoWidget *Video;



     norme  etmp2;
  //  Ui::MainWindow *ui;

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
};

#endif // NORMEUI_H
