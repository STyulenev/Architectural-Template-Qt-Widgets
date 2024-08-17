cmake_minimum_required(VERSION 3.5)

project(Source
    VERSION 0.1
    DESCRIPTION "Source"
    LANGUAGES CXX
)

add_subdirectory(controller)
add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(setting)
add_subdirectory(view-model)
# ...
