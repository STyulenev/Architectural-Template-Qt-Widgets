#include "Navigator.h"

namespace ATQW::Views {

Navigator::Navigator(QStackedWidget* container, Pages::BasePage* startPage) :
    m_container(container)
{
    connectPage(startPage);
    this->m_stackWidgets.append(startPage);
    m_container->addWidget(m_stackWidgets.last());
    m_container->setCurrentIndex(0);
}

auto Navigator::next(Pages::BasePage* page) -> void
{
    disconnectPage(m_stackWidgets.last());
    connectPage(page);
    m_stackWidgets.append(page);
    m_container->addWidget(page);
    m_container->setCurrentWidget(page);
}

auto Navigator::back() -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    connectPage(m_stackWidgets.last());
    m_container->setCurrentWidget(m_stackWidgets.last());
    m_stackWidgets.last()->updatePage();
}

auto Navigator::back(QVariant data) -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    connectPage(m_stackWidgets.last());
    m_container->setCurrentWidget(m_stackWidgets.last());
    m_stackWidgets.last()->updatePage(data);
}

auto Navigator::backTo(QString pageName) -> void
{
    while (!m_stackWidgets.isEmpty()) {
        if (m_stackWidgets.last()->pageName() == pageName) {
            connectPage(m_stackWidgets.last());
            m_container->setCurrentWidget(m_stackWidgets.last());
            break;
        } else {
            m_container->removeWidget(m_stackWidgets.last());
            delete m_stackWidgets.last();
            m_stackWidgets.removeLast();
        }
    }
}

auto Navigator::backToAndNext(QString PageName, Pages::BasePage* page) -> void
{
    while (!m_stackWidgets.isEmpty()) {
        if (m_stackWidgets.last()->pageName() == PageName) {
            next(page);
            break;
        } else {
            m_container->removeWidget(m_stackWidgets.last());
            delete m_stackWidgets.last();
            m_stackWidgets.removeLast();
        }
    }
}

auto Navigator::replace(Pages::BasePage* page) -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    disconnectPage(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    m_stackWidgets.append(page);
    connectPage(page);
    m_container->addWidget(page);
}

auto Navigator::connectPage(Pages::BasePage* page) -> void
{
    connect(page, qOverload<>(&Pages::BasePage::back), this, qOverload<>(&Navigator::back));
    connect(page, qOverload<QVariant>(&Pages::BasePage::back), this, qOverload<QVariant>(&Navigator::back));
    connect(page, &Pages::BasePage::backTo, this, &Navigator::backTo);
    connect(page, &Pages::BasePage::backToAndNext, this, &Navigator::backToAndNext);
    connect(page, &Pages::BasePage::replace, this, &Navigator::replace);
    connect(page, &Pages::BasePage::next, this, &Navigator::next);
}

auto Navigator::disconnectPage(Pages::BasePage* page) -> void
{
    disconnect(page, qOverload<>(&Pages::BasePage::back), this, qOverload<>(&Navigator::back));
    disconnect(page, qOverload<QVariant>(&Pages::BasePage::back), this, qOverload<QVariant>(&Navigator::back));
    disconnect(page, &Pages::BasePage::backTo, this, &Navigator::backTo);
    disconnect(page, &Pages::BasePage::backToAndNext, this, &Navigator::backToAndNext);
    disconnect(page, &Pages::BasePage::replace, this, &Navigator::replace);
    disconnect(page, &Pages::BasePage::next, this, &Navigator::next);
}

} // namespace ATQW::Views
