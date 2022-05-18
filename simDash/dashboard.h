#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <AC_sharedMemory.h>
namespace Ui {
class DashBoard;
}

class DashBoard : public QWidget
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();
    void reFreshDashboard(physics_mmap *data);
private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
