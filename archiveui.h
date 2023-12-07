#ifndef ARCHIVEUI_H
#define ARCHIVEUI_H

#include <QDialog>

namespace Ui {
class archiveui;
}

class archiveui : public QDialog
{
    Q_OBJECT

public:
    explicit archiveui(QWidget *parent = nullptr);
    ~archiveui();

private slots:
    void on_pushButton_ajouter_m_clicked();
    void on_bouton_supp_clicked();

    void on_pushButton_3_clicked();

    void on_searchButton_clicked();

    void on_ImportButton_clicked();

    void on_historique_clicked();

    void on_id_clicked();


    void on_statistique_mariem_clicked();

    void on_PDF_mariem_clicked();

    void on_arduino_clicked();

    void on_e_idE_cursorPositionChanged(int arg1, int arg2);

    void on_e_id_cursorPositionChanged(int arg1, int arg2);




    void on_pushButton_4_clicked();

    void on_pushButton__modifier_m_clicked();
    void setdata();

private:
    Ui::archiveui *ui;
    int selectedId;
    QString etatformulaire;
    int endusavec;
    QByteArray data;
};

#endif // ARCHIVEUI_H
