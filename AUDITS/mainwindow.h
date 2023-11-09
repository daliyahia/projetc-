#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audits.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
     explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_pb_ajouter_clicked();



    void on_bt_supp_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
     AUDITS A;



};
#endif // MAINWINDOW_H
