#=======================================================================
#
# lupdate cmake files
#
#=======================================================================

if(NOT TARGET Qt${QT_VERSION_MAJOR}::lconvert)
    message(FATAL_ERROR "The package \"Qt${QT_VERSION_MAJOR}LinguistTools\" is required.")
endif()

file(GLOB TS_FILES "${CMAKE_SOURCE_DIR}/res/languages/*.ts")
message("---> ${TS_FILES}")
foreach(TS_FILE ${TS_FILES})

    if(WIN32)
        # В Windows QT_UTILITY_PATH может быть пустым
        execute_process(COMMAND C:/Qt/6.6.3/mingw_64/bin/lupdate -noobsolete -recursive ${PROJECT_SOURCE_DIR} -ts ${TS_FILE})
    elseif(UNIX)
        execute_process(COMMAND ${QT_UTILITY_PATH}lupdate -noobsolete -recursive ${PROJECT_SOURCE_DIR} -ts ${TS_FILE})
    else()
        message(FATAL_ERROR "The lupdate path is required.")
    endif()

endforeach()

if(QT_VERSION VERSION_LESS 5.15.0)
    qt5_add_translation(QM_FILES ${TS_FILES})
else()
    qt_add_translation(QM_FILES ${TS_FILES})
endif()

function(ADD_APP_TRANSLATIONS_RESOURCE res_file)

    set(_qm_files ${ARGN})
    set(_res_file ${CMAKE_CURRENT_BINARY_DIR}/app_translations.qrc)

    file(WRITE ${_res_file} "<!DOCTYPE RCC><RCC version=\"1.0\">\n <qresource prefix=\"/\">\n")
    foreach(_lang ${_qm_files})
        get_filename_component(_filename ${_lang} NAME)
        file(APPEND ${_res_file} "  <file>${_filename}</file>\n")
    endforeach()
    file(APPEND ${_res_file} " </qresource>\n</RCC>\n")

    set(${res_file} ${_res_file} PARENT_SCOPE)

endfunction()
