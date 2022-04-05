#include "BSCTMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BSCTMainWindow w;
    w.show();
    return a.exec();
}
