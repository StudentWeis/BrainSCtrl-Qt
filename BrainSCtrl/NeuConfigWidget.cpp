#include "NeuConfigWidget.h"
#include "ui_NeuConfigWidget.h"

#include <QPainter>


NeuConfigWidget::NeuConfigWidget(QWidget *parent) : QWidget(parent), ui(new Ui::NeuConfigWidget)
{
    ui->setupUi(this);

}

NeuConfigWidget::~NeuConfigWidget()
{
    delete ui;
}

/**
 * @brief Slider 和 SpinBox 联动
 */
void NeuConfigWidget::on_NeuCount_SL_valueChanged(int value)
{
    ui->NeuCount_SB->setValue(value);
    ui->NeuWidget->NeuCount = ui->NeuCount_SB->value();
    ui->NeuWidget->update();
}
void NeuConfigWidget::on_NeuCount_SB_valueChanged(int arg1)
{
    ui->NeuCount_SL->setValue(arg1);
}
void NeuConfigWidget::on_SynWeight_SL_valueChanged(int value)
{
    ui->SynWeight_SB->setValue(double(value)/100);
}
void NeuConfigWidget::on_SynWeight_SB_valueChanged(double arg1)
{
    ui->SynWeight_SL->setValue(int(arg1*100));
}
void NeuConfigWidget::on_SynRatio_SL_valueChanged(int value)
{
    ui->SynRatio_SB->setValue(double(value)/100);
    ui->NeuWidget->SynRatio = ui->SynRatio_SB->value();
    ui->NeuWidget->update();
}
void NeuConfigWidget::on_SynRatio_SB_valueChanged(double arg1)
{
    ui->SynRatio_SL->setValue(int(arg1*100));
}
void NeuConfigWidget::on_CpuCount_SL_valueChanged(int value)
{
    ui->CpuCount_SB->setValue(value);
}
void NeuConfigWidget::on_CpuCount_SB_valueChanged(int arg1)
{
    ui->CpuCount_SL->setValue(arg1);
}
