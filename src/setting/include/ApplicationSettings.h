#pragma once

#include <QSize>
#include <QByteArray>

namespace ATQW::Settings {

class ApplicationSettings
{

private:
    static ApplicationSettings* self;

    ApplicationSettings() = default;
    ~ApplicationSettings() = default;
    ApplicationSettings(const ApplicationSettings&);
    ApplicationSettings& operator=(ApplicationSettings&);

public:
    static ApplicationSettings* getSetting();

    auto setMainWindowsSetting(const QSize& size, const QByteArray& state) -> void;
    auto getMainWindowsSetting() -> std::pair<QSize, QByteArray>;

    // ...

};

} // namespace ATQW::Settings
