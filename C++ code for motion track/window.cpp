#include "window.h"
#include "adcreader.h"
#include <cmath>  // for sine stuff
QVector<double> data_x, data_y;


Window::Window() : gain(5)
{
    // set up the initial plot data
    for( int index=0; index<plotDataSize; ++index )
    {
        xData[index] = index;
        yData[index] = gain * sin( M_PI * index/50 );
    }

    curve = new QwtPlotCurve;
    plot = new QwtPlot;
    // make a plot curve from the data and attach it to the plot
    curve->setSamples(xData, yData, plotDataSize);
    curve->attach(plot);

    plot->setTitle("Acceleration data of x axis");
    plot->setAxisTitle(QwtPlot::yLeft, "Value [m/s2]");
    plot->setAxisTitle(QwtPlot::xBottom, "");
    plot->replot();
    plot->show();

    for( int index=0; index<plotDataSize; ++index )
    {
        xData1[index] = index;
        yData1[index] = gain * sin( M_PI * index/50 );
    }

    curve1 = new QwtPlotCurve;
    plot1 = new QwtPlot;
    // make a plot curve from the data and attach it to the plot
    curve1->setSamples(xData1, yData1, plotDataSize);
    curve1->attach(plot1);

    plot1->setTitle("Acceleration data of y axis");
    plot1->setAxisTitle(QwtPlot::yLeft, "Value [m/s2]");
    plot1->setAxisTitle(QwtPlot::xBottom, "");
    plot1->replot();
    plot1->show();

    for( int index=0; index<plotDataSize; ++index )
    {
        xData_acc[index] = index;
        yData_acc[index] = gain * sin( M_PI * index/50 );
    }

    path_curve = new QwtPlotCurve;
    path_plot = new QwtPlot;
    // make a plot curve from the data and attach it to the plot
    path_curve->setSamples(xData_acc, xData_acc, plotDataSize);
    path_curve->attach(path_plot);

    path_plot->setAxisTitle(QwtPlot::yLeft, "Y coordinate [m]");
    path_plot->setAxisTitle(QwtPlot::xBottom, "X coordinate [m]");
    path_plot->setAxisScale(QwtPlot::yLeft, -25,25);
    path_plot->setAxisScale(QwtPlot::xBottom, -25, 25);
    path_plot->replot();
    path_plot->show();

    // set up the layout - knob above thermometer
    vLayout = new QVBoxLayout;
    vLayout->addWidget(plot);
    vLayout->addWidget(plot1);

    // plot to the left of knob and thermometer
    hLayout = new QHBoxLayout;
    hLayout->addWidget(path_plot);
    hLayout->addLayout(vLayout);
    setLayout(hLayout);

    adcreader = new ADCreader();
    adcreader->start();

    dlg_zx = new zx();
    dlg_zx->show();
}


Window::~Window() {
    // tells the thread to no longer run its endless loop
    adcreader->quit();
    // wait until the run method has terminated
    adcreader->wait();
    delete adcreader;
}

/*method 1: doing a = a + integration */\
void Window::timerEvent( QTimerEvent * )
{

    if (adcreader->readDataF()== -1 && adcreader->readDataL() < 5000)
    {
        /* ********************************************************** x-axis accleration **************************************/

    double inVal = adcreader->readData();
    double TinVal = 0.0000305*9.8*(inVal-45286);

    memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
    yData[plotDataSize-1] = TinVal;
     curve->setSamples(xData, yData, plotDataSize);
    plot->replot();

    // doing twice integration for x acceleratoion to get the x of positon in 2d coordinate axis
    v0 = v0 + TinVal - 0.7*v0 ;
    s0 = s0 + v0 - 0.7*s0 ;

    /* ********************************************************** y-axis accleration **************************************/

    double inVal1 = adcreader->readData1();
    double TinVal1 = 0.0000305*9.8*(inVal1-58746);
    memmove( yData1, yData1+1, (plotDataSize-1) * sizeof(double) );
    yData1[plotDataSize-1] = TinVal1;
    curve1->setSamples(xData1, yData1, plotDataSize);
    plot1->replot();

    // doing twice integration for y acceleratoion to get the y of positon in 2d coordinate axis
    v1 = v1 + TinVal1 - 0.7*v1;
    s1 = s1 + v1 - 0.7*s1 ;

    /* ********************************************************** track motion trace **************************************/
    //  plot the trace of devices
    data_x<<s0;
    data_y<<s1;
    dlg_zx->data_up();
    path_curve->setSamples(&s0,&s1,plotDataSize);
    path_plot->replot();

    }
    else
        printf ("wrong");

}
