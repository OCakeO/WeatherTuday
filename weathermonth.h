#ifndef WEATHERMONTH_H
#define WEATHERMONTH_H

#include <QWidget>

namespace Ui {
class weatherMonth;
}

class weatherMonth : public QWidget
{
    Q_OBJECT

public:
    explicit weatherMonth(QWidget *parent = nullptr);
    ~weatherMonth();

private:
    Ui::weatherMonth *ui;
};

#endif // WEATHERMONTH_H
