#-------------------------------------------------
#
# Project created by Project Hive 2015-10-14T18:40:32
#
#-------------------------------------------------

QT       += core
QT	 += gui
QT       += widgets
QT	 += network
#QT	 += opengl
#QT       += concurrent

CONFIG   += c++14

TARGET = Hive!
TEMPLATE = app
INCLUDEPATH += /usr/local/include
SOURCES += \
    Gui/ContactsTab.cpp \
    Gui/Frameworks/ContactWidget.cpp \
    Gui/SideBar.cpp \
    main.cpp \
    Hive.cpp \
    GlobalType.cpp \
    UsrData.cpp \
\
    Gui/HomeTab.cpp \
    Gui/MainBlock.cpp \
    Gui/ChatStack.cpp \
    Gui/SettingsTab.cpp \
    Gui/SettingsStack_messaging.cpp \
    Gui/SettingsStack_profile.cpp \
    Gui/SettingsStack_questions.cpp \
    Gui/SettingsStack_update.cpp \
    Gui/HomeStack_storage.cpp \
    Gui/HomeStack_network.cpp \
    Gui/HomeStack_list.cpp \
    Gui/HomeStack_welcome.cpp \
\
    Gui/Frameworks/ScrollStack.cpp \
\
    Gui/Frameworks/Widgets/TextBubble.cpp \
    Gui/Frameworks/Widgets/ColorPicker.cpp \
    Gui/Frameworks/Widgets/BadgeIcon.cpp \
\
    Network/NetworkManager.cpp \
\
    Gui/Frameworks/Widgets/AvatarWidgets.cpp \
    Log.cpp \
    HiveProtocol.cpp \
    Data/AppDataManager.cpp \
    HiveUdpServer.cpp \
    Bee.cpp \
    HiveDoubleBuffer.cpp \
    HiveServer.cpp \
    Gui/Window.cpp \
    Global.cpp \
    Subscription.cpp \
    Database.cpp \
    Gui/Frameworks/Widgets/Button.cpp \
    Gui/Frameworks/Widgets/SearchBar.cpp
\

HEADERS  += \
	Gui/ContactsTab.h \
	Gui/Frameworks/ContactWidget.h \
	Gui/SideBar.h \
    Hive.h \
    GlobalType.h \
    UsrData.h \
\
    Gui/HomeTab.h \
    Gui/MainBlock.h \
    Gui/ChatStack.h \
    Gui/SettingsTab.h \
    Gui/SettingsStack_messaging.h \
    Gui/SettingsStack_profile.h \
    Gui/SettingsStack_questions.h \
    Gui/SettingsStack_update.h \
    Gui/HomeStack_storage.h \
    Gui/HomeStack_network.h \
    Gui/HomeStack_list.h \
    Gui/HomeStack_welcome.h \
\
    Gui/Frameworks/ScrollStack.h \
\
    Gui/Frameworks/Widgets/TextBubble.h \
    Gui/Frameworks/Widgets/ColorPicker.h \
    Gui/Frameworks/Widgets/BadgeIcon.h \
\
    Network/NetworkManager.h \
\
    Gui/Frameworks/Widgets/AvatarWidgets.h \
    Log.h \
    Message.h \
    HiveProtocol.h \
    Data/AppDataManager.h \
    HiveUdpServer.h \
    Bee.h \
    HiveDoubleBuffer.h \
    HiveServer.h \
    Gui/Window.h \
    Global.h \
    Subscription.h \
    Database.h \
    Gui/Frameworks/Widgets/Button.h \
    Gui/Frameworks/Widgets/SearchBar.h

ICON = Src/hive.icns

RESOURCES += \
    Src/img.qrc \
    Src/font.qrc
#    Src/icon.qrc

macx{
#    QT   += macextras
    QMAKE_INFO_PLIST = ./Info.plist
    plist.path = "$$DESTDIR/$$join(TARGET,,,.app)/Contents"
    plist.files = ./Info.plist
    INSTALLS += plist
    PKG_CONFIG = /usr/local/bin/pkg-config

    LIBS += -framework AppKit
    OBJECTIVE_HEADERS += \
	Gui/macos/WindowOptions.h
    OBJECTIVE_SOURCES += \
	Gui/macos/WindowOptions.mm
}


unix{
    CONFIG += link_pkgconfig

    CONFIG(debug, debug|release) {
	PKGCONFIG += \
	    libagio-d
    }

    CONFIG(release, debug|release) {
	PKGCONFIG += \
	    libagio
    }
}

win32{
    QMAKE_LFLAGS += -L../libs/libuv/win32 -luv
    RC_FILE = ./Src/hive.rc
}


