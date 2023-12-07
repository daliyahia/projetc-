#ifndef DIALOGVIDEO_H
#define DIALOGVIDEO_H

#include <QDialog>
#include<QtMultimedia>
#include<QtMultimediaWidgets>
//#include<QTCore>
#include<QtWidgets>
#include<QtGui>

namespace Ui {
class Dialogvideo;
}

class Dialogvideo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogvideo(QWidget *parent = nullptr);
    ~Dialogvideo();

private slots:

    void durationChanged(qint64 duration);

    void positionChanged(qint64 duration);

    void on_pushButton_seek_barckward_clicked();

    void on_pushButton_play_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_seek_foward_clicked();

    void on_pushButton_volume_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

    void on_horizontalSlider_duration_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_Ouvrir_clicked();

private:
    Ui::Dialogvideo *ui;
    QMediaPlayer *Player;
     QVideoWidget *Video;
     qint64 mDuration;
     bool IS_Pause=true;
     bool IS_Muted= false;
     void updateDuration(qint64 Duration);
};

#endif // DIALOGVIDEO_H
