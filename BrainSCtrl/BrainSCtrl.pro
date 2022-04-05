QT       += core gui charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NeuChartWidget.cpp \
    NeuConfigWidget.cpp \
    NeuPaint.cpp \
    SerialPortList.cpp \
    XSerialPortWidget.cpp \
    main.cpp \
    BSCTMainWindow.cpp

HEADERS += \
    BSCTMainWindow.h \
    NeuChartWidget.h \
    NeuConfigWidget.h \
    NeuPaint.h \
    SerialPortList.h \
    XSerialPortWidget.h

FORMS += \
    BSCTMainWindow.ui \
    NeuChartWidget.ui \
    NeuConfigWidget.ui \
    XSerialPortWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
