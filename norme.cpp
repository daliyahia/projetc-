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
//QSDFGHJKLM%
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


              query.prepare("UPDATE norme"" SET ID_N=:id_n, VERSION=:version, PRINCIPE=:principe , OBJECTIFS=:objectifs where ID_N='"+id_n+"' ");


                          query.bindValue(":id_n",ID_N );
                          query.bindValue(":version", VERSION);
                          query.bindValue(":principe", PRINCIPE);
                          query.bindValue(":objectifs", OBJECTIFS);



                      return query.exec();

          }



          QSqlQueryModel * norme::triNorme(QString tri)
          {
              QSqlQueryModel * model = new QSqlQueryModel();
              if(tri == "par défaut"){
                  model->setQuery("SELECT * FROM norme ");
              }else if (tri == "id_n") {
                  model->setQuery("SELECT * FROM norme ORDER BY ID_N ");
              } else{
                  model->setQuery("SELECT * FROM norme ORDER BY VERSION");
              }
              model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_n"));
              model->setHeaderData(1,Qt::Horizontal,QObject::tr("version"));
              model->setHeaderData(2,Qt::Horizontal,QObject::tr("principe"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("objectifs"));
              return model;

          }


          QSqlQueryModel *norme::rechercherNorme(QString recherche)
            {
                QSqlQueryModel * model = new QSqlQueryModel();
                model->setQuery("SELECT * FROM norme WHERE ID_N LIKE UPPER('%"+recherche+"%')OR UPPER(VERSION) LIKE UPPER('%"+recherche+"%')OR UPPER(PRINCIPE) LIKE UPPER('%"+recherche+"%')");
                model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_n"));
                model->setHeaderData(1,Qt::Horizontal,QObject::tr("version"));
                model->setHeaderData(2,Qt::Horizontal,QObject::tr("principe"));
                model->setHeaderData(3,Qt::Horizontal,QObject::tr("objectifs"));
                return model;

            }



          QVector<int> norme::statNorme()
          {
              QVector<int> stat;
                  QSqlQuery query;
                  int nbr1=0,nbr2=0;
                  query.exec("SELECT "
                             "SUM(CASE WHEN version = '2015' THEN 1 ELSE 0 END) AS num_1, "
                             "SUM(CASE WHEN version = '2018' THEN 1 ELSE 0 END) AS num_2 "

                             "FROM norme");
                  if (query.next()) {
                      nbr1 = query.value("num_1").toInt();
                      nbr2 = query.value("num_2").toInt();


                  }
                  stat.push_back(nbr1);
                  stat.push_back(nbr2);


                  return stat;

          }

