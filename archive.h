#ifndef Archive_H
#define Archive_H

#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include <QKeyEvent>
#include <QStandardItemModel>
#include <QMap>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

using namespace std;

class Archive
{
public:
    // variables de l'entité


    int ID;
    QString NOM;
    QDate DATE_HIS;
    QString TYPE;
    QString VERSION;
    QString filePath;


    Archive();

    Archive(int id,  QString ,  QDate ,  QString ,  QString );






    int getID() const ;
    QString getNOM() const ;
    QDate getDATE_HIS() const ;
;
    QString getTYPE() const ;
    QString getVERSION() const ;

    void setID(int id);
    void setNOM(const QString& nom);
    void setDATE_HIS(const QDate& date);

    void setTYPE(const QString& type);
    void setVERSION(const QString& version);
    void setFilePath(const QString& filePath);


    bool ajouter();
    bool supprimer(int ID);
    bool update(int ID, QString NOM, QDate DATE_HIS,QString TYPE,QString VERSION);
    QSqlQueryModel *Afficher();
    vector<Archive> ListDesArchives(int);

    // metiers


    QSqlQueryModel* tri_ID();
QSqlQueryModel* MultiSearch(const QString &recherche) ;
void logHistoricalInfo(const QString& info);
bool exporterPDF(const QString &fileName, QSqlQueryModel *model);
void afficherHistorique();



};


#endif // Archive_H
