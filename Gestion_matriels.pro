QT += core gui sql multimedia multimediawidgets printsupport charts widgets axcontainer serialport network
QT +=serialport
QT += sql
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11
SOURCES += \
    archive.cpp \
    archiveui.cpp \
    auditui.cpp \
    dialogvideo.cpp \
    employerui.cpp \
    entreprise.cpp \
    generateurpdf.cpp \
    matrielui.cpp \
    norme.cpp \
    arduino.cpp \
    connection.cpp \
    exportexcelobject.cpp \
    main.cpp \
    mainwindow.cpp \
    matriels.cpp \
    normeui.cpp \
    notification.cpp \
    audits.cpp \
    calendrier.cpp \
    employer.cpp \
    login.cpp \
    menu.cpp  \
    qrcode.cpp \
    smtp.cpp

HEADERS += \
    archive.h \
    archiveui.h \
    auditui.h \
   dialogvideo.h \
    employerui.h \
    entreprise.h \
    generateurpdf.h \
    matrielui.h \
    norme.h \
    arduino.h \
    connection.h \
    exportexcelobject.h \
    mainwindow.h \
    matriels.h \
    normeui.h \
    notification.h \
    audits.h \
    calendrier.h \
    employer.h \
    login.h \
    menu.h \
    qrcode.h \
    smtp.h

FORMS += \
    archiveui.ui \
    auditui.ui \
    dialogvideo.ui \
    employerui.ui \
    mainwindow.ui \
    login.ui \
    matrielui.ui \
    menu.ui \
    normeui.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
