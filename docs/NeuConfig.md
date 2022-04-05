# NeuConfig-Qt 开发文档

使用 Qt5 开发，通过图形化表格式的配置方法将配置神经元网络，将配置结果转化为一句单独的命令。









### Slider

结合 `QSlider` 与 `QSpinBox`：彼此设置槽函数 `valueChanged`，通过 `setValue` 函数改变值。

QSlider 没有小数，可以通过乘除彼此适应。

```cpp
void NeuConfigWidget::on_SynWeight_SL_valueChanged(int value)
{
    ui->SynWeight_SB->setValue(double(value)/100);
}

void NeuConfigWidget::on_SynWeight_SB_valueChanged(double arg1)
{
    ui->SynWeight_SL->setValue(int(arg1*100));
}
```



### Graphic

https://blog.csdn.net/qq_34139994/article/details/105301214





Graphic 的是面向对象的方式，使用起来过于复杂。而神经元网络属于固定的绘图，采用 QPaint 的方式进行。





### QPaint

QPaint 的方式更加简单。

https://blog.csdn.net/qq21497936/article/details/105506028

更新图表的方式

https://blog.csdn.net/u013928315/article/details/78195491

画笔画刷

```cpp
painter.setPen(QPen(Qt::blue,4));
```

图层覆盖问题，其实就是一个先后画图的顺序问题 。



### 神经元网络绘制

需要绘制神经元以及神经元连接。

算出数量，计算间隔，然后测试。

这种方式绘制神经元还可以，但是绘制网络则不太好，因为太容易饱和。20/7 = 2。

绘制神经元网络最好的方式是设计一个随机数组，确定数量，随机数组中随即一定位置。

随机数，排除。



设定突触的可设置最大数量为当前神经元数量。











画圆通过 C++ 标准库 math.h 提供的正弦和余弦函数绘制。