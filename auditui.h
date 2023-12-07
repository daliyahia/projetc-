#ifndef AUDITUI_H
#define AUDITUI_H

#include <QDialog>
#include "audits.h"
#include "calendrier.h"

namespace Ui {
class auditui;
}

class auditui : public QDialog
{
    Q_OBJECT

public:
    explicit auditui(QWidget *parent = nullptr);
    ~auditui();

 private slots:
    void on_pb_ajouter_clicked();



    void on_bt_supp_clicked();



    void on_pushButton_2_clicked();

    void on_stat_clicked();

    void on_tri_clicked();

    void on_tri_2_clicked();

    void on_chercher_textChanged(const QString &arg1);

   // void on_cherch_clicked();



    void on_BtnEnregistrer_clicked();

    void on_le_pdf_clicked();



    void on_calendarWidget_activated(const QDate &date);
    void setFontSize(int size);
    void setMonth(int month);
    void setYear(QDate date);
    void insertCalendar();

private:
    Ui::auditui *ui;
    QDialog *chartDialog;
     AUDITS Am;

     int fontSize;
     QDate selectedDate;
     QTextBrowser *editor;
};

#endif // AUDITUI_H
