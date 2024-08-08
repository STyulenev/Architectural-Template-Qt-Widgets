#include "MainWindow.h"
#include "./ui_MainWindow.h"

namespace ATQW::Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace ATQW::Views
