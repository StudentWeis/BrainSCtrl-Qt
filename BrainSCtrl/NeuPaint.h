#ifndef NEUPAINT_H
#define NEUPAINT_H
#include <stdio.h>


#include <QWidget>

class NeuPaint : public QWidget
{
    Q_OBJECT
public:
    explicit NeuPaint(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int   NeuCount = 0;
    float SynRatio = 0;
    char * NeuMatrix = NULL;


signals:

};

#endif // NEUPAINT_H
