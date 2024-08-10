#include "ApplicationSettings.h"

#include <QSettings>
#include <QCoreApplication>

namespace ATQW::Settings {

ApplicationSettings* ApplicationSettings::self = 0;

QSettings settings(qApp->organizationName(), qApp->applicationName());

ApplicationSettings* ApplicationSettings::getSetting()
{
    if (!self) {
        self = new ApplicationSettings();
    }

    return self;
}

auto ApplicationSettings::setMainWindowsSetting(const QSize& size, const QByteArray& state) -> void
{
    settings.beginGroup("mainWindow");
    settings.setValue("size", size);
    settings.setValue("state", state);
    settings.endGroup();
}

auto ApplicationSettings::getMainWindowsSetting() -> std::pair<QSize, QByteArray>
{
    settings.beginGroup("mainWindow");
    auto pair = std::make_pair<QSize, QByteArray>(
        settings.value("size", QSize(800, 500)).toSize(),
        settings.value("state").toByteArray()
    );
    settings.endGroup();

    return pair;
}

} // namespace ATQW::Settings
