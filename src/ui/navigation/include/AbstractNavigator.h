#pragma once

#include "BasePage.h"

#include <QStack>
#include <QStackedWidget>

namespace ATQW::Navigation {

class AbstractNavigator : public QObject
{
    Q_OBJECT

public:
    AbstractNavigator() = delete;
    explicit AbstractNavigator(QStackedWidget* container, QObject* parent = nullptr) :
        m_container(container),
        QObject(parent) { };
    virtual ~AbstractNavigator() = default;

protected:
    virtual auto connectPage(ATQW::Pages::BasePage* page) -> void = 0;
    virtual auto disconnectPage(ATQW::Pages::BasePage* page) -> void = 0;

public slots:
    virtual auto back() -> void = 0;
    virtual auto back(QVariant data) -> void = 0;
    virtual auto backTo(QString pageName) -> void = 0;
    virtual auto backToAndNext(QString PageName, ATQW::Pages::BasePage* page) -> void = 0;
    virtual auto next(ATQW::Pages::BasePage* page) -> void = 0;
    virtual auto replace(ATQW::Pages::BasePage* page) -> void = 0;

protected:
    QStackedWidget* m_container;
    QStack<ATQW::Pages::BasePage*> m_stackWidgets;

};

} // namespace ATQW::Navigation
