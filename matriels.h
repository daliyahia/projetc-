#ifndef MATRIELS_H
#define MATRIELS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Matriels
{
public:
    Matriels();
    Matriels(QString,QString,QString,int);
    QString getREFERENCE();
    QString getNOM();
    QString getETAT();
    int getQUANTITE();

    void setREFERENCE(QString);
     void setNOM(QString);
      void setETAT(QString);

       void setQUANTITE(int);
       //fonctionnalites
public slots :
       bool ajouter();
       QSqlQueryModel *afficher();
       bool supprimer(QString );
       bool modifier( QString );
       //Métiers
       QSqlQueryModel * recherchermatriels(QString recherche);
       QSqlQueryModel * trimatriels(QString tri);
       QVector<int> statmatriels();



private:
    QString REFERENCE,NOM,ETAT;
    int QUANTITE;

};

#endif // MATRIELS_H
