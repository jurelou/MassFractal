QT += widgets
QMAKE_CXXFLAGS+=-std=gnu++11
TARGET = MassFractal
INCLUDEPATH += .
SOURCES	=	main.cpp \
			mainWindow.cpp \
			FractalWidget.cpp \
			RenderThread.cpp
HEADERS	=	mainWindow.h \
			FractalWidget.h \
			RenderThread.h
