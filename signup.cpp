#include <QString>
#include <Qdebug>
#include "signup.h"
#include "addmoredetails.h"
#include "ui_signup.h"
#include "mainmenu.h"
#include "patient.h"


signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    connect(ui->calendarWidget, &QCalendarWidget::clicked,
            this, &signup::on_calendarWidget_clicked);

}

signup::~signup()
{
    delete ui;
}


void signup::on_calendarWidget_activated(const QDate &date)
{

}


void signup::on_calendarWidget_clicked(const QDate &date)
{
    QString dateStr = date.toString("dd-MM-yyyy");
    ui->label_6->setText(dateStr);
}


void signup::on_label_6_linkActivated(const QString &link)
{

}


void signup::on_pushButton_2_clicked()
{
    QString first = ui->lineEdit->text();
    QString last = ui->lineEdit_3->text();
    QString User = ui->lineEdit_2->text();
    QString user_pass = ui->lineEdit_4->text();
    QString date_of_birth = ui->label_6->text();

    patient * p = new patient(first,last,date_of_birth,User,user_pass);

    hide();
    addmoredetails *m = new addmoredetails(*p);
    m->setModal(true);
    m->exec();
}


void signup::on_pushButton_clicked()
{
    hide();
    mainmenu m;
    m.show();
}

