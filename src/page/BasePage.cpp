#include "BasePage.h"

namespace ATQW::Pages {

BasePage::BasePage(QWidget* parent) :
    QWidget(parent)
{

}

auto BasePage::pageName() const -> const QString&
{
    return m_pageName;
}

auto BasePage::setPageName(const QString& pageName) -> void
{
    m_pageName = pageName;
}

} // namespace ATQW::Pages
