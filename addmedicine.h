#ifndef ADDMEDICINE_H
#define ADDMEDICINE_H

#include <QDialog>

namespace Ui {
class addmedicine;
}

class addmedicine : public QDialog
{
    Q_OBJECT

public:
    explicit addmedicine(QWidget *parent = nullptr);
    ~addmedicine();

private:
    Ui::addmedicine *ui;
};

#endif // ADDMEDICINE_H
