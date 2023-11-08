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
  model->setQuery("select * from matriels");
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




