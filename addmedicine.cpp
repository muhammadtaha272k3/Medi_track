#include "addmedicine.h"
#include "ui_addmedicine.h"

addmedicine::addmedicine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addmedicine)
{
    ui->setupUi(this);
}

addmedicine::~addmedicine()
{
    delete ui;
}
