QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/parameter.cpp \
    main.cpp \
    common/Board.cpp \
    view/mymainwindow.cpp \
    viewmodel/commands/backcommand.cpp \
    viewmodel/commands/f_restartcommand.cpp \
    viewmodel/commands/flipoverChessCommand.cpp \
    viewmodel/commands/moveStoneCommand.cpp \
    viewmodel/commands/moveStoneCommand_f.cpp \
    viewmodel/commands/restartcommand.cpp \
    viewmodel/my_vm.cpp \
    view/mywidget.cpp \
    app/msapp.cpp\
    view/sink/SinkProperty.cpp\
    viewmodel/sinks/my_vmsink.cpp\
    model/my_model.cpp\
    common/F_Board.cpp



HEADERS += \
    common/Board.h \
    common/parameter.h \
    common/step.h \
    view/mymainwindow.h \
    viewmodel/commands/backcommand.h \
    viewmodel/commands/f_restartcommand.h \
    viewmodel/commands/flipoverChessCommand.h \
    viewmodel/commands/moveStoneCommand.h \
    viewmodel/commands/moveStoneCommand_f.h \
    viewmodel/commands/restartcommand.h \
    viewmodel/my_vm.h \
    view/mywidget.h \
    app/msapp.h\
    common/etlbase.h\
    view/sink/SinkProperty.h\
    viewmodel/sinks/my_vmsink.h\
    model/my_model.h\
    common/F_Board.h


FORMS += \
    mymainwindow.ui \
    mywidget.ui

TRANSLATIONS += \
    chess_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
