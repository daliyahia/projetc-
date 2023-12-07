#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "employer.h"
#include "arduino.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();



private slots:

    void on_Button_valider_clicked();
    void on_Scan_clicked();

private:
    Ui::login *ui;
    Arduino A;
};

#endif // LOGIN_H
