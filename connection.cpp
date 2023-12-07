#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("said");
    db.setPassword("esprit18");
    if(db.open()) test=true;
    return test;
}
void Connection::closeConnection(){db.close();}
