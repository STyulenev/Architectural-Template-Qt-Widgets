#include "AuthenticationPage.h"
#include "ui_AuthenticationPage.h"

#include "PageFactory.h"

namespace ATQW::Pages {

AuthenticationPage::AuthenticationPage(QWidget* parent) :
    BasePage(parent),
    ui(new Ui::AuthenticationPage)
{
    ui->setupUi(this);
    setPageName(this->objectName());
}

AuthenticationPage::~AuthenticationPage()
{
    delete ui;
}

auto AuthenticationPage::updatePage() -> void
{

}

auto AuthenticationPage::updatePage([[maybe_unused]] QVariant data) -> void
{

}

auto AuthenticationPage::on_enterButton_clicked() -> void
{
    emit next(getPage(PageName::MAIN_MENU_PAGE));
}

} // namespace ATQW::Pages
