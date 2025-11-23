#ifndef ADDMOREDETAILS_H
#define ADDMOREDETAILS_H

#include <QDialog>
#include <QString>
#include "patient.h"
#include "day.h"
#include "caretaker.h"
#include "month.h"
#include "queue"



namespace Ui {
class addmoredetails;
}

class addmoredetails : public QDialog
{
    Q_OBJECT

public:
    explicit addmoredetails(patient &p,QWidget *parent = nullptr);
    ~addmoredetails();

private slots:
    patient &pat;
    void on_comboBox_activated(int index);
    void onUnitChanged(int index);
    void onUnitChanged_2(int index);
    void on_pushButton_clicked();

private:
    Ui::addmoredetails *ui;
};

#endif // ADDMOREDETAILS_H
