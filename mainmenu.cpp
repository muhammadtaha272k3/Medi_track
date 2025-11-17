#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "signup.h"
#include "day.h"
#include "patient.h"

mainmenu::mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_name_windowIconTextChanged(const QString &iconText)
{

}

