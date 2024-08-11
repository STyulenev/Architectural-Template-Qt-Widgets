#pragma once

#include "AbstractNavigator.h"

namespace ATQW::Navigation {

class Navigator final : public AbstractNavigator
{

public:
    Navigator() = delete;
    explicit Navigator(QStackedWidget* container, ATQW::Pages::BasePage* startPage, QObject* parent = nullptr);
    ~Navigator() = default;

protected:
    auto connectPage(ATQW::Pages::BasePage* page) -> void override;
    auto disconnectPage(ATQW::Pages::BasePage* page) -> void override;

public slots:
    auto back() -> void override;
    auto back(QVariant data) -> void override;
    auto backTo(QString pageName) -> void override;
    auto backToAndNext(QString PageName, ATQW::Pages::BasePage* page) -> void override;
    auto next(ATQW::Pages::BasePage* page) -> void override;
    auto replace(ATQW::Pages::BasePage* page) -> void override;

};

} // namespace ATQW::Navigation
