#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "entreprise.h"
#include <QMainWindow>
#include <QComboBox>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSortFilterProxyModel>
#include "arduino.h"
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
    void on_btajouter_clicked();



    void on_supprimer1_clicked();


    void on_valide_modif_clicked();

    void on_chercher_clicked();


void on_Imprimer_clicked();



void on_send_email_clicked();

void on_stat_clicked();

void on_trier_clicked();

private:
    Ui::MainWindow *ui;
    //trier
Qt::SortOrder sortOrder;
 QSortFilterProxyModel* proxyModelChercher;
 static bool customSort(const QModelIndex &left, const QModelIndex &right);

QStringList files;
    Entreprise E,E1;

QByteArray data;
Arduino *arduino;
};
#endif // MAINWINDOW_H
