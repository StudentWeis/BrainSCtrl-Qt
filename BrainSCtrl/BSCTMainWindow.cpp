#include "BSCTMainWindow.h"
#include "ui_BSCTMainWindow.h"
#include <QLabel>

BSCTMainWindow::BSCTMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::BSCTMainWindow)
{
    ui->setupUi(this);

    NeuConfigW = new NeuConfigWidget();
    XSerialPortW = new XSerialPortWidget();

    connect(XSerialPortW, SIGNAL(serial_Recive(double)), ui->widget, SLOT(updateMbrlineChart(double)));

    connect(ui->actionsdf, SIGNAL(triggered(bool)), this, SLOT(guanyu()));

    QLabel *TJULable = new QLabel(this);
    TJULable->setText(tr("天津大学嵌入式小组"));
    ui->statusbar->addPermanentWidget(TJULable);
}

BSCTMainWindow::~BSCTMainWindow()
{
    delete ui;
}

void BSCTMainWindow::on_XSerialPort_Bt_clicked()
{
    XSerialPortW->show();
    ui->statusbar->showMessage("配置串口", 2000);
}

void BSCTMainWindow::on_Clear_Bt_clicked()
{
    ui->widget->clearChart();
    ui->statusbar->showMessage("清除图像", 1000);
}

void BSCTMainWindow::guanyu()
{
    QMessageBox::information(this, "关于",
                             "多核嵌入式神经元仿真平台 - BrainSCtrl v0.1\r\n若有问题请发邮件至 studentweis@gmail.com");
}
