#pragma once

#include <QSplashScreen>

namespace Ui {
    class SplashScreen;
}

namespace ATQW::Views {

class SplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget* parent = nullptr);
    ~SplashScreen();

private:
    Ui::SplashScreen* ui;

};

} // namespace ATQW::Views
