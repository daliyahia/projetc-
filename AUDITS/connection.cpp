#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetCpp");
db.setUserName("amaluser");//inserer nom de l'utilisateur
db.setPassword("123456");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
