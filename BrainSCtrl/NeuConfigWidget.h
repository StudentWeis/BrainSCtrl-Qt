#ifndef NEUCONFIGWIDGET_H
#define NEUCONFIGWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
class NeuConfigWidget;
}
QT_END_NAMESPACE

class NeuConfigWidget : public QWidget
{
    Q_OBJECT

  public:
    NeuConfigWidget(QWidget *parent = nullptr);
    ~NeuConfigWidget();


private slots:
    void on_NeuCount_SL_valueChanged(int value);
    void on_NeuCount_SB_valueChanged(int arg1);
    void on_SynWeight_SL_valueChanged(int value);
    void on_SynWeight_SB_valueChanged(double arg1);
    void on_SynRatio_SL_valueChanged(int value);
    void on_SynRatio_SB_valueChanged(double arg1);
    void on_CpuCount_SL_valueChanged(int value);
    void on_CpuCount_SB_valueChanged(int arg1);

private:
    Ui::NeuConfigWidget *ui;
};
#endif // NEUCONFIGWIDGET_H
