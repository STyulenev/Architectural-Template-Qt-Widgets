#pragma once

#include <QApplication>

namespace ATQW::Core {

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    ~Application();

    auto launch() -> void;

private:
    // ...

};

} // namespace ATQW::Core
