cmake_minimum_required(VERSION 3.16)

project(Turtle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#enabling debug symbols for Valgrind
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qml Quick Test Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Qml Quick Test Multimedia)

set(PROJECT_SOURCES
        src/main.cpp
        src/turtle_window.cpp
        src/turtle_window.h
        src/turtle_window.ui
        src/turtle.cpp
        src/turtle.h
        src/paintarea.cpp
        src/paintarea.h



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Turtle
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/nlohmann/ordered_map.hpp src/nlohmann/json_fwd.hpp src/nlohmann/json.hpp src/nlohmann/byte_container_with_subtype.hpp src/nlohmann/adl_serializer.hpp
        images_donatello.qrc



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Turtle APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Turtle SHARED
            ${PROJECT_SOURCES}

        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Turtle
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(Turtle PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Turtle PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Multimedia)

# Copy commands.json from root folder to build folder
file(COPY ${CMAKE_SOURCE_DIR}/commands.json DESTINATION ${CMAKE_BINARY_DIR})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Turtle)
endif()
set_target_properties(Turtle PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Turtle
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Turtle)
endif()

#CONFIGURATION OF TESTS STARTS

#Add test source and create a separate test targets
set(TEST_SOURCES
    src/main_test.cpp
    src/paintarea.cpp
    src/turtle.cpp
    tests/test_square.h
    tests/test_boundry.h
)

add_executable(TurtleTests
    ${TEST_SOURCES}
)

#Include test directory for the test target
target_include_directories(TurtleTests PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/tests)

#Link the test target with Qt Test and necessary libraries
target_link_libraries(TurtleTests PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Qml Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Multimedia)

#CONFIGURATION OF TESTS ENDS
