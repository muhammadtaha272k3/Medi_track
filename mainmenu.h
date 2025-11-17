#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_name_windowIconTextChanged(const QString &iconText);

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
