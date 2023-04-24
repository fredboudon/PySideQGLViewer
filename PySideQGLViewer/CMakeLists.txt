#
# This file is part of KDDockWidgets.
#
# SPDX-FileCopyrightText: 2020-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
# Author: Renato Araujo Oliveira Filho <renato.araujo@kdab.com>
#
# SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only
#
# Contact KDAB at <info@kdab.com> for commercial licensing options.
#

# Auto-Genereate files every class will have his cpp/h files
set(PySideQGLViewer_SRC
    # individual classes
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_camera_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_constraint_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_axisplaneconstraint_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_localconstraint_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_worldconstraint_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_cameraconstraint_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_frame_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_keyframeinterpolator_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_manipulatedframe_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_manipulatedcameraframe_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_mousegrabber_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_quaternion_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/qglviewer_vec_wrapper.cpp
    # global module wrapper
    ${CMAKE_CURRENT_BINARY_DIR}/PySideQGLViewer/pysideqglviewer_module_wrapper.cpp
)


# includes necessary to parse and build the classes specified on typesystem
set(PySideQGLViewer_include_paths
    $ENV{CONDA_PREFIX}/include
    $<JOIN:$<TARGET_PROPERTY:PySideQGLViewer,INTERFACE_INCLUDE_DIRECTORIES>,${PATH_SEP}>
)

# A list of paths where shiboken should look for typesystem
set(PySideQGLViewer_typesystem_paths # PySide path, this variable was exposed by FindPySide2.cmake
    ${PYSIDE_TYPESYSTEMS}
)

# Include flags/path that will be set in 'target_include_directories'
set(PySideQGLViewer_target_include_directories 
    ${CMAKE_SOURCE_DIR}/src 
    $ENV{CONDA_PREFIX}/include/
)

# Libraries that will be necessary to link the target, this will used in the command 'target_link_libraries'
set(PySideQGLViewer_target_link_libraries
    ${QGLViewer_Lib}
    Qt${Qt_VERSION_MAJOR}::Core
    Qt${Qt_VERSION_MAJOR}::Gui
    Qt${Qt_VERSION_MAJOR}::Widgets
    Qt${Qt_VERSION_MAJOR}::Xml
    Qt${Qt_VERSION_MAJOR}::OpenGL
    ${Python3_LIBRARIES}
)

# changes on these files should trigger a new generation
set(PySideQGLViewer_DEPENDS
    #${CMAKE_CURRENT_SOURCE_DIR}/kddockwidgets_global.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/camera.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/config.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/constraint.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/domUtils.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/frame.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/keyFrameInterpolator.h
    $ENV{CONDA_PREFIX}/include/QGLViewer/qglviewer.h
)

create_python_bindings(
    "PySideQGLViewer"
    "${PySideQGLViewer_typesystem_paths}"
    "${PySideQGLViewer_include_paths}"
    "${PySideQGLViewer_SRC}"
    "${PySideQGLViewer_target_include_directories}"
    "${PySideQGLViewer_target_link_libraries}"
    ${CMAKE_CURRENT_SOURCE_DIR}/qglviewer_global.h
    ${CMAKE_CURRENT_SOURCE_DIR}/typesystem_pyqglviewer.xml
    "${PySideQGLViewer_DEPENDS}"
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Make module import from build dir work
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/__init__.py @ONLY)

# install
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py $<TARGET_FILE:PySideQGLViewer>
    DESTINATION ${${PROJECT_NAME}_PYTHON_BINDINGS_INSTALL_PREFIX}
)
#if(NOT WIN32)
#    install(FILES $<TARGET_LINKER_FILE:PySideQGLViewer> $<TARGET_SONAME_FILE:PySideQGLViewer>
#            DESTINATION ${${PROJECT_NAME}_PYTHON_BINDINGS_INSTALL_PREFIX}
#    )
#endif()
