#pragma once

//#include "MainWindow.h"

#include <QTest>

namespace ATQW::Tests {

class Test_MainWindow : public QObject
{
    Q_OBJECT

private:
    //Views::MainWindow window;

public:
    explicit Test_MainWindow(QObject* parent = 0);
    ~Test_MainWindow() = default;

private slots:
    auto test_bench() -> void;

};

} // namespace ATQW:Tests
