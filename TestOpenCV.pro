TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++17 opencv cmdline
INCLUDEPATH += /usr/local/include/opencv4
LIBS += -L/usr/local/lib
LIBS += \
    -lopencv_core \
    -lopencv_features2d \
    -lopencv_highgui \
    -lopencv_imgcodecs \
    -lopencv_imgproc \
    -lopencv_calib3d \
    -lopencv_videoio \

SOURCES += \
        main.cpp

DISTFILES += \
    image.jpg
