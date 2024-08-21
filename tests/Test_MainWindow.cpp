#include <Test_MainWindow.h>

namespace ATQW::Tests {

Test_MainWindow::Test_MainWindow(QObject* parent) :
    QObject(parent)
{

}

auto Test_MainWindow::test_bench() -> void
{
    QBENCHMARK {
        std::vector<QString> vector;
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");

        std::vector<QString> vector2 = vector;
    }
}

} // namespace ATQW:TestsTests
