#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ApplicationSettings.h"
#include "Navigator.h"
#include "PageFactory.h"

#include <QAction>
#include <QApplication>
#include <QDateTime>
#include <QMenu>
#include <QStyle>
#include <QTimer>

namespace ATQW::Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Системный трей
    m_systemTray = new QSystemTrayIcon(this);
    m_systemTray->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    m_systemTray->setToolTip(qApp->applicationName());

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction("Развернуть окно", this);
    QAction* quitAction = new QAction("Выход", this);

    connect(viewWindow, &QAction::triggered, this, &MainWindow::show);
    connect(quitAction, &QAction::triggered, this, [this]() -> void {
        exit = true;
        qApp->quit();
    });

    menu->addAction(viewWindow);
    menu->addAction(quitAction);
    m_systemTray->setContextMenu(menu);

    m_systemTray->show();

    connect(m_systemTray, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);

    // Предыдущее состояние
    auto state = ATQW::Settings::ApplicationSettings::getSetting()->getMainWindowsSetting();
    resize(state.first);
    restoreState(state.second);

    // Навигатор
    m_navigator = std::make_shared<ATQW::Pages::Navigator>(ui->stackedWidget, ATQW::Pages::getPage(ATQW::Pages::PageName::AUTHENTICATION_PAGE));

    // Время/дата
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

auto MainWindow::closeEvent(QCloseEvent* event) -> void
{
    if (!exit) {
        m_systemTray->showMessage(qApp->applicationName(), QObject::tr("Приложение свернуто."), QSystemTrayIcon::Information);

        event->ignore();
        this->hide();
    }
}

auto MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason) -> void
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if (this->isHidden()) {
            this->show();
        }
        break;
    case QSystemTrayIcon::MiddleClick:
        this->show();
        break;
    default:
        break;
    }
}

} // namespace ATQW::Views
