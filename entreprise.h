#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include <QString>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

#include <QtCharts/QChartView>
class Entreprise
{

public:
    Entreprise();
    Entreprise(QString,QString,QString,QString,int,QString);
    QString getIde();
    QString getNom();
    QString getAdresse();
    QString getAdresse_mail();
    int getNumero();
    QString getDomaine();

    void setIde(QString);
    void setNom(QString);
    void setAdresse(QString);
    void setAdresse_mail(QString);
    void setNumero(int);
    void setDomaine(QString);

   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(QString);
   bool idExists(QString );
   Entreprise getDataById(QString );
   bool updateData();

private:
    int Numero;
    QString Ide,Nom,Adresse,Adresse_mail,Domaine;
};




#endif // ENTREPRISE_H
