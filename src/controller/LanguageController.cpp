#include <LanguageController.h>

#include <QLocale>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

namespace ATQW::Controllers {

LanguageController::LanguageController(QObject* parent) :
    QObject(parent)
{
    m_translator = new QTranslator(this);
    qApp->installTranslator(m_translator);
}

LanguageController::~LanguageController()
{

}

auto LanguageController::setLanguage(const QString& langugage) -> void
{
    m_currLang = langugage;

    switchTranslator();
}

auto LanguageController::getLanguage() -> const QString&
{
    return m_currLang;
}

auto LanguageController::switchTranslator() -> void
{
    QLocale locale = QLocale(m_currLang);
    QLocale::setDefault(locale);

    qApp->removeTranslator(m_translator);

    if (m_translator->load(QString(":/ATQW_%1.qm").arg(m_currLang))) {
        qApp->installTranslator(m_translator);

        emit languageChanged();
    } else {
        qDebug() << "Failed to load " << QString(":/ATQW_%1.qm").arg(m_currLang);
    }
}

} // namespace ATQW::Сontrollers
