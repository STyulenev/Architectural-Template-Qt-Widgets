#include "SettingPage.h"
#include "ui_SettingPage.h"

#include "LanguageController.h"
#include "ThemeController.h"

#include "LanguageViewModel.h"
#include "ThemeViewModel.h"

#include "PageFactory.h"

namespace ATQW::Pages {

SettingPage::SettingPage(QWidget* parent) :
    BasePage(parent),
    ui(new Ui::SettingPage)
{
    ui->setupUi(this);
    setPageName(this->objectName());

    m_languageController = qobject_cast<Controllers::LanguageController*>(qApp->property("LanguageController").value<QObject*>());
    m_themeController    = qobject_cast<Controllers::ThemeController*>(qApp->property("ThemeController").value<QObject*>());

    m_languageViewModel = new ViewModels::LanguageViewModel(this);
    m_themeViewModel    = new ViewModels::ThemeViewModel(this);

    ui->languageComboBox->setModel(m_languageViewModel);
    ui->themeComboBox->setModel(m_themeViewModel);

    ui->themeComboBox->setCurrentIndex(1); // stub
}

SettingPage::~SettingPage()
{
    delete ui;
}

auto SettingPage::updatePage() -> void
{

}

auto SettingPage::updatePage([[maybe_unused]] QVariant data) -> void
{

}

auto SettingPage::on_logoutButton_clicked() -> void
{
    emit backTo("AuthenticationPage");
}

auto SettingPage::on_backButton_clicked() -> void
{
    emit back(QString("data"));
}

auto SettingPage::on_languageComboBox_activated(int index) -> void
{
    m_languageController->setLanguage(m_languageViewModel->getCodeForIndex(index));

    ui->retranslateUi(this);
}

auto SettingPage::on_themeComboBox_activated(int index) -> void
{
    m_themeController->setTheme(m_themeViewModel->getCodeForIndex(index));
}

} // namespace ATQW::Pages
