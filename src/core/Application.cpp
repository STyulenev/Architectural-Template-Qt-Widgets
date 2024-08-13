#include <Application.h>

#include "LanguageController.h"

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

    this->setProperty("LanguageController", QVariant::fromValue<QObject*>(m_languageController));
    // ...
}

} // namespace ATQW::Core
