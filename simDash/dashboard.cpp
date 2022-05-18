#include "dashboard.h"
#include "ui_dashboard.h"
#include <QDebug>
#
DashBoard::DashBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashBoard)
{
    ui->setupUi(this);
}

DashBoard::~DashBoard()
{
    delete ui;
}
void DashBoard::reFreshDashboard(physics_mmap *data)
{
//    uint16_t speedd = data->speedKmh;
//    qDebug()<<"Speed ---"<<data->speedKmh;
    qDebug()<<"gear ---"<<(data->gear-1);
    ui->td_speed->setText(QString::number((uint16_t)data->speedKmh));
    if(data->gear == 0)
    {
        ui->td_gear->setText("R");
    }
    else if (data->gear == 1)
    {
        ui->td_gear->setText("N");
    }
    else
    {
        ui->td_gear->setText(QString::number((uint16_t)(data->gear)-1));
    }

    //ui->td_position->setText(QString::number((uint16_t)data.));
}
