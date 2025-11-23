#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QPropertyAnimation>
#include <QWidget>
#include "signup.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->login,SIGNAL(clicked()),
            this,SLOT(login()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString user =ui->usernameinput->text();
    QString pass1 =ui->passwordinput->text();

    hide();
    mainmenu *m = new mainmenu(&p);
    m.setModal(true);
    m.exec();
}


void MainWindow::on_login_pressed()
{

}



void MainWindow::on_signup_clicked()
{
    hide();
    signup sign;
    sign.setModal(true);
    sign.exec();
}

