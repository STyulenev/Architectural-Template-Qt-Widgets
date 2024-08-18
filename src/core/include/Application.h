#pragma once

#include <QApplication>

namespace ATQW::Controllers {
    class LanguageController;
    class ThemeController;
}

namespace ATQW::Core {

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    ~Application();

    auto launch() -> void;

private:
    auto setTheme(const QString& style) -> void;
    auto setFont() -> void;

private:
    Controllers::LanguageController* m_languageController;
    Controllers::ThemeController*    m_themeController;
    // ...

};

} // namespace ATQW::Core
