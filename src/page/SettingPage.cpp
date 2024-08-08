#include "SettingPage.h"
#include "ui_SettingPage.h"

#include "PageFactory.h"

namespace ATQW::Pages {

SettingPage::SettingPage(QWidget* parent) :
    BasePage(parent),
    ui(new Ui::SettingPage)
{
    ui->setupUi(this);
    setPageName(this->objectName());
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

} // namespace ATQW::Pages
