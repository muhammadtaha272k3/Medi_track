#ifndef GRAPHSHOW_H
#define GRAPHSHOW_H

#include <QDialog>

namespace Ui {
class stepgraph;
}

class stepgraph : public QDialog
{
    Q_OBJECT

public:
    explicit stepgraph(QWidget *parent = nullptr);
    ~stepgraph();

private:
    Ui::stepgraph *ui;
};

#endif // GRAPHSHOW_H
