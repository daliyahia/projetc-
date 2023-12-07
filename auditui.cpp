#include "auditui.h"
#include "ui_auditui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audits.h"
#include <QMessageBox>
#include <QtDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QMessageBox>
#include <QIntValidator>
#include <QObject>
#include <QtDebug>
#include <QTabWidget>
#include<QSqlQuery>
#include <QDate>
#include <QDateEdit>
#include <QSqlTableModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QTextDocument>
//
#include <QDesktopServices>
#include <QTextDocument>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>


#include <QPainter>
#include <QDebug>



#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPainter>
#include <QApplication>
#include <QTextBrowser>
#include <QtCharts/QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include<QSqlRecord>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QSqlQueryModel>
#include <QDebug>
#include "calendrier.h"
#include <QDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>



#include <QPdfWriter>
#include <QPainter>

auditui::auditui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auditui)
{
    ui->setupUi(this);
}

auditui::~auditui()
{
    delete ui;
}

void auditui::on_pb_ajouter_clicked()
{
  qDebug() << "Setting background color to magenta.";
    ui->table_checklist->repaint();
    ui->table_checklist_2->repaint();

    ui->table_checklist_3->repaint();
    ui->table_checklist->setAutoFillBackground(true);
    ui->table_checklist_2->setAutoFillBackground(true);
     ui->table_checklist_3->setAutoFillBackground(true);
    qDebug() << "Setting background color to magenta.";
    ui->table_checklist->repaint();
    ui->table_checklist->setAutoFillBackground(true);
    ui->table_checklist_2->repaint();
    ui->table_checklist_2->setAutoFillBackground(true);
    ui->table_checklist_3->repaint();
    ui->table_checklist_3->setAutoFillBackground(true);
    int NUM_D = ui->le_numd->text().toInt();
       QString ACTION = ui->le_action->currentText();
       QString DATE_AUDIT = ui->la_date->text();

       // Utilisez qDebug() pour imprimer la valeur d'action dans la console de débogage
       qDebug() << "Action: " << ACTION;


       AUDITS A(NUM_D, ACTION, DATE_AUDIT);

       // Ajouter les données à la base de données
       bool insertionSuccess = A.ajouter();

       // Mettre à jour le modèle de la table avec les données nouvellement ajoutées
       ui->table_audits->setModel(A.afficher());
       QPalette palette = ui->table_checklist->palette();
       QPalette palette_2 = ui->table_checklist_2->palette();
       QPalette palette_3= ui->table_checklist_3->palette();
       palette.setColor(QPalette::Background, Qt::magenta);
       palette_2.setColor(QPalette::Background, Qt::magenta);
       palette_3.setColor(QPalette::Background, Qt::magenta);
       ui->table_checklist->setAutoFillBackground(true);
       ui->table_checklist->setPalette(palette);
       ui->table_checklist->setVisible(true);
       ui->table_checklist_2->setAutoFillBackground(true);
       ui->table_checklist_2->setPalette(palette_2);
       ui->table_checklist_2->setVisible(true);
       ui->table_checklist_3->setAutoFillBackground(true);
       ui->table_checklist_3->setPalette(palette_3);
       ui->table_checklist_3->setVisible(true);
       if (ACTION.toLower() == "conformer") {
           ui->table_checklist->setStyleSheet("background-color:magenta;");
           ui->table_checklist_3->setStyleSheet("background-color: magenta;");
       } else {
           // Rétablir la couleur par défaut si nécessaire
           ui->table_checklist->setStyleSheet(""); // Cela réinitialise la feuille de style
       }
       if (ACTION.toLower() == "criditation") {
           ui->table_checklist_2->setStyleSheet("background-color:magenta;");
           ui->table_checklist->setStyleSheet("background-color: magenta;");
           ui->table_checklist_3->setStyleSheet("background-color:magenta;");
       } else {
           // Rétablir la couleur par défaut si nécessaire
           ui->table_checklist_2->setStyleSheet(""); // Cela réinitialise la feuille de style
           ui->table_checklist_3->setStyleSheet("background-color:magenta;");
       }
       if (ACTION.toLower() == "analyser") {
           ui->table_checklist_3->setStyleSheet("background-color: magenta;");
       } else {
           // Rétablir la couleur par défaut si nécessaire
          // ui->table_checklist_3->setStyleSheet(""); // Cela réinitialise la feuille de style
       }


       QMessageBox messageBox;

       if (insertionSuccess) {
          // messageBox.setText("Data added to the database successfully!");

           // Mettre à jour la couleur du table_checklist si l'action est conforme
           if (ACTION.toLower() == "conforme") {
               // Utilisez qDebug() pour imprimer un message dans la console de débogage
               qDebug() << "Setting background color to magenta.";
               if (ACTION.toLower() == "criditation") {

             if (ACTION.toLower() == "analyser"){
                  qDebug() << "Setting background color to magenta.";
                  // Utilisez qDebug() pour imprimer un message dans la console de débogage
                  qDebug() << "Setting background color to magenta.";
                 qDebug() << "Setting background color to magenta.";
                 qDebug() << "Setting background color to magenta.";
               // Créer une palette
               QPalette palette = ui->table_checklist->palette();
               QPalette palette_2 = ui->table_checklist_2->palette();
               QPalette palette_3 = ui->table_checklist_3->palette();
               // Définir la couleur d'arrière-plan en vert
               palette.setColor(QPalette::Background, Qt::magenta);
               palette_2.setColor(QPalette::Background, Qt::magenta);
               palette_3.setColor(QPalette::Background, Qt::magenta);
               // Activer l'arrière-plan automatique
               ui->table_checklist->setAutoFillBackground(true);
               ui->table_checklist_2->setAutoFillBackground(true);
               ui->table_checklist_3->setAutoFillBackground(true);
               // Appliquer la palette au widget
               ui->table_checklist_2->setPalette(palette);
              // ui->table_checklist_3->setPalette(palette);
           }
       } /*else {
           messageBox.setText("Failed to add data to the database.");
       }*/

      // messageBox.exec();
   }



}
}

void auditui::on_bt_supp_clicked()
{
   AUDITS A;
        int NUM_D_to_delete = ui->le_numd->text().toInt();
        bool test = A.supprimer(NUM_D_to_delete);
        if(test)
        {

            ui->table_audits->setModel(A.afficher());
           // QMessageBox::information(this,QObject::tr("ok"),
           // QObject::tr("suppression effectuée\nClick OK to exit."),QMessageBox::Ok);
        }

        /*else
        {
        QMessageBox::information(this, tr("Not OK"), tr("Deletion was not successful. Click OK to exit."), QMessageBox::Ok);
        }*/

}


void auditui::on_pushButton_2_clicked()
{

        int NUM_D = ui->le_numd->text().toInt();

        // Récupérer la valeur sélectionnée dans le QComboBox
        QString ACTION = ui->le_action->currentText();

        QString DATE_AUDIT = ui->la_date->text();

        // Créer un objet AUDITS avec les paramètres
        AUDITS A(NUM_D, ACTION, DATE_AUDIT);

        // Ajouter les données à la base de données
        bool insertionSuccess = A.ajouter();

        // Mettre à jour le modèle de la table avec les données nouvellement ajoutées
        ui->table_audits->setModel(A.afficher());
      //  QMessageBox messageBox;


       // if (insertionSuccess) {
         //   messageBox.setText("Data added to the database successfully!");
        //} else {
          //  messageBox.setText("Failed to add data to the database.");
       // }

       // messageBox.exec();
    }

void auditui::on_stat_clicked()
{


    QSqlQueryModel *model = Am.afficher();

        if (!model) {
            qDebug() << "Error: QSqlQueryModel is null.";
            return;
        }

        int totalEmployes = model->rowCount();
        int controlerCount = 0;
        int analyserCount = 0;
        int conformerCount = 0;
        int criditationCount = 0;

        // Assuming 'action' is an attribute in the employe class
        int actionColumnIndex = model->record().indexOf("action");

        // Count actions
        for (int row = 0; row < totalEmployes; ++row) {
            QString action = model->data(model->index(row, actionColumnIndex)).toString().toLower();
            if (action == "controler") {
                controlerCount++;
            } else if (action == "analyser") {
                analyserCount++;
            } else if (action == "conformer") {
                conformerCount++;
            } else if (action == "criditation") {
                criditationCount++;
            }
        }

        // Calculate percentages
        double pourcentageControler = (totalEmployes > 0) ? ((double)controlerCount / totalEmployes) * 100 : 0;
        double pourcentageAnalyser = (totalEmployes > 0) ? ((double)analyserCount / totalEmployes) * 100 : 0;
        double pourcentageConformer = (totalEmployes > 0) ? ((double)conformerCount / totalEmployes) * 100 : 0;
        double pourcentageCriditation = (totalEmployes > 0) ? ((double)criditationCount / totalEmployes) * 100 : 0;

        // Create QPieSeries
        QPieSeries *series = new QPieSeries();

        // Add slices
        if (pourcentageControler > 0) {
            QPieSlice *sliceControler = new QPieSlice(QString("Controler (%1%)").arg(pourcentageControler), pourcentageControler);
            sliceControler->setColor(QColor("lightblue")); // Change color to lightblue
            series->append(sliceControler);
        }

        if (pourcentageAnalyser > 0) {
            QPieSlice *sliceAnalyser = new QPieSlice(QString("Analyser (%1%)").arg(pourcentageAnalyser), pourcentageAnalyser);
            sliceAnalyser->setColor(QColor("lightgreen")); // Change color to lightgreen
            series->append(sliceAnalyser);
        }

        if (pourcentageConformer > 0) {
            QPieSlice *sliceConformer = new QPieSlice(QString("Conformer (%1%)").arg(pourcentageConformer), pourcentageConformer);
            sliceConformer->setColor(QColor("lightcoral")); // Change color to lightcoral
            series->append(sliceConformer);
        }

        if (pourcentageCriditation > 0) {
            QPieSlice *sliceCriditation = new QPieSlice(QString("Criditation (%1%)").arg(pourcentageCriditation), pourcentageCriditation);
            sliceCriditation->setColor(QColor("lightyellow")); // Change color to lightyellow
            series->append(sliceCriditation);
        }

        // Create QChart
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique ACTIONS");

        // Customize legend
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);

        // Create QChartView
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Add rotation animation
        QPropertyAnimation *animation = new QPropertyAnimation(series, "slicesAngle");
        animation->setStartValue(0.0);
        animation->setEndValue(360.0);
        animation->setDuration(2000); // Animation duration in milliseconds

        // Set chart animation
        chart->setAnimationOptions(QChart::AllAnimations);
        chartView->setChart(chart);

        // Create QDialog
        chartDialog = new QDialog(this);
        chartDialog->setFixedSize(1080, 720);
        QVBoxLayout *layout = new QVBoxLayout(chartDialog);
        layout->addWidget(chartView);

        // Close button
        QPushButton *closeButton = new QPushButton("Fermer", chartDialog);
        connect(closeButton, &QPushButton::clicked, chartDialog, &QDialog::accept);
        layout->addWidget(closeButton);

        // Display the window
        chartDialog->exec();
    }

void auditui::on_tri_clicked()
{
   AUDITS A;
     QSqlQueryModel * result =A.tri_NUM_D();
     ui->table_audits->setModel(result);
}

void auditui::on_tri_2_clicked()
{
    AUDITS A;
      QSqlQueryModel * result =A.tri_DATE_AUDIT();
      ui->table_audits->setModel(result);
}

void auditui::on_chercher_textChanged(const QString &arg1)
{
    if(arg1!="")
           ui->table_audits->setModel(Am.rechercherAUDITS(arg1));
           else
               ui->table_audits->setModel(Am.rechercherAUDITS(arg1));
}
void auditui::on_le_pdf_clicked()
{

        QPdfWriter pdf("C:/Users/hammemi/Downloads/AUDITS(1)/AUDITS/AUDITS.pdf");
        QPainter painter(&pdf);
        int i = 4000;

        painter.setPen(Qt::darkCyan);
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(3000, 1400, "AUDITS");

        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(100, 100, 9400, 2500);
        painter.drawRect(100, 3000, 9400, 500);
        painter.setFont(QFont("Time New Roman", 9));
        painter.drawText(4400, 3300, "NUM_D");
        painter.drawText(400, 3300, "ACTION");
        painter.drawText(1750, 3300, "DATE_AUDIT");

        painter.drawRect(100, 3000, 9400, 9000);

        QSqlQuery query;
        query.prepare("SELECT * FROM AUDITS");
        query.exec();
        while (query.next())
        {
            painter.drawText(1350, i, query.value("NUM_D").toString());
            painter.drawText(2300, i, query.value("ACTION").toString());
            painter.drawText(3400, i, query.value("DATE_AUDIT").toString());
            i = i + 350;
        }

       // QMessageBox::information(this, QObject::tr("PDF Saved Successfully!"),
         //                        QObject::tr("PDF Saved Successfully!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }

void auditui::on_BtnEnregistrer_clicked()

        {
            QString dir = "C:/Users/Amal/Downloads/ddd/AUDITS(1)/AUDITS/AUDITS.pro";
            QDir().mkpath(dir);
            QString fileName = dir + "/AUDITS.pdf";
            QPdfWriter pdf(fileName);
            QPainter painter(&pdf);
            int i = 4000;

            painter.drawPixmap(QRect(100, 100, 2000, 2000), QPixmap("C:/Users/msi/Downloads/logo_p.png"));

            painter.setPen(Qt::red);
            painter.setFont(QFont("Time New Roman", 25));
            painter.drawText(3000, 1450, "Liste des AUDITS");

            painter.setPen(Qt::black);
            painter.setFont(QFont("Time New Roman", 15));
            painter.drawRect(100, 100, 9400, 2500);
            painter.drawRect(100, 3000, 9400, 500);
            painter.setFont(QFont("Time New Roman", 10));
            painter.drawText(4400, 3300, "NUM_D");
            painter.drawText(400, 3300, "ACTION");
            painter.drawText(1350, 3300, "DATE_AUDIT");

            painter.drawRect(100, 3000, 9400, 10700);

            QSqlQuery query;
            query.prepare("SELECT NUM_D, ACTION, DATE_AUDIT FROM AUDITS");
            query.exec();
            while (query.next())
            {
                painter.drawText(300, i, query.value("NUM_D").toString());
                painter.drawText(1500, i, query.value("ACTION").toString());
                painter.drawText(3000, i, query.value("DATE_AUDIT").toString());

                i = i + 500;
            }

            /*int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez-vous afficher le PDF ?",
                                                QMessageBox::Yes | QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile(dir + "/AUDITS.pdf"));
            }*/

            painter.end();
        }



void auditui::on_calendarWidget_activated(const QDate &)
{


    QDate selectedDate = ui->calendarWidget->selectedDate();
       qDebug() << "Selected date: " << selectedDate.toString("yyyy-MM-dd");

       QSqlQuery query;
       query.prepare("SELECT * FROM AUDITS WHERE DATE_AUDIT = :date");
       query.bindValue(":date", selectedDate.toString("yyyy-MM-dd"));

       if (query.exec()) {
           qDebug() << "Query executed successfully.";

           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery(query);

           // Vous pouvez également définir des noms de colonnes plus conviviaux
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_D"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("ACTION"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_AUDIT"));

           ui->calendrier->setModel(model);
       } else {
           qDebug() << "Error in SQL query: " << query.lastError().text();
       }
   }







void auditui::insertCalendar()
{



    editor->clear();
    QTextCursor cursor = editor->textCursor();
    cursor.beginEditBlock();

    QDate date(selectedDate.year(), selectedDate.month(), 1);
//! [5]

//! [6]
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setBackground(QColor("#e0e0e0"));
    tableFormat.setCellPadding(2);
    tableFormat.setCellSpacing(4);
//! [6] //! [7]
    QVector<QTextLength> constraints;
    constraints << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14);
    tableFormat.setColumnWidthConstraints(constraints);
//! [7]

//! [8]
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);
//! [8]

//! [9]
    QTextFrame *frame = cursor.currentFrame();
    QTextFrameFormat frameFormat = frame->frameFormat();
    frameFormat.setBorder(1);
    frame->setFrameFormat(frameFormat);
//! [9]

//! [10]
    QTextCharFormat format = cursor.charFormat();
    format.setFontPointSize(fontSize);

    QTextCharFormat boldFormat = format;
    boldFormat.setFontWeight(QFont::Bold);

    QTextCharFormat highlightedyellow = boldFormat;
    highlightedyellow.setBackground(Qt::yellow);
    QTextCharFormat highlightedred = boldFormat;
    highlightedred.setBackground(Qt::red);
    QTextCharFormat highlightedgreen = boldFormat;
    highlightedgreen.setBackground(Qt::green);
//! [10]

//! [11]
    for (int weekDay = 1; weekDay <= 7; ++weekDay) {
        QTextTableCell cell = table->cellAt(0, weekDay-1);
//! [11] //! [12]
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(QLocale::system().dayName(weekDay), boldFormat);
    }
//! [12]

//! [13]
    table->insertRows(table->rows(), 1);
//! [13]


    while (date.month() == selectedDate.month()) {
        int weekDay = date.dayOfWeek();
        QTextTableCell cell = table->cellAt(table->rows()-1, weekDay-1);
        QTextCursor cellCursor = cell.firstCursorPosition();
        QSqlQuery q;
        QVector<QDate> vec;
        q.prepare("select DATE_EV from Resevatoin ");
        if(q.exec()){
            while(q.next()){
            vec.push_back(q.value(0).toDate());
            }
        }

        QVectorIterator<QDate> i(vec);
        if (vec.contains(date)) {
            if ( vec.count(date) <= 3  ) {
                cellCursor.insertText(QString("%1").arg(date.day()), highlightedgreen);
            }
            else if( (vec.count(date) <= 5) && (vec.count(date) > 3) ) {
                cellCursor.insertText(QString("%1").arg(date.day()), highlightedyellow);

            }
            else if( (vec.count(date) > 5)) {
                cellCursor.insertText(QString("%1").arg(date.day()), highlightedred);

            }

        }
                else if(!vec.contains(date)) {
        cellCursor.insertText(QString("%1").arg(date.day()), format);
        }
        date = date.addDays(1);
        if (weekDay == 7 && date.month() == selectedDate.month())
            table->insertRows(table->rows(), 1);

    }
    cursor.endEditBlock();
//! [14]
    setWindowTitle(tr("Calendar for %1 %2"
        ).arg(QLocale::system().monthName(selectedDate.month())
        ).arg(selectedDate.year()));

}
//! [14]

//! [15]
void auditui::setFontSize(int size)
{
    fontSize = size;
    insertCalendar();
}
//! [15]

//! [16]
void auditui::setMonth(int month)
{
    selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
    insertCalendar();
}
//! [16]

//! [17]
void auditui::setYear(QDate date)
{
    selectedDate = QDate(date.year(), selectedDate.month(), selectedDate.day());
    insertCalendar();
}
//! [17]

