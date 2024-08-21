#include <QTest>
#include <Test_MainWindow.h>

auto main(int argc, char* argv[]) -> int
{
    //assert(QTest::qExec(new ATQW::Test_MainWindow, argc, argv) == 0);
    QTest::qExec(new ATQW::Tests::Test_MainWindow, argc, argv);

    return 0;
}
