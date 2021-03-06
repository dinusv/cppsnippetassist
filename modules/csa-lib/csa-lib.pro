TEMPLATE = lib
TARGET   = csa
QT      += qml quick script
CONFIG  += qt

DEFINES += Q_CSA
DEFINES += Q_CSA_LIB

# Destination

win32:CONFIG(debug, debug|release): DLLDESTDIR = $$quote($$OUT_PWD/../build/debug)
else:win32:CONFIG(release, debug|release): DLLDESTDIR = $$quote($$OUT_PWD/../build/release)
else:unix: TARGET = $$quote($$OUT_PWD/../build/csa)

include($$PWD/../../3rdparty/libclang.pro)

include($$PWD/astnodes/astnodes.pri)
include($$PWD/codebase/codebase.pri)
include($$PWD/script/script.pri)
