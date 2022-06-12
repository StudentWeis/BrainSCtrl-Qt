#ifndef NEUPAINT_H
#define NEUPAINT_H
#include <stdio.h>


#include <QWidget>

extern int NeuCount;

class NeuPaint : public QWidget
{
    Q_OBJECT
public:
    explicit NeuPaint(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);


    float SynRatio = 0;
    char * NeuMatrix = NULL;


signals:

};

#endif // NEUPAINT_H
