#ifndef AUDITS_H
#define AUDITS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
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






   private:
       int NUM_D;
       QString ACTION;
       QString DATE_AUDIT;


};

#endif // AUDITS_H

