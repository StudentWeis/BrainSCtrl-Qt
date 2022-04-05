#include "NeuPaint.h"
#include <QDebug>
#include <QPainter>
#include <cmath>
#include <stdlib.h>
#include <string>

#define DRAW_CIRCLE_R3(x, y) painter.drawEllipse(x - 3, y - 3, 6, 6)

NeuPaint::NeuPaint(QWidget *parent) : QWidget(parent)
{
}

void NeuPaint::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.save();

    painter.setBrush(QColor(255, 0, 0));

    // 创建随机矩阵
    srand(time(0));
    int temp = (NeuCount * 8) * (NeuCount * 8);
    NeuMatrix = (char *)malloc(temp);
    for (int i = 0; i < NeuCount * 8; i++)
    {
        for (int j = 0; j < NeuCount * 8; j++)
        {
            NeuMatrix[i * NeuCount * 8 + j] = rand() % 100 + 1;
        }
    }

    QPoint Neu[NeuCount * 8];
    if (NeuCount == 0)
        ;
    else
    {
        // 画点并记录点的坐标
        for (int i = 1; i < 2 * NeuCount + 1; i++)
        {
            int temp_x = round(150 * (sin(i * 3.14 / (4 * NeuCount + 2))));
            int temp_y = round(150 * (cos(i * 3.14 / (4 * NeuCount + 2))));
            DRAW_CIRCLE_R3(160 + temp_x, 160 + temp_y);
            Neu[(i - 1) * 4] = QPoint(160 + temp_x, 160 + temp_y);
            DRAW_CIRCLE_R3(160 + temp_x, 160 - temp_y);
            Neu[(i - 1) * 4 + 1] = QPoint(160 + temp_x, 160 - temp_y);
            DRAW_CIRCLE_R3(160 - temp_x, 160 + temp_y);
            Neu[(i - 1) * 4 + 2] = QPoint(160 - temp_x, 160 + temp_y);
            DRAW_CIRCLE_R3(160 - temp_x, 160 - temp_y);
            Neu[(i - 1) * 4 + 3] = QPoint(160 - temp_x, 160 - temp_y);
        }
        // 画线
        for (int i = 0; i < NeuCount * 8; i++)
        {
            for (int j = 0; j < NeuCount * 8; j++)
            {
                // 根据随机矩阵确定比例
                if (NeuMatrix[i * (NeuCount * 8 - 1) + j] < round(SynRatio * 100))
                {
                    painter.drawLine(Neu[i], Neu[j]);
                }
            }
        }
    }

    // 加了 free 会卡死，不知为何
    // free(NeuMatrix);
    painter.restore();
}
