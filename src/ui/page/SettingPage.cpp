#include "SettingPage.h"
#include "ui_SettingPage.h"

#include "LanguageController.h"
#include "LanguageViewModel.h"
#include "PageFactory.h"

namespace ATQW::Pages {

SettingPage::SettingPage(QWidget* parent) :
    BasePage(parent),
    ui(new Ui::SettingPage)
{
    ui->setupUi(this);
    setPageName(this->objectName());

    m_languageController = qobject_cast<Controllers::LanguageController*>(qApp->property("LanguageController").value<QObject*>());
    m_languageViewModel = new ViewModels::LanguageViewModel(this);
    ui->languageComboBox->setModel(m_languageViewModel);
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

} // namespace ATQW::Pages
