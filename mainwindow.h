#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matriels.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_btn_ajouter_clicked();

    void on_btn_supprimer_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_modifier_clicked();

private:
    Matriels etmp;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
