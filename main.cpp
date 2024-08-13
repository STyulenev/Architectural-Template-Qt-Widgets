#include "Application.h"
#include "MainWindow.h"
#include "SplashScreen.h"

#include <QThread>

auto main(int argc, char* argv[]) -> int
{
    ATQW::Core::Application app(argc, argv);
    ATQW::Views::MainWindow mainWindow;

    ATQW::Views::SplashScreen splashScreen;
    splashScreen.show();
    app.processEvents();
    {
        // some actions
        app.launch();
        QThread::sleep(3);
    }
    splashScreen.finish(&mainWindow);

    mainWindow.show();
    return app.exec();
}
