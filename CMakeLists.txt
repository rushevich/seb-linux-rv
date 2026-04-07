cmake_minimum_required(VERSION 3.20)

project(safe-exam-browser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

option(SEB_BROWSER_ENGINE_WPE "Enable WPE (QtWPE) browser engine" OFF)
option(RISCV_HARDENED_BUILD "Enable riscv64 hardened defaults" OFF)

if(RISCV_HARDENED_BUILD)
  add_compile_definitions(RISCV_HARDENED_BUILD)
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network Xml)
qt_standard_project_setup()

qt_add_executable(safe-exam-browser)

target_include_directories(safe-exam-browser PRIVATE "${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE SEB_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Ensure Qt's automoc picks up engine interface headers with Q_OBJECT.
list(APPEND SEB_SOURCES
  "${CMAKE_SOURCE_DIR}/src/browser/engine/browser_view.h"
  "${CMAKE_SOURCE_DIR}/src/browser/engine/qtwebengine_browser_view.h"
  "${CMAKE_SOURCE_DIR}/src/browser/engine/wpe_browser_view.h"
)

target_sources(safe-exam-browser PRIVATE ${SEB_SOURCES})

qt_add_resources(safe-exam-browser resources.qrc)

target_link_libraries(safe-exam-browser PRIVATE
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::Network
  Qt6::Xml
  z
  crypto
)

# Engine selection mirrors the migration plan: QtWebEngine vs WPE.
set(SEB_BROWSER_ENGINE "qtwebengine" CACHE STRING "Browser engine backend: qtwebengine|wpe")
set_property(CACHE SEB_BROWSER_ENGINE PROPERTY STRINGS qtwebengine wpe)

if(SEB_BROWSER_ENGINE STREQUAL "qtwebengine")
  find_package(Qt6 REQUIRED COMPONENTS WebEngineCore WebEngineWidgets)
  target_compile_definitions(safe-exam-browser PRIVATE SEB_ENGINE_QTWEBENGINE=1)
elseif(SEB_BROWSER_ENGINE STREQUAL "wpe")
  target_compile_definitions(safe-exam-browser PRIVATE SEB_USE_WPE=1)
else()
  message(FATAL_ERROR "Unknown SEB_BROWSER_ENGINE=${SEB_BROWSER_ENGINE} (expected qtwebengine or wpe)")
endif()

if(SEB_BROWSER_ENGINE STREQUAL "qtwebengine")
  target_link_libraries(safe-exam-browser PRIVATE Qt6::WebEngineCore Qt6::WebEngineWidgets)
endif()

if(SEB_BROWSER_ENGINE STREQUAL "wpe")
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(WPEWEBKIT REQUIRED IMPORTED_TARGET wpewebkit-1.1)
  pkg_check_modules(LIBWPE REQUIRED IMPORTED_TARGET wpe-1.0)
  pkg_check_modules(WPEBACKEND REQUIRED IMPORTED_TARGET wpebackend-fdo-1.0)
  target_link_libraries(safe-exam-browser PRIVATE
    PkgConfig::WPEWEBKIT
    PkgConfig::LIBWPE
    PkgConfig::WPEBACKEND
    Qt6::Gui
  )
endif()

install(TARGETS safe-exam-browser RUNTIME DESTINATION bin)

