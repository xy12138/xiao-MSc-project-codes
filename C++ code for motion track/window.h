#ifndef WINDOW_H
#define WINDOW_H
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QBoxLayout>
#include "adcreader.h"
#include "zx.h"
#include "qcustomplot.h"

extern QVector<double> data_x, data_y;

// class definition 'Window'
class Window : public QWidget
{
    // must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
    Q_OBJECT

public:
    Window(); // default constructor - called when a Window is declared without arguments

    ~Window();

    void timerEvent( QTimerEvent * );

//public slots:
//	void setGain(double gain);

// internal variables for the window class
private:

    QwtPlot      *plot;
    QwtPlotCurve *curve;
    QwtPlot      *plot1;
    QwtPlotCurve *curve1;
    QwtPlot      *plotc;
    QwtPlotCurve *curvec;
    QwtPlot      *path_plot;
    QwtPlotCurve *path_curve;
    zx *dlg_zx;

    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    static const int plotDataSize = 100;

    // data arrays for the plot
    double xData[plotDataSize];
    double yData[plotDataSize];

    double xData1[plotDataSize];
    double yData1[plotDataSize];

    double xData_acc[plotDataSize];
    double yData_acc[plotDataSize];

    double v0 = 0;
    double v1 = 0;
    double s0 = 0;
    double s1 = 0;

    double gain;
    int count;

    FILE *fp;
    int dg1,dg2,dg3,dg4,dg5,dg6,dg7,dg8,dg9,dg10,dg11,dg12;
    char dgy[666];
    ADCreader *adcreader;
};

#endif // WINDOW_H
