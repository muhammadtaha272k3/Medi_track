#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QString>
#include "patient.h"

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(
        patient &p,
        QWidget *parent = nullptr);

    ~mainmenu();

private slots:
    patient &p;
    void on_name_windowIconTextChanged(const QString &iconText);
    void ondataChanged_1(int index);
    void ondataChanged_2(int index);


    void on_pushButton_clicked();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
