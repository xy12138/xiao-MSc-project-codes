#ifndef ADCREADER
#define ADCREADER
#include <QThread>
#include <QDataStream>
#include <QBuffer>

class ADCreader : public QThread
{
public:
    ADCreader() {running = 0;};
    void quit();
    void run();
    float readData();
    float readData1();
    float readData2();
    float readDataF();
    float readDataL();
    QBuffer buffer;

private:
    bool running;
    FILE *fp;
    int dg1,dg2,dg3,dg4,dg5,dg6,dg7,dg8,dg9,dg10,dg11,dg12;
    char dgy[666];

};

#endif
