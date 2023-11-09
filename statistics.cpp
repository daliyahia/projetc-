#include "statistics.h"
#include "ui_statistics.h"
#include "employer.h"
//#include <QtCharts>

statistics::statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistics)

{
    {
     ui->setupUi(this);
    this->setWindowTitle("STATISTIQUES");
           QPieSeries *series = new QPieSeries();


          // Crud_Menu m;
           Employer E;
          int  total_specialitepres = E.total_directeur()+E.total_secretaire()+E.total_controleur();

          series->append("total_directeur",E.total_directeur());
           //series->append("Total des enfant par rapport au prestataire ",total);
          series->append("total_secretaire",E.total_secretaire());
          series->append("total_controleur",E.total_controleur());
          series->setHoleSize(0.2);

           QPieSlice *slice = series->slices().at(0);
           slice->setLabelVisible();

           QPieSlice *slice1 = series->slices().at(1);
           slice1->setExploded();
           slice1->setLabelVisible();

           QPieSlice *slice2 = series->slices().at(2);
           slice2->setLabelVisible();

           QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("  specialité d'employers  :");
           chart->legend()->hide();
           chart->setAnimationOptions(QChart::SeriesAnimations);

           QChartView *chartview = new QChartView(chart);
           chartview->setRenderHint(QPainter::Antialiasing);
           chartview->setParent(ui->horizontalFrame);
       }
   }



statistics::~statistics()
{
    delete ui;
}

