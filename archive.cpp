#include "archive.h"
#include<QSqlQuery>
#include<QtDebug>
#include <iostream>
#include<QObject>
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QStandardItemModel>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QtSql>
#include <QMap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries> // Inclure cette ligne
#include <QtCharts/QChart>
bool queryResult;
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>

using namespace std;


Archive::Archive() {
    ID = 0;
    NOM="";
    TYPE = "";
    VERSION = "";
}

Archive::Archive(int id,  QString nom,  QDate dateHis,  QString type,  QString version)
{
    ID = id;
    NOM = nom;
    DATE_HIS = dateHis;
    TYPE = type;
    VERSION = version;
}

// Getters
int Archive::getID() const {
    return ID;
}

QString Archive::getNOM() const {
    return NOM;
}

QDate Archive::getDATE_HIS() const {
    return DATE_HIS;
}


QString Archive::getTYPE() const {
    return TYPE;
}

QString Archive::getVERSION() const {
    return VERSION;
}

// Setters
void Archive::setID(int id) {
    ID = id;
}

void Archive::setNOM(const QString& nom) {
    NOM = nom;
}

void Archive::setDATE_HIS(const QDate& date) {
    DATE_HIS = date;
}


void Archive::setTYPE(const QString& type) {
    TYPE = type;
}

void Archive::setVERSION(const QString& version) {
    VERSION = version;
}




bool Archive::ajouter() {
    QSqlQuery query;
    QString res = QString::number(ID);

    query.prepare("INSERT INTO ARCHIVE (ID, NOM, DATE_HIS, TYPE, VERSION) "
                  "VALUES (:ID, :NOM, :DATE_HIS, :TYPE, :VERSION)");

    query.bindValue(":ID", res);
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATE_HIS", DATE_HIS);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":VERSION", VERSION);

    // Exécution de la requête SQL
    bool queryResult = query.exec();

    // Enregistrement dans l'historique
    QFile file("C:/Users/21650/Desktop/Archive/historique.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        // Gérer l'échec d'ouverture du fichier
        return false;
    }

    QTextStream cout(&file);
    QString d_info = QDateTime::currentDateTime().toString();
    QString message = d_info + " - Une archive a été ajoutée avec l'id " + QString::number(ID) + "\n";
    cout << message;

    file.close();

    return queryResult;
}


bool Archive::supprimer(int ID) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    QString deleteQuery = "DELETE FROM ARCHIVE WHERE ID = :ID";
    query.prepare(deleteQuery);
    query.bindValue(":ID", ID);

    // Exécution de la requête SQL
    bool success = query.exec();

    // Enregistrement dans l'historique
    QFile file("C:/Users/21650/Desktop/Archive/historique.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        // Gérer l'échec d'ouverture du fichier
        qDebug() << "Error opening history file for writing";
        return false;
    }

    QTextStream cout(&file);
    QString d_info = QDateTime::currentDateTime().toString();
    QString message = d_info + " - Archive avec l'id " + QString::number(ID) + " supprimée\n";
    cout << message;

    file.close();

    // Gestion des erreurs lors de la suppression
    if (!success) {
        qDebug() << "Error deleting record:" << query.lastError().text();
    }

    return success;
}


bool Archive::update(int ID, QString NOM, QDate DATE_HIS, QString TYPE, QString VERSION) {
    QSqlQuery query;
    query.prepare("UPDATE ARCHIVE SET NOM=:NOM, DATE_HIS=:DATE_HIS, TYPE=:TYPE, VERSION=:VERSION WHERE ID=:ID");
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATE_HIS", DATE_HIS);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":VERSION", VERSION);
    query.bindValue(":ID", ID);

    // Exécution de la requête SQL
    bool queryResult = query.exec();

    // Enregistrement dans l'historique
    QFile file("C:/Users/21650/Desktop/Archive/historique.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        // Gérer l'échec d'ouverture du fichier
        qDebug() << "Error opening history file for writing";
        return false;
    }

    QTextStream cout(&file);
    QString d_info = QDateTime::currentDateTime().toString();
    QString message = d_info + " - Archive avec l'id " + QString::number(ID) + " mise à jour\n";
    cout << message;

    file.close();

    return queryResult;
}




QSqlQueryModel* Archive::Afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM ARCHIVE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_HIS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("VERSION"));

    // Enregistrement dans l'historique
    QFile file("C:/Users/21650/Desktop/Archive/historique.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream cout(&file);
        QString d_info = QDateTime::currentDateTime().toString();
        QString message = d_info + " - Affichage des archives\n";
        cout << message;

        file.close();
    } else {
        qDebug() << "Error opening history file for writing";
    }

    return model;
}




vector<Archive> Archive::ListDesArchives(int ID){
    Archive a;
    vector<Archive> vecteurArchives;

    QSqlQuery query;
    query.prepare("SELECT * from ARCHIVE where ID!=:ID");
    query.bindValue(":ID",ID);

    if (query.exec()) {
        while(query.next()){
            a.setID(query.value("ID").toInt());
            a.setNOM(query.value("NOM").toString());
            a.setDATE_HIS(query.value("DATE_HIS").toDate());
            a.setTYPE(query.value("TYPE").toString());
            a.setVERSION(query.value("VERSION").toString());


            // Retrieve date as QDateTime and then convert it to QDate
            QDateTime dateTime = query.value("DATE").toDateTime();
            a.setDATE_HIS(dateTime.date());

            vecteurArchives.push_back(a);
        }
    }
    return vecteurArchives;
}


QSqlQueryModel* Archive::MultiSearch(const QString &recherche)
 {

     QSqlQueryModel * m=new QSqlQueryModel();
     m->setQuery("SELECT * FROM ARCHIVE WHERE VERSION LIKE '"+recherche+"%' OR NOM LIKE '"+recherche+"%' OR TYPE LIKE '"+recherche+"%' ");
     m->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
     m->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     m->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_HIS"));
     m->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));
     m->setHeaderData(4,Qt::Horizontal,QObject::tr("VERSION"));


     return m;
}







QSqlQueryModel* Archive::tri_ID()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  ARCHIVE  ORDER BY ID ASC ");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE "));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("VERSION"));

                   return model;


}




void Archive::afficherHistorique() {
    // Charger le contenu du fichier d'historique
    QFile historyFile("C:/Users/21650/Desktop/Archive/historique.txt");
    if (historyFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&historyFile);
        QString historiqueContenu = in.readAll();
        historyFile.close();


        QDialog* historiqueDialog = new QDialog(nullptr);
        historiqueDialog->setWindowTitle("Historique");
        historiqueDialog->setMinimumSize(400, 300);

        QTextEdit* textEdit = new QTextEdit(historiqueDialog);
        textEdit->setPlainText(historiqueContenu);
        textEdit->setReadOnly(true);

        QVBoxLayout* layout = new QVBoxLayout(historiqueDialog);
        layout->addWidget(textEdit);

        historiqueDialog->exec();
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le fichier d'historique pour la lecture.");
    }
}


