#ifndef ZX_H
#define ZX_H
#include "qcustomplot.h"


#include <QWidget>

namespace Ui {
class zx;
}

class zx : public QWidget
{
    Q_OBJECT

public:
    explicit zx(QWidget *parent = 0);
    void data_up();
    ~zx();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::zx *ui;
    QCPCurve *fermatSpiral1;
};

#endif // ZX_H
