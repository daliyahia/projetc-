#include "employer.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>


Employer::Employer()
{
id=0; nom=""; prenom=""; adresse=""; role=""; suivi=0; salaire=0;
}

Employer::Employer(int id,QString nom,QString prenom,QString adresse,QString role,int suivi,float salaire)
{this->id=id; this->nom=nom; this->prenom=prenom; this->adresse=adresse; this->role=role;
    this->suivi=suivi;this->salaire=salaire;}


Employer::Employer(int id,QString nom,QString prenom,int suivi)
{this->id=id; this->nom=nom; this->prenom=prenom;this->suivi=suivi;}

int Employer:: getid(){return id;}
QString Employer:: getnom(){return nom;}
QString Employer::getprenom(){return prenom;}
QString Employer:: getadresse(){return adresse;}
QString Employer::getrole(){return role;}
int Employer::getsuivi(){return suivi;}
float Employer::getsalaire(){return salaire;}
void Employer:: setid(int id){this->id=id;}
void Employer::setnom(QString nom){this->nom=nom;}
void Employer::setprenom(QString prenom){this->prenom=prenom;}
void Employer::setadresse(QString adresse){this->adresse=adresse;}
void Employer::setrole(QString role){this->role=role;}
void Employer::setsuivi(int suivi){this->suivi=suivi;}
void Employer::setsalaire(float salaire){this->salaire=salaire;}

bool Employer::ajouter()
{
   QSqlQuery query;
   QString id_string=QString::number(id);
   QString suivi_string=QString::number(suivi);
   QString salaire_string=QString::number(salaire);
   query.prepare("INSERT INTO AUDITEURS (ID, NOM, PRENOM, ADRESSE, ROLE, SUIVI,SALAIRE) VALUES (:ID, :NOM, :PRENOM, :ADRESSE, :ROLE, :SUIVI, :SALAIRE)");
   query.bindValue(":ID", id_string);
   query.bindValue(":NOM", nom);
   query.bindValue(":PRENOM", prenom);
   query.bindValue(":ADRESSE", adresse);
   query.bindValue(":ROLE", role);
   query.bindValue(":SUIVI", suivi_string);
   query.bindValue(":SALAIRE", salaire_string);
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
    query.bindValue(":SALAIRE",salaire);
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
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));



   return model;
}
bool Employer::modifier(int id)
{

 QString id_string=QString::number(id);
 QString suivi_string=QString::number(suivi);

 QString salaire_string=QString::number(salaire);
    QSqlQuery query;
          query.prepare("UPDATE AUDITEURS SET  NOM= :NOM, PRENOM= :PRENOM, ADRESSE= :ADRESSE, ROLE= :ROLE, SUIVI=:SUIVI, SALAIRE=:SALAIRE where id=:ID");
          query.bindValue(":ID",id_string);
           query.bindValue(":NOM",nom);
           query.bindValue(":PRENOM",prenom);
           query.bindValue(":ADRESSE",adresse);
           query.bindValue(":ROLE",role);         
           query.bindValue(":SUIVI",suivi_string);
           query.bindValue(":SALAIRE", salaire_string);
           return query.exec();
}
QSqlQueryModel* Employer::tri_nom()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  AUDITEURS  ORDER BY NOM ASC");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));         
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE "));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("SUIVI"));
                   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
                   return model;


}

QSqlQueryModel* Employer::tri_suivi()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  AUDITEURS  ORDER BY SUIVI ASC");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE "));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("SUIVI"));
                   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
                   return model;


}
QSqlQueryModel* Employer::tri_ID()
{

                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from  AUDITEURS  ORDER BY ID ASC");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE "));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("SUIVI"));
                   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
                   return model;


}


QSqlQueryModel* Employer::chercher_nom(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM AUDITEURS WHERE ID LIKE '"+recherche+"%' OR NOM LIKE '"+recherche+"%' OR PRENOM LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("SUIVI"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));

     return model;
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


int Employer::calculer()
{
    QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM AUDITEURS");
        if (!query.exec())
        {
            qDebug() << "Erreur :" << query.lastError().text();
            return -1;
        }
        if (query.next())
        {
            int tot = query.value(0).toInt();
            qDebug() << "totale:" << tot;
            return tot;
        } else
        {
            qDebug() << "Aucun res.";
            return -1;
        }
}
int Employer::rol(QString role)
{
    QSqlQuery query;

        query.prepare("SELECT COUNT(*) FROM AUDITEURS WHERE role = :ROLE");
        query.bindValue(":ROLE", role);
        if (!query.exec()) {
            qDebug() << "Erreur :" << query.lastError().text();
            return -1;
        }
        if (query.next()) {
            int count = query.value(0).toInt();
            qDebug() << "Le nombre d'occurrences pour le role" << role << "est de" << count;
            return count;
        }
        else
            {
                qDebug() << "Aucun resultat retourne par la requete.";
                return -1;
            }

}
float Employer::statistique(QString role)
{
    float stat=0;
    int tot;
    int count;
    tot=calculer();
    count=rol(role);
    qDebug()<<tot;
    qDebug()<<count;
if(tot!=-1)
{
    stat=static_cast<double>(count)/tot*100;
    qDebug() << "statistique de "<<role<<"="<<stat<<"%";
}
    return stat;
}

Employer Employer::employer_du_mois()
{
    QSqlQuery query;
          query.prepare("SELECT * FROM AUDITEURS ORDER BY SUIVI DESC ");

          if (!query.exec()) {
              qDebug() << "Erreur :" << query.lastError().text();
              // Vous pouvez renvoyer un employé par défaut ou gérer l'erreur autrement
              return Employer(); // Retourne un employé par défaut
          }

          if (query.next()) {
              int id = query.value(0).toInt();
              QString nom = query.value(1).toString(); // Remplacez ces valeurs par les colonnes appropriées
              QString prenom = query.value(2).toString();
              int suivi = query.value(5).toInt();
              // ... (autres colonnes)

              // Créez un objet Employer avec les données récupérées
              Employer employeDuMois(id, nom, prenom,suivi); // Assurez-vous d'inclure toutes les informations nécessaires

              return employeDuMois;
          } else {
              qDebug() << "Aucun employé trouvé.";
              // Vous pouvez renvoyer un employé par défaut ou gérer l'erreur autrement
              return Employer(); // Retourne un employé par défaut
          }

    }
