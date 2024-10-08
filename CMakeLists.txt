cmake_minimum_required(VERSION 3.5)

project(Architectural-Template-Qt-Widgets
    VERSION 0.1
    DESCRIPTION "An example architectural template for a multi-page GUI application using Qt/Widgets"
    HOMEPAGE_URL "https://github.com/STyulenev/Architectural-Template-Qt-Widgets"
    LANGUAGES CXX
)

option(TEST_OPTION "test opiton" ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core LinguistTools REQUIRED)

include(cmake/CPackSettings.cmake)
include(cmake/TranslationUtils.cmake)
add_app_translations_resource(APP_RES ${QM_FILES})

if(LINUX)
    add_subdirectory(debian)
endif(LINUX)

add_subdirectory(src)

if(TEST_OPTION)
    add_subdirectory(tests)
endif(TEST_OPTION)

set(PROJECT_SOURCES
    main.cpp

    ${APP_RES}
    resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    ATQW::Core-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

install(TARGETS ${PROJECT_NAME}
    DESTINATION "${BINARY_DESTINATION}"
    PERMISSIONS ${BINARY_PERMISSIONS_DEFAULT}
    COMPONENT runtime
)
