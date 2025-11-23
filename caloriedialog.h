#ifndef CALORIEDIALOG_H
#define CALORIEDIALOG_H

#include <QDialog>

namespace Ui {
class caloriedialog;
}

class caloriedialog : public QDialog
{
    Q_OBJECT

public:
    explicit caloriedialog(QWidget *parent = nullptr);
    ~caloriedialog();

private:
    Ui::caloriedialog *ui;
};

#endif // CALORIEDIALOG_H
