#include <ThemeController.h>

#include <QFile>
#include <QDebug>

namespace ATQW::Controllers {

ThemeController::ThemeController(QObject* parent) :
    QObject(parent)
{

}

ThemeController::~ThemeController()
{

}

auto ThemeController::setTheme(const int themeId) -> void
{
    if (m_themeId != themeId) {
        m_themeId = themeId;

        switch (m_themeId) {
        case 1:
            switchTheme(":/res/styles/dark-style.css");
            break;
        case 2:
            switchTheme(":/res/styles/light-style.css");
            break;
        default:
            break;
        }
    }
}

auto ThemeController::getTheme() -> int
{
    return m_themeId;
}

auto ThemeController::switchTheme(const QString&& path) -> void
{
    QFile styleFile(path);

    if (styleFile.open(QIODevice::ReadOnly)) {
        QString appSlyle = QString(styleFile.readAll());

        emit themeChanged(appSlyle);

        styleFile.close();
    } else {
        qDebug() << "Failed to load " << path;
    }
}

} // namespace ATQW::Сontrollers
