#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QDebug>
#include <QMessageBox>
#include "QTranslator"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
  // MainWindow w;
    login l;

    if(test)
    {
         l.show();
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

            }
                else
                    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                QObject::tr("connection failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
    QTranslator T;
    QStringList languages;
          languages <<"French"<<"English";
          const QString lang=QInputDialog::getItem(NULL,"Select language ","Language",languages);
          if (lang=="English")

        {
             T.load(":/new/traduction/anglais.qm");
        }
        if (lang !="French")
        {
            a.installTranslator(&T);
        }
     l.show();

    return a.exec();
}
