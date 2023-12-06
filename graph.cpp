#include "graph.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>

graph::graph(QWidget *parent)
    : QMainWindow(parent)
{
    QSqlQuery query("SELECT * FROM ARCHIVE ORDER BY TYPE");

    QBarSet *barSet = new QBarSet("Article");

    int index = 1;
    while (query.next()) {
        QString TYPE = query.value("TYPE").toString();

        // Utilisation de l'index de la requête comme abscisse
        QString stringValueFromQuery = query.value("QT").toString();
        // Remplacez INDEX_COLUMN_NAME par le nom de la colonne contenant les indices dans votre base de données

        // Adding data to the bar set
        *barSet << stringValueFromQuery.toDouble();  // Assuming your QT values are numeric

        index++;
    }

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(barSet);

    QChart *graphe = new QChart();
    graphe->addSeries(barSeries);
    graphe->setTitle("Graph Article");

    QBarCategoryAxis *axeX = new QBarCategoryAxis();
    axeX->append("Article", barSet);
    graphe->addAxis(axeX, Qt::AlignBottom);
    barSeries->attachAxis(axeX);

    QValueAxis *axeY = new QValueAxis;
    axeY->setRange(0, 100);  // Ajustez cette plage selon vos données
    axeY->setLabelFormat("%.1f");
    axeY->setTitleText(QString::fromUtf8("Prix"));
    graphe->addAxis(axeY, Qt::AlignLeft);
    barSeries->attachAxis(axeY);

    // Le widget
    QChartView *graphique = new QChartView(graphe);
    graphique->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(graphique);
    resize(800, 600);
}

