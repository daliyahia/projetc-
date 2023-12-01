#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

    private slots:
        void on_Button_employer_clicked();

        void on_Button_Quitter_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
