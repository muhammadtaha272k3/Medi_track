#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QPropertyAnimation>
#include <QWidget>
#include "signup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/images/Myresources/background.png); background-repeat: no-repeat; background-position: center;");

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
    bool found = false;

    while (true){

    }

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

