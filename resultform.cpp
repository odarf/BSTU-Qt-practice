#include "resultform.h"
#include "ui_resultform.h"
#include <QVariant>
#include <QSettings>
#include <QDebug>

resultForm::resultForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultForm)
{
    player = new QMediaPlayer();
    player->setMedia(QUrl("C:/Users/madven/Documents/laba2Viboryi/res/voteEnds.mp3"));
        player->play();
    ui->setupUi(this);
    QSettings sett("C:/Users/madven/Documents/laba2Viboryi/kandidati.ini", QSettings::IniFormat);
    sett.setIniCodec( "Windows-1251" );
    this->ui->label->setText(sett.value("text/label1", "").toString());
    this->ui->label_2->setText(sett.value("text/label2", "").toString());
    this->ui->label_3->setText(sett.value("text/label3", "").toString());
    this->ui->label_4->setText(sett.value("text/label4", "").toString());
    this->ui->label_5->setText(sett.value("text/label5", "").toString());
    this->ui->label_6->setText(sett.value("results/sum", "").toString());
    this->ui->label_9->setText(sett.value("results/nedeistvitelnie", "").toString());
    double a=sett.value("results/kandidat1", "").toDouble();
    double b=sett.value("results/sum", "").toDouble();
    this->ui->label_10->setNum((a/b)*100);
        double c=sett.value("results/kandidat2", "").toDouble();
        double d=sett.value("results/sum", "").toDouble();
        this->ui->label_11->setNum((c/d)*100);
            double e=sett.value("results/kandidat3", "").toDouble();
            double f=sett.value("results/sum", "").toDouble();
            this->ui->label_12->setNum((e/f)*100);
                double g=sett.value("results/kandidat4", "").toDouble();
                double h=sett.value("results/sum", "").toDouble();
                this->ui->label_13->setNum((g/h)*100);
                    double k=sett.value("results/kandidat5", "").toDouble();
                    double l=sett.value("results/sum", "").toDouble();
                    this->ui->label_14->setNum((k/l)*100);



}

resultForm::~resultForm()
{
    delete ui;
    musicStop();
}

void resultForm::closeEvent(QCloseEvent *event)
{

    musicStop();

}

void resultForm::musicStop()
{
    player->stop();
}

