#include "addmoredetails.h"
#include "ui_addmoredetails.h"
#include "patient.h"
#include "mainmenu.h"

#include <string>
#include <QString>

addmoredetails::addmoredetails(patient &p,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addmoredetails)
    , pat(p)
{
    ui->setupUi(this);
    connect (ui->comboBox, &QComboBox::currentIndexChanged,
        this, &addmoredetails::onUnitChanged);
    connect (ui->comboBox_2, &QComboBox::currentIndexChanged,
            this, &addmoredetails::onUnitChanged_2);

}

addmoredetails::~addmoredetails()
{
    delete ui;
}

void addmoredetails::on_comboBox_activated(int index)
{

}

void addmoredetails::onUnitChanged(int index)
{
    double inputValue = ui->lineEdit->text().toDouble();

    if (index == 0) {
        pat.setWeightKg(inputValue);
        ui->lineEdit->setText(QString::number(pat.getWeightKg(), 'f', 2));
    }
    // If selected lb
    else if (index == 1) {
        pat.setWeightlb(inputValue);
        ui->lineEdit->setText(QString::number(pat.getWeightLb(), 'f', 2));
    }
}
void addmoredetails::onUnitChanged_2(int index)
{
    double inputValue = ui->lineEdit_2->text().toDouble();

    if (index == 0) {
        double temp2 = ui->lineEdit_2->text().toDouble() * 30.48;
        QString s = QString::number(temp2, 'f', 2);
        pat.setHeight(s);
        ui->lineEdit_2->setText(s);
    }

    else if (index == 1) {
        pat.setHeight(ui->lineEdit_2->text());
        ui->lineEdit_2->setText(QString::number(pat.getWeightKg(), 'f', 2));
    }
}

void addmoredetails::on_pushButton_clicked()
{
    pat.setContactInfo(ui->lineEdit_5->text());
    pat.setBloodGroup(ui->lineEdit_3->text());
    pat.setGender(ui->lineEdit_4->text());
    pat.setHeight(ui->lineEdit_2->text());
    mainmenu *m = new mainmenu(pat);
    m->setModal(true);
    m->exec();
}

