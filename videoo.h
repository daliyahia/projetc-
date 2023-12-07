#ifndef VIDEOO_H
#define VIDEOO_H

#include <QMainWindow>
#include<QtMultimedia>
#include<QtMultimediaWidgets>
#include<QTCore>
#include<QtWidgets>
#include<QtGui>

namespace Ui {
class videoo;
}

class videoo : public QDialog
{
    Q_OBJECT

public:
    explicit videoo(QWidget *parent = nullptr);
    ~videoo();

private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 duration);

    void on_actionopen_triggered();

    void on_horizontalSlider_duration_valueChanged(int value);

     void on_pushButton_play_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_volume_clicked();

     void on_horizontalSlider_volume_valueChanged(int value);

     void on_pushButton_seek_barckward_clicked();

    void on_pushButton_seek_foward_clicked();



private:
    Ui::videoo*ui;
    QMediaPlayer *Player;
     QVideoWidget *Video;
     qint64 mDuration;
     bool IS_Pause=true;
     bool IS_Muted= false;
     void updateDuration(qint64 Duration);
};

#endif // VIDEOO_H
