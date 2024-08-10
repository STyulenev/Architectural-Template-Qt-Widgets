#pragma once

#include "BasePage.h"

namespace ATQW::Pages {

// Main Pages
enum PageName {
    AUTHENTICATION_PAGE = 0,
    MAIN_MENU_PAGE ,
    SETTING_PAGE
};

BasePage* getPage(const PageName&& Page);

} // namespace ATQW::Pages
