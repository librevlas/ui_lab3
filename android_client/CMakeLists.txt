cmake_minimum_required(VERSION 3.5)

project(ui_lab3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Network)

set(PROJECT_SOURCES
    main.cpp
    MainWindow.cpp
    MainWindow.h
    SignInWidget.h SignInWidget.cpp
    ClientApi.cpp ClientApi.h
    Client.cpp Client.h
    SignUpWidget.cpp SignUpWidget.h
    ConnectWidget.cpp ConnectWidget.h QuestionsWidget.cpp QuestionsWidget.h QuestionListWidget.cpp QuestionListWidget.h QuestionWidget.cpp QuestionWidget.h AnswerPageWidget.cpp AnswerPageWidget.h AnswerWidget.cpp AnswerWidget.h PostAnswerWidget.cpp PostAnswerWidget.h PostQuestionWidget.cpp PostQuestionWidget.h)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ui_lab3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET ui_lab3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else ()
    if (ANDROID)
        add_library(ui_lab3 SHARED
            ${PROJECT_SOURCES}
            )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else ()
        add_executable(ui_lab3
            ${PROJECT_SOURCES}
            )
    endif ()
endif ()

target_link_libraries(ui_lab3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ui_lab3 PRIVATE Qt6::Network)

set_target_properties(ui_lab3 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    )

install(TARGETS ui_lab3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ui_lab3)
endif ()
