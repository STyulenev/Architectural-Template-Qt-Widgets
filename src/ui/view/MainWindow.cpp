#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ApplicationSettings.h"
#include "Navigator.h"
#include "PageFactory.h"

#include <QTimer>
#include <QDateTime>

namespace ATQW::Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto state = ATQW::Settings::ApplicationSettings::getSetting()->getMainWindowsSetting();
    resize(state.first);
    restoreState(state.second);

    m_navigator = std::make_shared<ATQW::Pages::Navigator>(ui->stackedWidget, ATQW::Pages::getPage(ATQW::Pages::PageName::AUTHENTICATION_PAGE));

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() -> void {
        ui->dateTimeLabel->setText(QDateTime::currentDateTime().toString("hh:mm:ss dd-MM-yyyy dddd"));
    });
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    ATQW::Settings::ApplicationSettings::getSetting()->setMainWindowsSetting(size(), saveState());

    delete ui;
}

} // namespace ATQW::Views
