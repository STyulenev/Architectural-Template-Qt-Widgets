#pragma once

#include "BasePage.h"

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

private:
    Ui::SettingPage* ui;

};

} // namespace ATQW::Pages
