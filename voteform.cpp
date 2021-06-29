#include "voteform.h"
#include "ui_voteform.h"
#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>

voteForm::voteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::voteForm)
{

    player = new QMediaPlayer();
    player->setMedia(QUrl("C:/Users/madven/Documents/laba2Viboryi/res/ricardoMusic.mp3"));
        player->play();
    ui->setupUi(this);
    ui->label_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->label_3->setStyleSheet("color: rgb(255, 255, 255)");
    ui->label_4->setStyleSheet("color: rgb(255, 255, 255)");
    ui->label_5->setStyleSheet("color: rgb(255, 255, 255)");
    ui->label_6->setStyleSheet("color: rgb(255, 255, 255)");

    QPixmap pix("C:/Users/madven/Documents/laba2Viboryi/res/ricardo.gif");
        m = double(pix.width())/pix.height();
        mo.setFileName("C:/Users/madven/Documents/laba2Viboryi/res/ricardo.gif");
        ui->label->setMovie(&mo);
        mo.start();

        QSettings sett("C:/Users/madven/Documents/laba2Viboryi/kandidati.ini", QSettings::IniFormat);
        sett.setIniCodec( "Windows-1251" );
        this->ui->label_2->setText(sett.value("text/label1", "").toString());
        this->ui->label_3->setText(sett.value("text/label2", "").toString());
        this->ui->label_4->setText(sett.value("text/label3", "").toString());
        this->ui->label_5->setText(sett.value("text/label4", "").toString());
        this->ui->label_6->setText(sett.value("text/label5", "").toString());
}

static int sum=0;
static int badFormCounter=0;
static int chBx1=0;
static int chBx2=0;
static int chBx3=0;
static int chBx4=0;
static int chBx5=0;

void voteForm::musicStop()
{
    player->stop();
    qDebug()<<123;

}

void voteForm::closeEvent(QCloseEvent *event)
{

    musicStop();

}

voteForm::~voteForm()
{
    delete ui;
    musicStop();
}

void voteForm::setSpeedMovie(int s)
{
    mo.setSpeed(s);
}




void voteForm::on_pushButton_clicked()
{
    sum++;
    chBx1+=(int)(ui->checkBox->isChecked());
    chBx2+=(int)(ui->checkBox_2->isChecked());
    chBx3+=(int)(ui->checkBox_3->isChecked());
    chBx4+=(int)(ui->checkBox_4->isChecked());
    chBx5+=(int)(ui->checkBox_5->isChecked());

    if(((chBx1 && chBx2 && chBx3) || (chBx2 && chBx3 && chBx4) || (chBx3 && chBx4 && chBx5) ||
        (chBx1 && chBx2 && chBx4) || (chBx1 && chBx2 && chBx5) || (chBx1 && chBx3 && chBx4) ||
        (chBx1 && chBx3 && chBx5) || (chBx1 && chBx4 && chBx5) || (chBx2 && chBx3 && chBx5) ||
        (chBx1 && chBx2 && chBx3))==true)
    {
        badFormCounter++;
            qDebug()<<666;
    }



        QSettings sett("C:/Users/madven/Documents/laba2Viboryi/kandidati.ini", QSettings::IniFormat);
        sett.setValue("results/kandidat1", chBx1);
        sett.setValue("results/kandidat2", chBx2);
        sett.setValue("results/kandidat3", chBx3);
        sett.setValue("results/kandidat4", chBx4);
        sett.setValue("results/kandidat5", chBx5);
        sett.setValue("results/nedeistvitelnie", badFormCounter);
        sett.setValue("results/sum", sum);


        voteForm::~voteForm();
}

void voteForm::on_pushButton_2_clicked()
{
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->checkBox_4->setCheckState(Qt::Unchecked);
    ui->checkBox_5->setCheckState(Qt::Unchecked);
}
