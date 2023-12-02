#include "connection.h"

connection::connection()
{

 }

bool connection::createconnection()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("ProjetCpp");//source de Donees OBDC
db.setUserName("yesmine");//inserer nom de l'utilisateur
db.setPassword("esprit23");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;

}
 void connection::closeconnection(){db.close();}


