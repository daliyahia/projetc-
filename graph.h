#ifndef GRAPH_H
#define GRAPH_H



#include <QtWidgets>
#include <QtCharts>

class graph : public QMainWindow
{
    Q_OBJECT

private:
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données

public:
    graph(QWidget *parent = 0);
    ~graph();
};

#endif // IHMGRAPHIQUE_H
