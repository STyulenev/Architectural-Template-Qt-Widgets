#include <Application.h>

#include "LanguageController.h"
#include "LoggingController.h"
#include "ThemeController.h"

#include <QFontDatabase>
#include <QStyleFactory>

namespace ATQW::Core {

Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
	Controllers::LoggingController::instance()->setDebugMessageHandler();
	
    setApplicationName("Architectural-Template-Qt-Widgets");
    setOrganizationName("Organization");
    setOrganizationDomain("organization.com");

    m_languageController = new Controllers::LanguageController(this);
    m_themeController    = new Controllers::ThemeController(this);
}

Application::~Application()
{

}

auto Application::launch() -> void
{
    connect(m_languageController, &Controllers::LanguageController::languageChanged, this, []() -> void {
        // ...
    });

    connect(m_themeController, &Controllers::ThemeController::themeChanged, this, &Application::setTheme);

    m_themeController->setTheme(2); // light-style
    setFont();

    this->setProperty("LanguageController", QVariant::fromValue<QObject*>(m_languageController));
    this->setProperty("ThemeController",    QVariant::fromValue<QObject*>(m_themeController));
    // ...
}

auto Application::setTheme(const QString& style) -> void
{
    qApp->setStyleSheet(style);
}

auto Application::setFont() -> void
{
    QFontDatabase::addApplicationFont(":/res/fonts/Helvetica.ttf");
}

} // namespace ATQW::Core
