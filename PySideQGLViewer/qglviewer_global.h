#pragma once

// Make "signals:", "slots:" visible as access specifiers
#define QT_ANNOTATE_ACCESS_SPECIFIER(a) __attribute__((annotate(#a)))

// Define PYTHON_BINDINGS this will be used in some part of c++ to skip problematic parts
#define PYTHON_BINDINGS


#include <QGLViewer/camera.h>
#include <QGLViewer/constraint.h>
#include <QGLViewer/domUtils.h>
#include <QGLViewer/frame.h>
#include <QGLViewer/keyFrameInterpolator.h>
#include <QGLViewer/manipulatedFrame.h>
#include <QGLViewer/manipulatedCameraFrame.h>
#include <QGLViewer/mouseGrabber.h>
#include <QGLViewer/qglviewer.h>
#include <QGLViewer/quaternion.h>
#include <QGLViewer/vec.h>
