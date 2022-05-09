include($$PWD/../../Input.pri)

DESTDIR = $$PLUGINS_PREFIX/Input
TARGET = $${TARGET}

HEADERS += decoderhivelyfactory.h \
           decoder_hively.h \
           hivelyhelper.h
    
SOURCES += decoderhivelyfactory.cpp \
           decoder_hively.cpp \
           hivelyhelper.cpp

INCLUDEPATH += $$EXTRA_PREFIX/libttk/include

unix{
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
    LIBS += -L$$EXTRA_PREFIX/libttk/lib -lhively$$STATIC_LIBRARY_SUFFIX
}

win32{
    LIBS += -L$$EXTRA_PREFIX/libttk/lib -lhively
}