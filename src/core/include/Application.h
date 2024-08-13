#pragma once

#include <QApplication>

namespace ATQW::Controllers {
    class LanguageController;
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
    Controllers::LanguageController* m_languageController;
    // ...

};

} // namespace ATQW::Core
