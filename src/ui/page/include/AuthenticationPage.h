#pragma once

#include "BasePage.h"

namespace Ui {
    class AuthenticationPage;
}

namespace ATQW::Pages {

class AuthenticationPage final : public BasePage
{
    Q_OBJECT

public:
    explicit AuthenticationPage(QWidget* parent = nullptr);
    ~AuthenticationPage();

protected:
    auto updatePage() -> void override;
    auto updatePage(QVariant data) -> void override;

private slots:
    auto on_enterButton_clicked() -> void;

private:
    Ui::AuthenticationPage* ui;

};

} // namespace ATQW::Pages
