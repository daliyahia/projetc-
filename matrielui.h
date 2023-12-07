#ifndef MATRIELUI_H
#define MATRIELUI_H

#include <QDialog>
#include <QMainWindow>
#include "matriels.h"
#include <QPrinter>
#include <QPainter>
#include <QDate>
#include <QTextStream>
#include <QTextDocument>
#include "notification.h"
// Inclure le fichier d'en-tête pour la vue de graphique QtCharts
#include <QtCharts/QChartView>
// Inclure le fichier d'en-tête pour la série de diagramme circulaire QtCharts
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
// Inclure le fichier d'en-tête pour la gestion de la disposition horizontale
#include <QHBoxLayout>
#include <QtCharts/QLegend>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include "qrcode.h"
#include <QLayout>
#include <QVector>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include "arduino.h"
#include <QPalette>

namespace Ui {
class matrielui;
}

class matrielui : public QDialog
{
    Q_OBJECT

public:
    explicit matrielui(QWidget *parent = nullptr);
    ~matrielui();
private slots:
    void on_btn_ajouter_clicked();

    void on_btn_supprimer_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_modifier_clicked();




    void on_trimatrielsComboBox_currentIndexChanged(const QString &arg1);

    void on_rechercheBar_textChanged(const QString &arg1);


    void on_PDF_clicked();




    void on_statistique_clicked();

    void on_pushButton_call_clicked();

    void message();

    void on_excel_clicked();

    void on_clear_clicked();
    void statmatriels();


private:
    Ui::matrielui *ui;
    Matriels etmp;
     notification notif;
     QByteArray data;
     QString test1;
};

#endif // MATRIELUI_H
