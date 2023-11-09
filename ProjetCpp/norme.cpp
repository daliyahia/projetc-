#include "norme.h"
#include<QString>

norme::norme()
{
    ID_N="";
    VERSION="";
    PRINCIPE="";
    OBJECTIFS="";
}
norme:: norme(QString ID_N,QString VERSION ,QString PRINCIPE,QString OBJECTIFS)
{
    this->ID_N=ID_N;
    this->VERSION=VERSION;
    this->PRINCIPE=PRINCIPE;
    this->OBJECTIFS=OBJECTIFS;
}
    QString norme::GetID_N(){return ID_N;}
    QString norme::GetVERSION() { return VERSION; }
    QString norme::GetPRINCIPE() { return PRINCIPE; }
    QString norme::GetOBJECTIFS() { return OBJECTIFS; }

    void norme::SetID_N(QString ID_N) { this->ID_N =ID_N; }
     void norme::SetVERSION(QString VERSION) { this->VERSION= VERSION; }
     void norme::SetPRINCIPE(QString PRINCIPE){ this->PRINCIPE= PRINCIPE; }
      void norme::SetOBJECTIFS(QString OBJECTIFS){ this->OBJECTIFS= OBJECTIFS; }

      bool norme::ajouter()
       {
          QSqlQuery query;

          query.prepare("INSERT INTO norme (ID_N,VERSION,PRINCIPE,OBJECTIFS )""VALUES(:id_n,:version,:principe,:objectifs)");
          query.bindValue(":id_n", ID_N);
          query.bindValue(":version", VERSION);
          query.bindValue(":principe", PRINCIPE);
          query.bindValue(":objectifs", OBJECTIFS);
          return query.exec();

       }

      QSqlQueryModel * norme::afficher()
      {
          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from norme");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_N"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("VERSION"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRINCIPE"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("OBJECTIFS"));
          return model;

      }

      bool norme::supprimer(QString id_n)
      {

          QSqlQuery query;
          query.prepare("Delete from norme where ID_N=:id_n");
          query.bindValue(":id_n",id_n);
          return query.exec();
          }
          bool norme::modifier(QString id_n){

              QSqlQuery query;


              query.prepare("UPDATE norme "" SET ID_N=:id_n, VERSION=:version, PRINCIPE=:principe , OBJECTIFS=:objectifs where ID_N='"+id_n+"' ");


                          query.bindValue(":id_n",ID_N );
                          query.bindValue(":version", VERSION);
                          query.bindValue(":principe", PRINCIPE);
                          query.bindValue(":objectifs", OBJECTIFS);



                      return query.exec();

          }

