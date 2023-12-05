#include "matriels.h"
#include<QString>
Matriels::Matriels()
{
  REFERENCE="";
  NOM="";
  ETAT="";
  QUANTITE=0;

}
Matriels::Matriels(QString REFERENCE,QString NOM,QString ETAT,int QUANTITE)
{
    this->REFERENCE=REFERENCE;
    this->NOM=NOM;
    this->ETAT=ETAT;
    this->QUANTITE=QUANTITE;
}
QString Matriels::getREFERENCE(){return REFERENCE;}
QString Matriels::getNOM(){return NOM;}
QString Matriels::getETAT(){return ETAT;}
int Matriels::getQUANTITE(){return QUANTITE;}

void Matriels::setREFERENCE(QString REFERENCE){ this->REFERENCE=REFERENCE;}
 void Matriels::setNOM(QString NOM){ this->NOM=NOM;}
  void Matriels::setETAT(QString ETAT){ this->ETAT=ETAT;}
  void Matriels::setQUANTITE(int QUANTITE){ this->QUANTITE=QUANTITE;}




  bool Matriels::ajouter()
  {
      QSqlQuery query;
      QString res=QString::number(QUANTITE);


      query.prepare("insert into matriels (REFERENCE,NOM,ETAT,QUANTITE )""values(:ref,:nom,:etat,:quantite)");
      query.bindValue(":ref", REFERENCE);
      query.bindValue(":nom", NOM);
      query.bindValue(":etat", ETAT);
      query.bindValue(":quantite", res);
  return query.exec();
  }



  QSqlQueryModel *Matriels::afficher()
  {
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select REFERENCE,NOM,ETAT,QUANTITE from matriels");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITE"));
  return model;
  }

  bool Matriels::supprimer(QString ref)
  {
  QSqlQuery query;

  query.prepare("Delete from matriels where reference=:ref");
  query.bindValue(":ref",ref);
  return query.exec();
  }
  bool Matriels::modifier(QString ref){

      QSqlQuery query;
          QString res=QString::number(QUANTITE);


            query.prepare("UPDATE matriels SET REFERENCE=:ref, NOM=:nom, ETAT=:etat , QUANTITE=:quantite where REFERENCE='"+ref+"' ");

            query.bindValue(":ref", REFERENCE);
            query.bindValue(":nom", NOM);
            query.bindValue(":etat", ETAT);
            query.bindValue(":quantite", res);


              return query.exec();

  }




  QSqlQueryModel *Matriels::recherchermatriels(QString recherche)
  {
      QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery("SELECT * from matriels WHERE (UPPER(REFERENCE) LIKE UPPER('%"+recherche+"%') OR UPPER(NOM) LIKE UPPER('%"+recherche+"%') OR ETAT LIKE UPPER('%"+recherche+"%'))");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));
      return model;

  }
QSqlQueryModel * Matriels::trimatriels(QString tri)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    if(tri == "par défaut"){
        model->setQuery("select REFERENCE,NOM,ETAT,QUANTITE from matriels");
    }else if (tri == "reference") {
        model->setQuery("select REFERENCE,NOM,ETAT,QUANTITE from matriels ORDER BY reference ");
    } else if (tri == "nom") {
        model->setQuery("select REFERENCE,NOM,ETAT,QUANTITE from matriels ORDER BY nom");
    }
    else if (tri == "etat") {
            model->setQuery("select REFERENCE,NOM,ETAT,QUANTITE from matriels ORDER BY etat");
        }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;

}
QVector<int> Matriels::statmatriels()
{
    QVector<int> stat;
        QSqlQuery query;
        int nbr1=0,nbr2=0;

        query.exec("SELECT "
                   "SUM(CASE WHEN QUANTITE > 10 THEN 1 ELSE 0 END) AS num_1, "
                   "SUM(CASE WHEN QUANTITE < 10 THEN 1 ELSE 0 END) AS num_2 "
                   "FROM matriels");
        if (query.next()) {
            // Récupère les valeurs de num_1 et num_2 et les convertit en entiers
            nbr1 = query.value("num_1").toInt();
            nbr2 = query.value("num_2").toInt();

        }
        stat.push_back(nbr1);
        stat.push_back(nbr2);

        return stat;
}
