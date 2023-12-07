#include "audits.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QSqlError>
using namespace std;

AUDITS::AUDITS()
{
    NUM_D=0;
    ACTION="";
    DATE_AUDIT="";

}
AUDITS::AUDITS(int NUM_D,QString ACTION,QString DATE_AUDIT)
{
    this->NUM_D=NUM_D;
    this->ACTION=ACTION;
    this->DATE_AUDIT=DATE_AUDIT;

}

int AUDITS::GetNUM()
{ return NUM_D; }
QString AUDITS::GetACTION()
{return  ACTION;}
QString AUDITS::GetDATE_AUDIT()
{return DATE_AUDIT;}

void AUDITS::SetNUM_D(int NUM_D){
    this->NUM_D=NUM_D;
}
void AUDITS::SetACTION(QString ACTION){
    this->ACTION=ACTION;
}
void AUDITS::SetDATE_AUDIT(QString DATE_AUDIT){
    this->DATE_AUDIT=DATE_AUDIT;
}

bool AUDITS::ajouter()
{
    bool test = false;
    QSqlQuery query;
    QString num_string = QString::number(NUM_D);

    query.prepare("INSERT INTO AUDITS (NUM_D,ACTION,DATE_AUDIT) "
                  "VALUES (:NUM_D, :ACTION ,:DATE_AUDIT)");
    query.bindValue(":NUM_D", num_string);
    query.bindValue(":ACTION", ACTION);
    query.bindValue(":DATE_AUDIT", DATE_AUDIT);


    if (query.exec()) {
        test = true;
    } else {
        qDebug() << "Error: " << query.lastError().text();
    }

    return test;
}



bool AUDITS::supprimer(int num_D  )
 {
     QSqlQuery query;
         query.prepare("SELECT * FROM AUDITS WHERE NUM_D = :num_D");
         query.bindValue(":num_D", num_D);

         if (query.exec() && query.next()) {
             // The num_D exists, so we can proceed with deletion.
             query.prepare("DELETE FROM AUDITS WHERE NUM_D = :num_D");
             query.bindValue(":num_D", num_D);
             if (query.exec()) {
                 return true; // Deletion was successful
             } else {
                 qDebug() << "Error during deletion:" << query.lastError().text();
                 return false;
             }
         } else {

             return false;
         }
     }






QSqlQueryModel* AUDITS::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT *  FROM AUDITS ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_D"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("action"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_AUDIT"));
    return model;
}
bool AUDITS::modifier(int NUM_D)
 {
     bool test = false;
     QSqlQuery query;
     QString NUM_D_string = QString::number(NUM_D);

     query.prepare("UPDATE AUDITS SET ACTION = :ACTION, DATE_AUDIT = :date_AUDIT WHERE NUM_D = :NUM_D");
     query.bindValue(":NUM_D", NUM_D_string);
     query.bindValue(":ACTION", ACTION);
     query.bindValue(":DATE_AUDIT", DATE_AUDIT);


     if (query.exec()) {
         test = true;
     } else {
         qDebug() << "Error: " << query.lastError().text();
     }

     return test;
 }
QSqlQueryModel * AUDITS ::tri_NUM_D()
{

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select * from AUDITS order by NUM_D");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_D"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ACTION"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_AUDIT"));

                   return model;

}

QSqlQueryModel *AUDITS::tri_DATE_AUDIT()
{



     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select * from AUDITS order by DATE_AUDIT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_D"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ACTION"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_AUDIT"));

                   return model;


}
QSqlQueryModel *AUDITS::rechercherAUDITS(QString recherche)
            {
                QSqlQueryModel * model = new QSqlQueryModel();
                model->setQuery("SELECT * FROM AUDITS WHERE NUM_D LIKE ('%"+recherche+"%')OR UPPER(ACTION) LIKE UPPER('%"+recherche+"%')OR DATE_AUDIT LIKE UPPER('%"+recherche+"%')");
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_D"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("ACTION"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_AUDIT"));


             return model;


            }


QSqlQueryModel* AUDITS::rechercherAUDITS(int NUM_D) {
    // Implémentation de la fonction rechercherAUDITS
    // Assurez-vous de retourner le modèle de requête correctement configuré
    QSqlQueryModel* model = new QSqlQueryModel();
    // ... code de la requête SQL ...
    return model;
}

