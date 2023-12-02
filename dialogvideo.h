#ifndef DIALOGVIDEO_H
#define DIALOGVIDEO_H

#include <QDialog>

namespace Ui {
class Dialogvideo;
}

class Dialogvideo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogvideo(QWidget *parent = nullptr);
    ~Dialogvideo();

private:
    Ui::Dialogvideo *ui;
};

#endif // DIALOGVIDEO_H
