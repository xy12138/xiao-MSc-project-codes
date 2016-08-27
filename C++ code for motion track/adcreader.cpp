#include "adcreader.h"
#include <QDebug>
#include "window.h"
#include <QFile>

void ADCreader::run()
{

    fp = fopen("/dev/rfcomm0","r");

    running = true;
    while (running) {

        if (fp ==NULL)
        {
            qDebug() << "READ FAILURE";
            sleep(1);

        }
    else
        {
        while(fgets(dgy,sizeof(dgy),fp)){
//       //* used only when process offline  acceleration data*//
//            QString data(dgy);
//              if (data.left(data.indexOf(",")) !="-1" && data.right(data.lastIndexOf(",")) !="0")
//                  {
//                      printf("wrong");
//                      continue;
//                  }
              sscanf(dgy,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&dg1,&dg2,&dg3,&dg4,&dg5,&dg6,&dg7,&dg8,&dg9,&dg10,&dg11,&dg12);
              printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",dg1,dg2,dg3,dg4,dg5,dg6,dg7,dg8,dg9,dg10,dg11,dg12);
            }
        }

    }
}

float ADCreader::readDataF()
{
      return dg1;
    }

float ADCreader::readDataL()
{
      return dg12;
    }


float ADCreader::readData()
{
      return dg3;
    }

float ADCreader::readData1()
{
      return dg4;
    }

void ADCreader::quit()
{
    running = false;
    exit(0);
}
