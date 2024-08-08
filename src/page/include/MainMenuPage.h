#pragma once

#include "BasePage.h"

namespace Ui {
    class MainMenuPage;
}

namespace ATQW::Pages {

class MainMenuPage final : public BasePage
{
    Q_OBJECT

public:
    explicit MainMenuPage(QWidget* parent = nullptr);
    ~MainMenuPage();

protected:
    auto updatePage() -> void override;
    auto updatePage(QVariant data) -> void override;

private slots:
    auto on_settingPageButton_clicked() -> void;
    auto on_closeButton_clicked() -> void;

private:
    Ui::MainMenuPage* ui;

};

} // namespace ATQW::Pages
