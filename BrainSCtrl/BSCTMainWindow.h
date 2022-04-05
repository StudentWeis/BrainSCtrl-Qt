#ifndef BSCTMAINWINDOW_H
#define BSCTMAINWINDOW_H

#include <NeuConfigWidget.h>
#include <QMainWindow>
#include <XSerialPortWidget.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
class BSCTMainWindow;
}
QT_END_NAMESPACE

class BSCTMainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    BSCTMainWindow(QWidget *parent = nullptr);
    ~BSCTMainWindow();

    NeuConfigWidget *NeuConfigW;
    XSerialPortWidget *XSerialPortW;

  private slots:
    void on_XSerialPort_Bt_clicked();
    void on_Clear_Bt_clicked();
    void guanyu();

  private:
    Ui::BSCTMainWindow *ui;
};
#endif // BSCTMAINWINDOW_H
