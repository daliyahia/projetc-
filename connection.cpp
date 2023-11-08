#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("ProjetCpp");
    db.setUserName("dali");
    db.setPassword("esprit23");
    if(db.open()) test=true;
    return test;
}
void Connection::closeConnection(){db.close();}
