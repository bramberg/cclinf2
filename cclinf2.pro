TEMPLATE = app

QT += qml quick widgets

QMAKE_CXXFLAGS += -std=c++14 -pedantic

SOURCES += models/tree/tree_model.cc \
    views/main_window/main_window.cc \
    views/tree/tree.cc \
    views/edit/edit.cc \
    views/search_line/search_line.cc \
    models/db/record.cc \
    models/db/record_data.cc \
    models/db/filesystem/db.cc \
    utils/exception.cc \
    models/db/filesystem/index/common.cc \
    models/db/filesystem/index/reader.cc \
    models/db/filesystem/index/writer.cc \
    models/db/filesystem/xml.cc \
    models/db/settings.cc \
    views/list_of_attaches.cc \
    views/edit/editmodel.cc \
    views/edit/formatting_toolbar.cc \
    views/edit/text_edit.cc \
    main.cpp

INCLUDEPATH += ./.

RESOURCES += \
    resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    views/main_window/main_window.h \
    views/tree/tree.h \
    views/edit/edit.h \
    views/search_line/search_line.h \
    models/tree/tree_model.h \
    models/tree/xml.h \
    models/db/filesystem/xml.h \
    models/db/record.h \
    models/db/record_data.h \
    models/db/filesystem/db.h \
    utils/exception.h \
    models/db/filesystem/xml/writer.h \
    models/db/filesystem/xml/xml.h \
    models/db/filesystem/index/common.h \
    models/db/filesystem/index/reader.h \
    models/db/filesystem/index/writer.h \
    models/db/settings.h \
    views/list_of_attaches.h \
    views/edit/editmodel.h \
    views/edit/formatting_toolbar.h \
    views/edit/text_edit.h

DISTFILES += \
    material-icons/core/accessibility.svg \
    material-icons/core/account-box.svg \
    material-icons/core/account-circle.svg \
    material-icons/core/add.svg \
    material-icons/core/add-box.svg \
    material-icons/core/add-circle.svg \
    material-icons/core/add-circle-outline.svg \
    material-icons/core/android.svg \
    material-icons/core/apps.svg \
    material-icons/core/archive.svg \
    material-icons/core/arrow-back.svg \
    material-icons/core/arrow-drop-down.svg \
    material-icons/core/arrow-drop-down-circle.svg \
    material-icons/core/arrow-drop-up.svg \
    material-icons/core/arrow-forward.svg \
    material-icons/core/attachment.svg \
    material-icons/core/backspace.svg \
    material-icons/core/backup.svg \
    material-icons/core/block.svg \
    material-icons/core/book.svg \
    material-icons/core/bookmark.svg \
    material-icons/core/bookmark-outline.svg \
    material-icons/core/bug-report.svg \
    material-icons/core/cancel.svg \
    material-icons/core/check.svg \
    material-icons/core/check-box.svg \
    material-icons/core/check-box-blank.svg \
    material-icons/core/check-box-outline.svg \
    material-icons/core/check-box-outline-blank.svg \
    material-icons/core/check-circle.svg \
    material-icons/core/check-circle-blank.svg \
    material-icons/core/check-circle-outline.svg \
    material-icons/core/check-circle-outline-blank.svg \
    material-icons/core/chevron-left.svg \
    material-icons/core/chevron-right.svg \
    material-icons/core/clear.svg \
    material-icons/core/close.svg \
    material-icons/core/cloud.svg \
    material-icons/core/cloud-circle.svg \
    material-icons/core/cloud-done.svg \
    material-icons/core/cloud-download.svg \
    material-icons/core/cloud-off.svg \
    material-icons/core/cloud-queue.svg \
    material-icons/core/cloud-upload.svg \
    material-icons/core/content-copy.svg \
    material-icons/core/content-cut.svg \
    material-icons/core/content-paste.svg \
    material-icons/core/create.svg \
    material-icons/core/credit-card.svg \
    material-icons/core/delete.svg \
    material-icons/core/done.svg \
    material-icons/core/done-all.svg \
    material-icons/core/drafts.svg \
    material-icons/core/drawer.svg \
    material-icons/core/drive.svg \
    material-icons/core/drive-document.svg \
    material-icons/core/drive-drawing.svg \
    material-icons/core/drive-file.svg \
    material-icons/core/drive-form.svg \
    material-icons/core/drive-fusiontable.svg \
    material-icons/core/drive-image.svg \
    material-icons/core/drive-ms-excel.svg \
    material-icons/core/drive-ms-powerpoint.svg \
    material-icons/core/drive-ms-word.svg \
    material-icons/core/drive-pdf.svg \
    material-icons/core/drive-presentation.svg \
    material-icons/core/drive-script.svg \
    material-icons/core/drive-site.svg \
    material-icons/core/drive-spreadsheet.svg \
    material-icons/core/drive-video.svg \
    material-icons/core/error.svg \
    material-icons/core/event.svg \
    material-icons/core/exit-to-app.svg \
    material-icons/core/expand-less.svg \
    material-icons/core/expand-more.svg \
    material-icons/core/explore.svg \
    material-icons/core/extension.svg \
    material-icons/core/favorite.svg \
    material-icons/core/favorite-outline.svg \
    material-icons/core/file-download.svg \
    material-icons/core/file-upload.svg \
    material-icons/core/filter.svg \
    material-icons/core/flag.svg \
    material-icons/core/flip-to-back.svg \
    material-icons/core/flip-to-front.svg \
    material-icons/core/folder.svg \
    material-icons/core/folder-mydrive.svg \
    material-icons/core/folder-shared.svg \
    material-icons/core/forward.svg \
    material-icons/core/fullscreen.svg \
    material-icons/core/fullscreen-exit.svg \
    material-icons/core/gesture.svg \
    material-icons/core/google.svg \
    material-icons/core/google-plus.svg \
    material-icons/core/help.svg \
    material-icons/core/history.svg \
    material-icons/core/home.svg \
    material-icons/core/https.svg \
    material-icons/core/inbox.svg \
    material-icons/core/info.svg \
    material-icons/core/info-outline.svg \
    material-icons/core/invert-colors.svg \
    material-icons/core/keep.svg \
    material-icons/core/label.svg \
    material-icons/core/label-outline.svg \
    material-icons/core/language.svg \
    material-icons/core/launch.svg \
    material-icons/core/link.svg \
    material-icons/core/list.svg \
    material-icons/core/lock.svg \
    material-icons/core/lock-open.svg \
    material-icons/core/lock-outline.svg \
    material-icons/core/mail.svg \
    material-icons/core/markunread.svg \
    material-icons/core/menu.svg \
    material-icons/core/more-horiz.svg \
    material-icons/core/more-vert.svg \
    material-icons/core/polymer.svg \
    material-icons/core/print.svg \
    material-icons/core/radio-button-off.svg \
    material-icons/core/radio-button-on.svg \
    material-icons/core/receipt.svg \
    material-icons/core/refresh.svg \
    material-icons/core/reminder.svg \
    material-icons/core/remove.svg \
    material-icons/core/remove-circle.svg \
    material-icons/core/remove-circle-outline.svg \
    material-icons/core/reply.svg \
    material-icons/core/reply-all.svg \
    material-icons/core/report.svg \
    material-icons/core/rotate-left.svg \
    material-icons/core/rotate-right.svg \
    material-icons/core/save.svg \
    material-icons/core/schedule.svg \
    material-icons/core/search.svg \
    material-icons/core/select-all.svg \
    material-icons/core/send.svg \
    material-icons/core/settings.svg \
    material-icons/core/settings-applications.svg \
    material-icons/core/settings-bluetooth.svg \
    material-icons/core/settings-cell.svg \
    material-icons/core/settings-phone.svg \
    material-icons/core/settings-power.svg \
    material-icons/core/settings-voice.svg \
    material-icons/core/shopping-basket.svg \
    material-icons/core/shopping-cart.svg \
    material-icons/core/sort.svg \
    material-icons/core/star.svg \
    material-icons/core/star-half.svg \
    material-icons/core/star-outline.svg \
    material-icons/core/star-rate.svg \
    material-icons/core/store.svg \
    material-icons/core/swap-driving-apps.svg \
    material-icons/core/swap-horiz.svg \
    material-icons/core/swap-vert.svg \
    material-icons/core/swap-vert-circle.svg \
    material-icons/core/tab.svg \
    material-icons/core/tab-unselected.svg \
    material-icons/core/text-format.svg \
    material-icons/core/theaters.svg \
    material-icons/core/thumb-down.svg \
    material-icons/core/thumb-up.svg \
    material-icons/core/today.svg \
    material-icons/core/translate.svg \
    material-icons/core/undo.svg \
    material-icons/core/unfold-less.svg \
    material-icons/core/unfold-more.svg \
    material-icons/core/view-array.svg \
    material-icons/core/view-column.svg \
    material-icons/core/view-headline.svg \
    material-icons/core/view-list.svg \
    material-icons/core/view-module.svg \
    material-icons/core/view-quilt.svg \
    material-icons/core/view-stream.svg \
    material-icons/core/visibility.svg \
    material-icons/core/visibility-off.svg \
    material-icons/core/warning.svg
