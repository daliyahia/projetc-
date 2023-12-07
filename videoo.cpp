#include "videoo.h"
#include "ui_video.h"
#include<QString>
#include<QDialog>



videoo::videoo(QWidget *parent):QDialog(parent),
    ui(new Ui::videoo)
    {

    ui->setupUi(this);

    Player =new QMediaPlayer();
    ui->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_seek_barckward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_seek_foward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->horizontalSlider_volume->setMinimum(0);
     ui->horizontalSlider_volume->setMaximum(100);
      ui->horizontalSlider_volume->setValue(30);
    Player->setVolume(ui->horizontalSlider_volume->value());
    connect(Player , &QMediaPlayer::durationChanged, this, &videoo::durationChanged);
    connect(Player , &QMediaPlayer::positionChanged, this, &videoo::positionChanged);

    ui->horizontalSlider_duration->setRange(0, Player->duration()/1000);
}

videoo::~videoo()
{
    delete ui;
}

void videoo::durationChanged(qint64 duration)
{
    mDuration= duration/1000;
    ui->horizontalSlider_duration->setMaximum(mDuration);
}

void videoo::positionChanged(qint64 duration)
{
    if(!ui->horizontalSlider_duration->isSliderDown())
    {
        ui->horizontalSlider_duration->setValue(duration/1000);
    }
    updateDuration(duration/1000);
}

void videoo::updateDuration(qint64 Duration)
{
    if(Duration || mDuration)
    {
        QTime CurrentTime(( Duration /3600) %60, (Duration / 60) % 60,Duration %60, (Duration * 1000)% 1000);
        QTime TotalTime((mDuration /3600) % 60, (mDuration/60) % 60, mDuration %60, (mDuration *1000)% 1000);
        QString Format ="";
        if(mDuration >3600) Format= "hh:mm:ss";
        else Format= "mm:ss";
        ui->label_current_time->setText(CurrentTime.toString(Format) );
        ui->label_total_time->setText(TotalTime.toString(Format) );
}
}

void videoo::on_actionopen_triggered()
{
    QString FileName =QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr( "MP4 Files (*.mp4)"));
    Video =new QVideoWidget();
    Video->setGeometry(5, 5, ui->groupBox_video->width()- 10,ui->groupBox_video->height()- 10 );
    Video->setParent(ui->groupBox_video);
    Player->setVideoOutput(Video);
    Player->setMedia(QUrl(FileName));
    Video->setVisible(true);
    Video->show();
}






void videoo::on_pushButton_play_pause_clicked()
{
    if( IS_Pause==true)
       {
        IS_Pause=false;
        Player->play();
        ui->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
       }
       else{
        IS_Pause= true;
        Player->pause();
        ui->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  }
}

void videoo::on_pushButton_stop_clicked()
{
    Player->stop();
}

void videoo::on_pushButton_seek_foward_clicked()
{
    ui->horizontalSlider_duration->setValue(ui->horizontalSlider_duration->value() + 20);
    Player->setPosition(ui->horizontalSlider_duration->value() *1000);
}

void videoo::on_pushButton_seek_barckward_clicked()
{
    ui->horizontalSlider_duration->setValue(ui->horizontalSlider_duration->value() - 20);
    Player->setPosition(ui->horizontalSlider_duration->value() *1000);
}

void videoo::on_horizontalSlider_duration_valueChanged(int value)
{

    Player->setPosition(value *1000);
}

void videoo::on_horizontalSlider_volume_valueChanged(int value)
{

     Player->setVolume(value);

}

void videoo::on_pushButton_volume_clicked()
{
    if(IS_Muted==false)
    {
        IS_Muted=true;
        ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        Player->setMuted(true);
    }
    else
    {
        IS_Muted=false;
        ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
         Player->setMuted(false);
    }
}
