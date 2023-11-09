#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>

class connection
{
    QSqlDatabase db;
public:
       connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
