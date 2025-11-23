#include "caloriedialog.h"
#include "ui_caloriedialog.h"

caloriedialog::caloriedialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::caloriedialog)
{
    ui->setupUi(this);
}

caloriedialog::~caloriedialog()
{
    delete ui;
}
