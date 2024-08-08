#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ATQW::Views {

class Navigator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow* ui;
    std::shared_ptr<Navigator> m_navigator;

};

} // namespace ATQW::Views
