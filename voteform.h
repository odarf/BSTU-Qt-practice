#ifndef VOTEFORM_H
#define VOTEFORM_H

#include <QWidget>
#include <QMovie>
#include <QtMultimedia/QMediaPlayer>
#include <QCloseEvent>
#include <QSettings>
#include <QVariant>

namespace Ui {
class voteForm;
}

class voteForm : public QWidget
{
    Q_OBJECT

public:
    explicit voteForm(QWidget *parent = nullptr);
    ~voteForm();
    void musicStop();
private slots:
    void setSpeedMovie(int);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::voteForm *ui;
    QMovie mo;
        double m;
    QMediaPlayer *player;
    void closeEvent(QCloseEvent *event);
};

#endif // VOTEFORM_H
