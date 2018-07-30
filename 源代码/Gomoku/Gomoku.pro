#-------------------------------------------------
#
# Project created by QtCreator 2017-06-07T21:44:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gomoku
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    chessboard.cpp \
    chessman.cpp \
    win1_show.cpp \
    win2_show.cpp \
    ai.cpp \
    global.cpp \
    mytimer.cpp \
    user.cpp \
    login.cpp \
    welcome.cpp \
    enroll.cpp \
    enroll_success.cpp \
    enroll_warning.cpp \
    enroll_warning2.cpp \
    login_warning.cpp \
    login_warning2.cpp \
    login_warning3.cpp \
    sky_ladder.cpp \
    enroll_warning3.cpp \
    enroll_warning4.cpp \
    login_warning4.cpp

HEADERS  += mainwindow.h \
    chessboard.h \
    chessman.h \
    win1_show.h \
    win2_show.h \
    ai.h \
    global.h \
    mytimer.h \
    user.h \
    login.h \
    welcome.h \
    enroll.h \
    enroll_success.h \
    enroll_warning.h \
    enroll_warning2.h \
    login_warning.h \
    login_warning2.h \
    login_warning3.h \
    sky_ladder.h \
    enroll_warning3.h \
    enroll_warning4.h \
    login_warning4.h

FORMS    += mainwindow.ui \
    win1_show.ui \
    win2_show.ui \
    login.ui \
    welcome.ui \
    enroll.ui \
    enroll_success.ui \
    enroll_warning.ui \
    enroll_warning2.ui \
    login_warning.ui \
    login_warning2.ui \
    login_warning3.ui \
    sky_ladder.ui \
    enroll_warning3.ui \
    enroll_warning4.ui \
    login_warning4.ui

RESOURCES += \
    resource.qrc
