#include "zx.h"
#include "ui_zx.h"
#include "window.h"
#include "qdebug.h"

zx::zx(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zx)
{
    ui->setupUi(this);
    /***********************set background***************************/
      QLinearGradient plotGradient_1;
      plotGradient_1.setStart(0, 0);
      plotGradient_1.setFinalStop(0, 350);
      plotGradient_1.setColorAt(0, Qt::white);//background gradually changes
      plotGradient_1.setColorAt(1, Qt::white);//background gradually changes
      ui->qCustomPlot_1->setBackground(plotGradient_1);


      ui->qCustomPlot_1->xAxis->setAutoTickStep(false);
      ui->qCustomPlot_1->yAxis->setAutoTickStep(false);
      ui->qCustomPlot_1->xAxis->setTickStep(1);        //t spacing of x axis
      ui->qCustomPlot_1->yAxis->setTickStep(1);        //t spacing of y axis


      /***********************set the colour of axis***************************/
      ui->qCustomPlot_1->xAxis->setBasePen(QPen(Qt::black, 1));// set the colour of x aixs
      ui->qCustomPlot_1->yAxis->setBasePen(QPen(Qt::black, 1));//t the colour of y aixs
      ui->qCustomPlot_1->xAxis->setTickPen(QPen(Qt::black, 1));
      ui->qCustomPlot_1->yAxis->setTickPen(QPen(Qt::black, 1));
      ui->qCustomPlot_1->xAxis->setSubTickPen(QPen(Qt::black, 1));
      ui->qCustomPlot_1->yAxis->setSubTickPen(QPen(Qt::black, 1));
      ui->qCustomPlot_1->xAxis->setTickLabelColor(Qt::black);
      ui->qCustomPlot_1->yAxis->setTickLabelColor(Qt::black);

      /***********************set background auxiliary corrdinates***************************/
      ui->qCustomPlot_1->xAxis->grid()->setPen(QPen(Qt::blue, 1, Qt::DotLine));//t the grid of x axis
      ui->qCustomPlot_1->yAxis->grid()->setPen(QPen(Qt::blue, 1, Qt::DotLine));//t the grid of y axis
      ui->qCustomPlot_1->xAxis->grid()->setSubGridVisible(true); //t the visiblity of subGrid for x axis
      ui->qCustomPlot_1->yAxis->grid()->setSubGridVisible(true); //t the visiblity of subGrid for x axis

      ui->qCustomPlot_1->xAxis->grid()->setZeroLinePen(Qt::NoPen);
      ui->qCustomPlot_1->yAxis->grid()->setZeroLinePen(Qt::NoPen);
      ui->qCustomPlot_1->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
      ui->qCustomPlot_1->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
      /***********************set the range of axis***************************/
      ui->qCustomPlot_1->xAxis->setRange(-5,5);
      ui->qCustomPlot_1->yAxis->setRange(-5,5);

      /***********************set trace***************************/
      fermatSpiral1 = new QCPCurve(ui->qCustomPlot_1->xAxis, ui->qCustomPlot_1->yAxis);
      ui->qCustomPlot_1->addPlottable(fermatSpiral1);
      fermatSpiral1->setAntialiased(false);
      fermatSpiral1->setPen(QPen(Qt::red));

      ui->qCustomPlot_1->xAxis->setLabel("x position");
      ui->qCustomPlot_1->yAxis->setLabel("y position");
}

void zx::data_up()

{

     fermatSpiral1->setData(data_x, data_y);

      ui->qCustomPlot_1->replot();

}

zx::~zx()
{
    delete ui;
}

void zx::on_pushButton_clicked()
{
    data_x.clear();
    data_y.clear();
    fermatSpiral1->setData(data_x, data_y);
    ui->qCustomPlot_1->replot();
}

void zx::on_pushButton_2_clicked()
{
    data_x.clear();
    data_y.clear();
    QFile file("./minix.txt");
    double v0;
    double s0;
    if (file.exists())
    {qDebug("x ok");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
       for(int i=1;i<601;i++)
       {
         QString data = QString(file.readLine());

         double TinVal = 0.0000305*(data.toInt()-45286);
         v0 = v0 + 9.8*TinVal;
         s0 = s0 + v0;
         data_x<<s0;
         printf("s0=%f\n",s0);

       }
    }
    QFile file1("./miniy.txt");
    if (file1.exists())
    {qDebug("y ok");
        file1.open(QIODevice::ReadOnly | QIODevice::Text);
        double v1;
        double s1;
       for(int i=1;i<601;i++)
       {
         QString data1 = QString(file1.readLine());
         double TinVal1 = 0.0000305*(data1.toInt()-58746);
         v1 = v1 + 9.8*TinVal1;
         s1 = s1 + v1;
         data_y<<s1;
         printf("s1=%f\n",s1);

       }
    }
    fermatSpiral1->setData(data_x, data_y);
    ui->qCustomPlot_1->replot();
}
