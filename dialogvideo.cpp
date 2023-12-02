#include "dialogvideo.h"
#include "ui_dialogvideo.h"

Dialogvideo::Dialogvideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogvideo)
{
    ui->setupUi(this);
}

Dialogvideo::~Dialogvideo()
{
    delete ui;
}
