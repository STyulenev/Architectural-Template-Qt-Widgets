cmake_minimum_required(VERSION 3.5)

project(Page-lib
    VERSION 0.1
    DESCRIPTION "Static library with pages for views"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB page-src "include/*.h" "ui/*.ui" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${page-src})
add_library(ATQW::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(COMMAND target_precompile_headers)
   target_precompile_headers(${PROJECT_NAME} PUBLIC
       ./include/PagePrecompile.h
   )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets

    ATQW::Controller-lib
    ATQW::View-model-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
