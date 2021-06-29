#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voteform.h"
#include "resultform.h"
#include <QtMultimedia/QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_voteBtn_clicked()
{
    voteForm *voteform = new voteForm;
    voteform->show();
}



void MainWindow::on_resultBtn_clicked()
{
    resultForm *resultform = new resultForm;
    resultform->show();

}
