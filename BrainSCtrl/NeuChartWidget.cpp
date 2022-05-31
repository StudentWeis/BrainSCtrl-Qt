#include "NeuChartWidget.h"
#include "ui_NeuChartWidget.h"

NeuChartWidget::NeuChartWidget(QWidget *parent) : QWidget(parent), ui(new Ui::NeuChartWidget)
{
    ui->setupUi(this);

    /* 绘制膜电位图表 */
    lineChart = new QChart();
    lineSeries = new QLineSeries();
    lineAxY = new QValueAxis();
    lineAxX = new QValueAxis();
    mbrlineChart();

    /* 绘制放电栅格图表 */
    gridChart = new QChart();
    gridSeries = new QScatterSeries();
    gridAxY = new QValueAxis();
    gridAxX = new QValueAxis();

    spkgridChart();
}

NeuChartWidget::~NeuChartWidget()
{
    delete ui;
}

/**
 * @brief 绘制膜电位图表
 */
void NeuChartWidget::mbrlineChart()
{
    /* 设置坐标轴 */
    lineAxX->setRange(0, 99);           // 设置 X 轴范围
    lineAxY->setRange(-75, 75);          // 设置 Y 轴范围
    lineAxX->setLabelsVisible(false);   // 隐藏 X 轴坐标
    lineAxX->setGridLineVisible(false); // 隐藏背景网格 X 轴框线
    lineAxY->setGridLineVisible(false); // 隐藏背景网格 Y 轴框线

    /* 设置图表 */
    lineChart->addAxis(lineAxY, Qt::AlignLeft); // 设置坐标轴位置
    lineChart->addAxis(lineAxX, Qt::AlignBottom);
    lineChart->setTheme(QChart::ChartThemeDark); // 设置图表主题
    lineChart->setContentsMargins(0, 0, 0, 0);   // 设置内外边界全部为 0
    lineChart->setMargins(QMargins(0, 0, 0, 0));
    lineChart->setBackgroundRoundness(0); // 设置背景区域无圆角
    ui->widget->setChart(lineChart);

    /* 设置曲线 */
    lineChart->addSeries(lineSeries);
    lineSeries->attachAxis(lineAxY);
    lineSeries->attachAxis(lineAxX);
    lineSeries->setColor(QColor(255, 0, 0));

    /* 隐藏图例说明 */
    QLegend *mlegend = lineChart->legend();
    mlegend->setVisible(false);
}

/**
 * @brief 槽函数：更新膜电位图表，在队尾添加新的数值
 */
void NeuChartWidget::updateMbrlineChart(double value)
{
    /* 膜电位线前推一格 */
    for (int i = 0; i < (POINTS_NUM_OF_MEMLINE - 1); i++)
    {
        membrane_line[i] = membrane_line[i + 1];
    }
    membrane_line[(POINTS_NUM_OF_MEMLINE - 1)] = value; // 更新在队尾的值

    /* 重新绘图 */
    lineSeries->clear();
    for (int i = 0; i < POINTS_NUM_OF_MEMLINE; i++)
    {
        lineSeries->append(i, membrane_line[i]);
    }
}

/**
 * @brief 绘制放电栅格图
 */
void NeuChartWidget::spkgridChart()
{
    /* 设置坐标轴属性 */
    gridAxX->setRange(0, 99);                     // 设置 X 轴范围
    gridAxY->setRange(0, 19);                     // 设置 Y 轴范围
    gridAxX->setLabelsVisible(false);             // 隐藏 X 轴坐标
    gridAxX->setGridLineVisible(false);           // 隐藏背景网格 X 轴框线
    gridAxY->setGridLineVisible(false);           // 隐藏背景网格 Y 轴框线
    gridChart->addAxis(gridAxY, Qt::AlignLeft);   // 设置 X 轴位置
    gridChart->addAxis(gridAxX, Qt::AlignBottom); // 设置 Y 轴位置

    /* 设置图表 */
    gridChart->setMargins(QMargins(0, 0, 0, 0));
    gridChart->setTheme(QChart::ChartThemeDark); // 设置主题风格
    ui->widget_2->setChart(gridChart);           // 显示到界面上

    /* 设置散点属性 */
    gridSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    gridSeries->setMarkerSize(2);
    gridSeries->setColor(QColor(255, 255, 255));
    gridChart->addSeries(gridSeries);
    gridSeries->attachAxis(gridAxX);
    gridSeries->attachAxis(gridAxY);
    gridSeries->setPen(QPen(Qt::NoPen)); // 画出的点不带轮廓

    /* 隐藏图例说明 */
    QLegend *mlegend = gridChart->legend();
    mlegend->setVisible(false);
}

void NeuChartWidget::updatespkgridChart()
{
}

void NeuChartWidget::clearChart()
{
    lineSeries->clear();
    gridSeries->clear();
}
