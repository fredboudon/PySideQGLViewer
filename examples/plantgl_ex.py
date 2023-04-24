from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *
from openalea.plantgl.all import *
from PySideQGLViewer import *
s = Scene()
s += Sphere()
def draw():
    d = Discretizer()
    gl = GLRenderer(d)
    s.apply(gl)

qapp = QApplication([])
viewer = QGLViewer()
viewer.setStateFileName('.plantgl_ex.xml')        
viewer.connect(viewer,SIGNAL("drawNeeded()"),draw)
viewer.show()
qapp.exec_()
