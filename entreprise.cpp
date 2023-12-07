#include "entreprise.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtWidgets/QApplication>
#include <QSqlQueryModel>
#include <QString>
#include <QComboBox>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

#include <QtCharts/QChartView>



Entreprise::Entreprise()
{
    Ide = " ";
    Nom = " ";
    Adresse = " ";
    Adresse_mail = " ";
    Numero = 0;
    Domaine = " ";
}

Entreprise::Entreprise(QString Ide, QString Nom, QString Adresse, QString Adresse_mail, int Numero, QString Domaine)
{
    this->Ide = Ide;
    this->Nom = Nom;
    this->Adresse = Adresse;
    this->Adresse_mail = Adresse_mail;
    this->Numero = Numero;
    this->Domaine = Domaine;
}

QString Entreprise::getIde() { return Ide; }
QString Entreprise::getNom() { return Nom; }
QString Entreprise::getAdresse() { return Adresse; }
QString Entreprise::getAdresse_mail() { return Adresse_mail; }
int Entreprise::getNumero() { return Numero; }
QString Entreprise::getDomaine() { return Domaine; }

void Entreprise::setIde(QString Ide) { this->Ide = Ide; }
void Entreprise::setNom(QString Nom) { this->Nom = Nom; }
void Entreprise::setAdresse(QString Adresse) { this->Adresse = Adresse; }
void Entreprise::setAdresse_mail(QString Adresse_mail) { this->Adresse_mail = Adresse_mail; }
void Entreprise::setNumero(int Numero) { this->Numero = Numero; }
void Entreprise::setDomaine(QString Domaine) { this->Domaine = Domaine; }

bool Entreprise::ajouter()
{

    QSqlQuery query;
        QString res = QString::number(Numero);
        query.prepare("insert into ENTREPRISE (ide, nom, addresse, email, numero, domaine) values(:ide, :nom, :addresse, :email, :numero, :domaine)");
        query.bindValue(":ide", Ide);
        query.bindValue(":nom", Nom);
        query.bindValue(":addresse", Adresse);
        query.bindValue(":email", Adresse_mail);
        query.bindValue(":numero", res);
        query.bindValue(":domaine", Domaine);
        bool test = query.exec();



            return test;
        return query.exec();

}
bool Entreprise::supprimer(QString Ide)
{
    QSqlQuery query;
    query.prepare("Delete from ENTREPRISE where ide=:Ide");
    query.bindValue(":Ide", Ide);

    return query.exec();

}
QSqlQueryModel* Entreprise::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM ENTREPRISE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ide"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse_email"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Domaine"));

return model;

}
bool Entreprise::idExists(QString Ide)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM ENTREPRISE WHERE ide = :ide");
    query.bindValue(":ide", Ide);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}

Entreprise Entreprise::getDataById(QString Ide)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ENTREPRISE WHERE ide = :ide");
    query.bindValue(":ide", Ide);

    if (query.exec() && query.next()) {
        QString Ide = query.value("ide").toString();
        QString Nom = query.value("nom").toString();
        QString Adresse = query.value("addresse").toString();
        QString Adresse_mail = query.value("email").toString();
        int Numero = query.value("numero").toInt();
        QString Domaine = query.value("domaine").toString();

        return Entreprise(Ide, Nom, Adresse, Adresse_mail, Numero, Domaine);
    }

    // Return an empty Entreprise object if no data is found
    return Entreprise();
}
bool Entreprise::updateData()
{
    QSqlQuery query;
    QString res = QString::number(Numero);
    query.prepare("UPDATE ENTREPRISE SET nom = :nom, addresse = :adresse, email = :email, numero = :numero, domaine = :domaine WHERE ide = :ide");
    query.bindValue(":ide", Ide);
    query.bindValue(":nom", Nom);
    query.bindValue(":adresse", Adresse);
    query.bindValue(":email", Adresse_mail);
    query.bindValue(":numero", res);
    query.bindValue(":domaine", Domaine);

    return query.exec();
}

