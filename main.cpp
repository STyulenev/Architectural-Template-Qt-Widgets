#include "MainWindow.h"
#include "SplashScreen.h"

#include <QApplication>
#include <QThread>

auto main(int argc, char* argv[]) -> int
{
    QApplication app(argc, argv);
    ATQW::Views::MainWindow mainWindow;

    ATQW::Views::SplashScreen splashScreen;
    splashScreen.show();
    app.processEvents();
    {
        // some actions
        QThread::sleep(5);
    }
    splashScreen.finish(&mainWindow);

    mainWindow.show();
    return app.exec();
}
