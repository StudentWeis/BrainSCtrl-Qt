#ifndef NEUCHART_H
#define NEUCHART_H

#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QScatterSeries>
#include <QValueAxis>
#include <QWidget>

extern int NeuCount;

#define POINTS_NUM_OF_MEMLINE 100 // 膜电位图表最大显示点数

QT_BEGIN_NAMESPACE
namespace Ui
{
class NeuChartWidget;
}
QT_END_NAMESPACE

class NeuChartWidget : public QWidget
{
    Q_OBJECT

  public:
    NeuChartWidget(QWidget *parent = nullptr);
    ~NeuChartWidget();

    QChart *lineChart = NULL;
    QValueAxis *lineAxX = NULL;
    QValueAxis *lineAxY = NULL;
    QLineSeries *lineSeries = NULL;
    qreal membrane_line[POINTS_NUM_OF_MEMLINE]; // 膜电位图表曲线
    void mbrlineChart();
    void clearChart();

    QValueAxis *gridAxX = NULL;
    QValueAxis *gridAxY = NULL;
    QChart *gridChart = NULL;
    QScatterSeries *gridSeries = NULL;
    void spkgridChart();

  private slots:
    void updateMbrlineChart(double value);
    void updateSpkgridChart();

  private:
    Ui::NeuChartWidget *ui;
};
#endif // NEUCHART_H
