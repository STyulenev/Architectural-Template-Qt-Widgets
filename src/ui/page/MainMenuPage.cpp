#include "MainMenuPage.h"
#include "ui_MainMenuPage.h"

#include "PageFactory.h"

namespace ATQW::Pages {

MainMenuPage::MainMenuPage(QWidget* parent) :
    BasePage(parent),
    ui(new Ui::MainMenuPage)
{
    ui->setupUi(this);
    setPageName(this->objectName());
}

MainMenuPage::~MainMenuPage()
{
    delete ui;
}

auto MainMenuPage::updatePage() -> void
{

}

auto MainMenuPage::updatePage(QVariant data) -> void
{
    qDebug() << data;
}

auto MainMenuPage::on_settingPageButton_clicked() -> void
{
    emit next(getPage(PageName::SETTING_PAGE));
}

auto MainMenuPage::on_closeButton_clicked() -> void
{
    emit exit(0);
}

} // namespace ATQW::Pages
