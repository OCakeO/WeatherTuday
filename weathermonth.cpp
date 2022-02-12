#include "weathermonth.h"
#include "ui_weathermonth.h"

weatherMonth::weatherMonth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::weatherMonth)
{
    ui->setupUi(this);
}

weatherMonth::~weatherMonth()
{
    delete ui;
}
