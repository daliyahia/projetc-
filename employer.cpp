#include "employer.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>


Employer::Employer()
{
id=0; nom=""; prenom=""; adresse=""; role=""; suivi=0;
}

Employer::Employer(int id,QString nom,QString prenom,QString adresse,QString role,int suivi)
{this->id=id; this->nom=nom; this->prenom=prenom; this->adresse=adresse; this->role=role;
    this->suivi=suivi;}

int Employer:: getid(){return id;}
QString Employer:: getnom(){return nom;}
QString Employer::getprenom(){return prenom;}
QString Employer:: getadresse(){return adresse;}
QString Employer::getrole(){return role;}
int Employer::getsuivi(){return suivi;}
void Employer:: setid(int id){this->id=id;}
void Employer::setnom(QString nom){this->nom=nom;}
void Employer::setprenom(QString prenom){this->prenom=prenom;}
void Employer::setadresse(QString adresse){this->adresse=adresse;}
void Employer::setrole(QString role){this->role=role;}
void Employer::setsuivi(int suivi){this->suivi=suivi;}

bool Employer::ajouter()
{
   QSqlQuery query;
   QString id_string=QString::number(id);
   QString suivi_string=QString::number(suivi);
   query.prepare("INSERT INTO AUDITEURS (ID, NOM, PRENOM, ADRESSE, ROLE, SUIVI) VALUES (:ID, :NOM, :PRENOM, :ADRESSE, :ROLE, :SUIVI)");
   query.bindValue(":ID", id_string);
   query.bindValue(":NOM", nom);
   query.bindValue(":PRENOM", prenom);
   query.bindValue(":ADRESSE", adresse);
   query.bindValue(":ROLE", role);
   query.bindValue(":SUIVI", suivi_string);
   return  query.exec();

}
bool Employer::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("delete from AUDITEURS where id=:ID");
    query.bindValue(":ID",id);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":ROLE", role);
    query.bindValue(":SUIVI", suivi);
    return  query.exec();
}


QSqlQueryModel* Employer::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();

   model->setQuery("SELECT *  FROM AUDITEURS ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("SUIVI"));



   return model;
}
bool Employer::modifier(int id)
{

 QString id_string=QString::number(id);
 QString suivi_string=QString::number(suivi);
    QSqlQuery query;
          query.prepare("UPDATE AUDITEURS SET  NOM= :NOM, PRENOM= :PRENOM, ADRESSE= :ADRESSE, ROLE= :ROLE, SUIVI=:SUIVI where id=:ID");
          query.bindValue(":ID",id_string);
          query.bindValue(":NOM",nom);
           query.bindValue(":PRENOM",prenom);
           query.bindValue(":ADRESSE",adresse);
           query.bindValue(":ROLE",role);         
           query.bindValue(":SUIVI",suivi_string);
           return query.exec();
}
QSqlQueryModel* Employer::tri_nom()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  AUDITEURS  ORDER BY NOM ASC");
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("ROLE "));
                   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SUIVI"));
                   return model;


}

QSqlQueryModel* Employer::tri_suivi()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  AUDITEURS  ORDER BY SUIVI ASC");
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("ROLE "));
                   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SUIVI"));
                   return model;


}
QSqlQueryModel* Employer::tri_ID()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  AUDITEURS  ORDER BY ID ASC");
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("ROLE "));
                   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SUIVI"));
                   return model;


}


QSqlQueryModel* Employer::chercher_nom(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM AUDITEURS WHERE ID LIKE '"+recherche+"%' OR NOM LIKE '"+recherche+"%' OR PRENOM LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("SUIVI"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ROLE"));

     return model;
}

int Employer :: statistique()
{
    Dialog_Stats stats;
    stats.setModal(true);
    stats.exec();
}
int Employer:: total_secretaire()
{
QSqlQuery query;
query.prepare("SELECT COUNT(*) FROM AUDITEURS");

query.exec();
int rows = 0;
while(query.next()) {
    rows = query.value(0).toInt();
}

return rows ;
}
int Employer:: total_controleur()
{
QSqlQuery query;
query.prepare("SELECT COUNT(*) FROM AUDITEURS");

query.exec();
int rows = 0;
while(query.next()) {
    rows = query.value(0).toInt();
}

return rows ;
}
int Employer:: total_directeur()
{
QSqlQuery query;
query.prepare("SELECT COUNT(*) FROM AUDITEURS");

query.exec();
int rows = 0;
while(query.next()) {
    rows = query.value(0).toInt();
}

return rows ;
}
