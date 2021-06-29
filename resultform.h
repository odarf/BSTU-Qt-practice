#ifndef RESULTFORM_H
#define RESULTFORM_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QSettings>
#include <QVariant>
#include <QCloseEvent>

namespace Ui {
class resultForm;
}

class resultForm : public QWidget
{
    Q_OBJECT

public:
    explicit resultForm(QWidget *parent = nullptr);
    ~resultForm();
    void musicStop();
private slots:

private:
    Ui::resultForm *ui;
    QMediaPlayer *player;
    void closeEvent(QCloseEvent *event);
};

#endif // RESULTFORM_H
