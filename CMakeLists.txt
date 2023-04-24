cmake_minimum_required(VERSION 3.26)
project(PySideQGLViewer)

set(PYTHON_BINDING_NAMESPACE "PySideQGLViewer")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Just to fix warnings with --warn-uninitialized
if(NOT DEFINED SHIBOKEN_CUSTOM_PREFIX) #look for shiboken in a custom location
    set(SHIBOKEN_CUSTOM_PREFIX "")
endif()
if(NOT DEFINED PYSIDE_CUSTOM_PREFIX) #look for pyside in a custom location
    set(PYSIDE_CUSTOM_PREFIX "")
endif()

if(${PROJECT_NAME}_QT6)
    set(PYSIDE_MAJOR_VERSION "6")
    set(PYTHON_BINDING_NAMESPACE "${PYTHON_BINDING_NAMESPACE}Qt${PYSIDE_MAJOR_VERSION}")
    set(QtWidgets_VERSION ${Qt6Widgets_VERSION})
else()
    set(PYSIDE_MAJOR_VERSION "2")
    set(QtWidgets_VERSION ${Qt5Widgets_VERSION})
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets Xml OpenGL REQUIRED)
find_package(Python3 3.10 REQUIRED COMPONENTS Interpreter Development)
find_package(Shiboken${PYSIDE_MAJOR_VERSION} REQUIRED)
find_package(PySide${PYSIDE_MAJOR_VERSION} ${QtWidgets_VERSION} EXACT REQUIRED)
find_package(QGLViewer REQUIRED)

if(NOT ${PROJECT_NAME}_PYTHON_BINDINGS_INSTALL_PREFIX)
    set(${PROJECT_NAME}_PYTHON_BINDINGS_INSTALL_PREFIX "$ENV{CONDA_PREFIX}")
endif()
set(Python3_VERSION_MAJORMINOR "${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}")
set(BINDINGS_DIR "lib/python${Python3_VERSION_MAJORMINOR}/site-packages/${PYTHON_BINDING_NAMESPACE}")
set(${PROJECT_NAME}_PYTHON_BINDINGS_INSTALL_PREFIX "${${PROJECT_NAME}_PYTHON_BINDINGS_INSTALL_PREFIX}/${BINDINGS_DIR}")

include(PySide${PYSIDE_MAJOR_VERSION}ModuleBuild)
add_subdirectory(PySideQGLViewer)
