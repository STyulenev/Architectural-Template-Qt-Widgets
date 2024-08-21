cmake_minimum_required(VERSION 3.5)

project(Test-bin
    VERSION 0.1
    DESCRIPTION "Application with tests"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

file(GLOB tests-src "include/*.h" "./*.cpp")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${tests-src}
    )
else()
    add_executable(${PROJECT_NAME}
        ${tests-src}
    )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Test
    View-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
