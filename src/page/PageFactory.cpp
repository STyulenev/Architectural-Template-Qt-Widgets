#include "PageFactory.h"

#include "assert.h"

#include "AuthenticationPage.h"
#include "MainMenuPage.h"
#include "SettingPage.h"

namespace ATQW::Pages {

BasePage* getPage(const PageName&& Page)
{
    switch(Page) {
    case PageName::AUTHENTICATION_PAGE:
        return new AuthenticationPage();
    case PageName::MAIN_MENU_PAGE:
        return new MainMenuPage();
    case PageName::SETTING_PAGE:
        return new SettingPage();
	// ...
    default:
        assert("PageFactory - unknown Page");
    }

    throw std::bad_function_call();
}

} // namespace ATQW::Pages
