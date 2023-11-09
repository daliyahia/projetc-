#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>



class Employer
{
public:
    Employer();
    Employer(int,QString,QString,QString,QString,int);
    int getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getrole();
    int getsuivi();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setrole(QString);
    void setsuivi(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id);
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_suivi();
    QSqlQueryModel* tri_ID();
    QSqlQueryModel* rechercher();
    QSqlQueryModel* chercher_nom(QString recherche);
    int statistique();
    int total_controleur();
    int total_secretaire();
    int total_directeur();

private:
     int id,suivi;
     QString nom,prenom,adresse,role;

};


#endif // EMPLOYER_H
