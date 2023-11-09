#ifndef NORME_H
#define NORME_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class norme
{
public:
    norme();

    norme(QString,QString,QString,QString);
   //  ~norme();

           QString GetID_N();
            QString GetVERSION();
             QString GetPRINCIPE();
              QString GetOBJECTIFS() ;

          void SetID_N(QString);
          void SetVERSION(QString);
           void SetPRINCIPE(QString);
           void SetOBJECTIFS(QString);
           //fonctionnalites

 public slots :

           bool ajouter();
           QSqlQueryModel *afficher();
           bool supprimer(QString);
            bool modifier(QString);

        protected:
       private:
           QString ID_N;
           QString VERSION;
           QString PRINCIPE;
           QString OBJECTIFS;
};

#endif // NORME_H
