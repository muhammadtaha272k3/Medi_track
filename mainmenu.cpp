#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "signup.h"
#include "day.h"
#include "patient.h"

#include <QString>
#include <QMenu>

mainmenu::mainmenu(patient &p ,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
    , p(p)

{

    ui->setupUi(this);
    connect (ui->comboBox, &QComboBox::currentIndexChanged,
        this, &mainmenu::ondataChanged_1);
    connect (ui->comboBox_2, &QComboBox::currentIndexChanged,
            this, &mainmenu::ondataChanged_2);

    ui->name->setText(p.getName());
    ui->agedata->setText(QString::number(p.getAge(), 'f', 2));

    QPushButton *btnMedicine = new QPushButton("Add Medicine", this);
    QMenu *menu = new QMenu(btnMedicine);
    btnMedicine->setMenu(menu);

}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::ondataChanged_1(int index){
    if (index == 0) {
        ui->label_7->setText(QString::number(p.getWeightKg(), 'f', 2));
    }
    // If selected lb
    else if (index == 1) {
        ui->label_7->setText(QString::number(p.getWeightLb(), 'f', 2));
    }
}

void mainmenu::ondataChanged_2(int index){
    if (index == 0) {
        QString temp = p.getHeight();

        double totalFeet = cm * 0.0328084;

        int feet = static_cast<int>(totalFeet);

        // Convert remaining fraction to inches
        double inches = (totalFeet - feet) * 12;

        // Format string
        QString result = QString("%1 ft %2 in")
                             .arg(feet)
                             .arg(static_cast<int>(inches));

         ui->label_9->setText(result);
    }
    else if (index == 1) {
        ui->label_9->setText(p.getHeight());
    }
}

void mainmenu::on_name_windowIconTextChanged(const QString &iconText)
{

}


void mainmenu::on_pushButton_clicked()
{

}

