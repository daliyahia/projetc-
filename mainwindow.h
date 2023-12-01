#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employer.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Button_valider_clicked();




    void on_Scan_clicked();

private:
    Ui::MainWindow *ui;
    Arduino A;
};
#endif // MAINWINDOW_H
