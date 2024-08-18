#pragma once

#include "BasePage.h"

namespace ATQW::Controllers {
    class LanguageController;
    class ThemeController;
}

namespace ATQW::ViewModels {
    class LanguageViewModel;
    class ThemeViewModel;
}

namespace Ui {
    class SettingPage;
}

namespace ATQW::Pages {

class SettingPage final : public BasePage
{
    Q_OBJECT

public:
    explicit SettingPage(QWidget* parent = nullptr);
    ~SettingPage();

protected:
    auto updatePage() -> void override;
    auto updatePage(QVariant data) -> void override;

private slots:
    auto on_logoutButton_clicked() -> void;
    auto on_backButton_clicked() -> void;
    auto on_languageComboBox_activated(int index) -> void;
    auto on_themeComboBox_activated(int index) -> void;

private:
    Ui::SettingPage* ui;
    Controllers::LanguageController* m_languageController;
    Controllers::ThemeController*    m_themeController;
    ViewModels::LanguageViewModel*   m_languageViewModel;
    ViewModels::ThemeViewModel*      m_themeViewModel;

};

} // namespace ATQW::Pages
