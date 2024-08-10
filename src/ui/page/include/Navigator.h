#pragma once

#include "BasePage.h"

#include <QStack>
#include <QStackedWidget>

namespace ATQW::Pages {

class Navigator : public QObject
{
    Q_OBJECT

public:
    Navigator() = delete;
    explicit Navigator(QStackedWidget* container, Pages::BasePage* startPage);
    ~Navigator() = default;

private:
    auto connectPage(Pages::BasePage* page) -> void;
    auto disconnectPage(Pages::BasePage* page) -> void;

public slots:
    auto back() -> void;
    auto back(QVariant data) -> void;
    auto backTo(QString pageName) -> void;
    auto backToAndNext(QString PageName, Pages::BasePage* page) -> void;
    auto next(Pages::BasePage* page) -> void;
    auto replace(Pages::BasePage* page) -> void;

private:
    QStackedWidget* m_container;
    QStack<Pages::BasePage*> m_stackWidgets;

};

} // namespace ATQW::Pages
