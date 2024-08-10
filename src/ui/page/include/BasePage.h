#pragma once

#include "PagePrecompile.h"

namespace ATQW::Pages {

class BasePage : public QWidget
{
    Q_OBJECT

    friend class Navigator;

public:
    explicit BasePage(QWidget* parent = nullptr);
    virtual ~BasePage() = default;

    auto pageName() const -> const QString&;
    auto setPageName(const QString& pageName) -> void;

protected:
    virtual auto updatePage() -> void = 0;
    virtual auto updatePage(QVariant data) -> void = 0;

signals:
    auto back() -> void;
    auto back(QVariant data) -> void;
    auto backTo(QString pageName) -> void;
    auto backToAndNext(QString pageName, Pages::BasePage* newFragment) -> void;
    auto next(BasePage* newFragment) -> void;
    auto replace(BasePage* newFragment) -> void;

private:
    QString m_pageName;

};

} // namespace ATQW::Pages
