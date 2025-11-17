#include <QString>
#include <Qdebug>
#include "signup.h"
#include "ui_signup.h"
#include "mainmenu.h"

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
    QString first = ui->label_2->text();
    QString last = ui->label_3->text();
    QString User = ui->label->text();
    QString user pass = ui->label->text();

    mainmenu m;
    m.setModal(true);
    m.exec();

}


void signup::on_pushButton_clicked()
{

}

