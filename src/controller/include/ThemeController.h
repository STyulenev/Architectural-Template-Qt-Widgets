#pragma once

#include <QObject>

namespace ATQW::Controllers {

class ThemeController : public QObject
{
    Q_OBJECT

public:
    explicit ThemeController(QObject* parent = nullptr);
    ~ThemeController();

public slots:
    auto setTheme(const int themeId) -> void;
    auto getTheme() -> int;

private:
    auto switchTheme(const QString&& path) -> void;

signals:
    auto themeChanged(const QString& style) -> void;

private:
    int m_themeId;

};

} // namespace ATQW::Controllers
