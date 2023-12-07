#ifndef AUDITS_H
#define AUDITS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTableView>
class AUDITS
{
public:
       AUDITS();
       AUDITS(int,QString,QString);


       int GetNUM() ;
        void SetNUM_D(int NUM_D) ;
        QString GetACTION() ;
        void SetACTION(QString ACTION) ;
        QString GetDATE_AUDIT() ;
        void SetDATE_AUDIT(QString DATE_AUDIT) ;

       bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(int);
        bool modifier(int );

        QSqlQueryModel *tri_NUM_D();
        QSqlQueryModel *tri_DATE_AUDIT();
        QSqlQueryModel* rechercherAUDITS(QString recherche);
        QSqlQueryModel* rechercherAUDITS(int NUM_D);

 void dataChanged();





   private:
       int NUM_D;
       QString ACTION;
       QString DATE_AUDIT;


};

#endif // AUDITS_H

