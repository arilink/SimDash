#include "mainwindow.h"
#include "ui_mainwindow.h"
#define AC_S "Local\\acpmf_physics"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dashBoard = new DashBoard();
    timeToRead = new QTimer(this);
    connect(timeToRead, SIGNAL(timeout()), this, SLOT(readData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_Start_clicked()
{
    acMemoryMapStart();
    dashBoard->show();
}

void MainWindow::acMemoryMapStart()
{
    acHandle = OpenFileMappingA(PAGE_READONLY,false,AC_S);
    if(acHandle == NULL)
    {
        qDebug()<<"Could Not Open AC memory map!!!";
    }
    else {
        qDebug()<<"Open AC memory map Success. Start to read !!!";
        //physicsBuffer = (physics_mmap*)MapViewOfFile(acHandle,PAGE_READONLY,0,0,sizeof (physics_mmap));
        //dashBoard->
        timeToRead->start(16);
    }

}

void MainWindow::readData()
{
    physicsBuffer = (physics_mmap*)MapViewOfFile(acHandle,PAGE_READONLY,0,0,sizeof (physics_mmap));
    dashBoard->reFreshDashboard(physicsBuffer);
    //qDebug()<<"Speed:"<<physicsBuffer->speedKmh;
}
