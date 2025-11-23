#include "graphshow.h"
#include "ui_graphshow.h"

stepgraph::stepgraph(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stepgraph)
{
    ui->setupUi(this);
}

stepgraph::~stepgraph()
{
    delete ui;
}
