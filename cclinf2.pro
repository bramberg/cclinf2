TEMPLATE = app

QT += qml quick widgets

QMAKE_CXXFLAGS += -std=c++14 -pedantic

SOURCES += \
    src/db/filesystem/index/common.cc \
    src/db/filesystem/index/reader.cc \
    src/db/filesystem/index/writer.cc \
    src/db/db.cc \
    src/db/filesystem/xml.cc \
    src/db/record_data.cc \
    src/db/settings.cc \
    src/record_viewer/editor/custom_text_edit.cc \
    src/record_viewer/editor/editor.cc \
    src/record_viewer/editor/formatting_toolbar.cc \
    src/record_viewer/links_list/link_view.cc \
    src/record_viewer/links_list/links_list.cc \
    src/record_viewer/links_list/vertical_scroll_area.cc \
    src/record_viewer/record_viewer.cc \
    src/utils/exception.cc \
    src/main.cpp \
    src/main_window.cc \
    src/navigation/search_line/search_line.cc \
    src/navigation/tree/tree_model.cc \
    src/navigation/tree/tree_view.cc \
    src/navigation/navigation.cc \
    src/record_viewer/title/record_title.cc \
    src/record.cc \
    src/dialogs/new_attachment_dialog.cc \
    src/db/database_reader.cc \
    src/db/filesystem/database_reader.cc

INCLUDEPATH += src

RESOURCES += \
    res/resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(res/deployment.pri)

HEADERS += \
    src/db/filesystem/index/common.h \
    src/db/filesystem/index/reader.h \
    src/db/filesystem/index/writer.h \
    src/db/db.h \
    src/db/filesystem/xml.h \
    src/db/record_data.h \
    src/db/settings.h \
    src/record_viewer/editor/custom_text_edit.h \
    src/record_viewer/editor/editor.h \
    src/record_viewer/editor/formatting_toolbar.h \
    src/record_viewer/links_list/link_view.h \
    src/record_viewer/links_list/links_list.h \
    src/record_viewer/links_list/vertical_scroll_area.h \
    src/record_viewer/record_viewer.h \
    src/utils/exception.h \
    src/main_window.h \
    src/navigation/search_line/search_line.h \
    src/navigation/tree/tree_model.h \
    src/navigation/tree/tree_view.h \
    src/navigation/navigation.h \
    src/record_viewer/title/record_title.h \
    src/record.h \
    src/dialogs/new_attachment_dialog.h \
    src/settings.h \
    src/db/database_reader.h \
    src/db/filesystem/database_reader.h \
    src/db/exceptions.h

DISTFILES +=

