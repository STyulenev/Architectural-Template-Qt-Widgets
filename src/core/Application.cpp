#include <Application.h>

namespace ATQW::Core {

Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
    setOrganizationName("Organization");
    setOrganizationDomain("organization.com");
}

Application::~Application()
{

}

auto Application::launch() -> void
{
    // ...
}

} // namespace ATQW::Core
