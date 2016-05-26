#ifndef STARTMENU_H
#define STARTMENU_H

#include <QDialog>
#include <QWidget>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;


};

#endif // STARTMENU_H
