#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedMemory>
#include <QTimer>
#include <windows.h>
#include <QDebug>
#include "dashboard.h"
#include "AC_sharedMemory.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_Start_clicked();
    void readData();
private:
    Ui::MainWindow *ui;
    void acMemoryMapStart();

    HANDLE  acHandle;
    DashBoard *dashBoard;
    graphics_mmap *graphicsBuffer;
    physics_mmap *physicsBuffer;
    statics_mmap *staticBuffer;
    QTimer *timeToRead;
};
#endif // MAINWINDOW_H
