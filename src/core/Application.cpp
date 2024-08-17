#include <Application.h>

#include "LanguageController.h"

#include <QFile>
#include <QStyleFactory>
#include <QFontDatabase>

namespace ATQW::Core {

Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
    setApplicationName("Architectural-Template-Qt-Widgets");
    setOrganizationName("Organization");
    setOrganizationDomain("organization.com");

    m_languageController = new Controllers::LanguageController(this);
}

Application::~Application()
{

}

auto Application::launch() -> void
{
    connect(m_languageController, &Controllers::LanguageController::languageChanged, this, []() -> void {
        // ...
    });

    setTheme();
    setFort();

    this->setProperty("LanguageController", QVariant::fromValue<QObject*>(m_languageController));
    // ...
}

auto Application::setTheme() -> void
{
    QFile styleFile(":/res/styles/light-style.css");
    if (styleFile.open(QIODevice::ReadOnly)) {
        QString appSlyle = QString(styleFile.readAll());
        qApp->setStyleSheet(appSlyle);
        styleFile.close();
    }
}

auto Application::setFort() -> void
{
    QFontDatabase::addApplicationFont(":/res/fonts/Helvetica.ttf");
}

} // namespace ATQW::Core
