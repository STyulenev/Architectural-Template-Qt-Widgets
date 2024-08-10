#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ATQW::Pages {
    class Navigator;
}

namespace ATQW::Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    std::shared_ptr<ATQW::Pages::Navigator> m_navigator;

};

} // namespace ATQW::Views
