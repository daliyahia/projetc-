#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>




class Employer
{
public:
    Employer();
    Employer(int, QString,QString,int);
    Employer(int,QString,QString,QString,QString,int,float);
    int getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getrole();
    int getsuivi();
    float getsalaire();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setrole(QString);
    void setsuivi(int);
    void setsalaire(float);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id);
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_suivi();
    QSqlQueryModel* tri_ID();
    QSqlQueryModel* rechercher();
    QSqlQueryModel* chercher_nom(QString recherche);
    int total_controleur();
    int total_secretaire();
    int total_directeur();
     int calculer();
     int rol(QString role);
     float statistique(QString role);
     Employer employer_du_mois();
     float getPrixTotalSuivisSup20() const;


private:
     int id,suivi;
     QString nom,prenom,adresse,role;
     float salaire;
     float prixTotalSuivisSup20;


};


#endif // EMPLOYER_H
