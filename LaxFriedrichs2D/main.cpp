/* 
 * File:   main.cpp
 * Author: adray
 *
 * Created on November 15, 2011, 6:46 AM
 */

#include <cstdlib>
#include <iostream>
#include "data.h"
#include "CalcData2d.h"

using namespace std;

/*
 * 
 */
double limiter (double a, double b)
{
    return a;
}
int bound(Data2d data)
{
    for(int i = 0; i < data.area.width.divisions; i ++)
        for (int j = 0; j < data.area.length.divisions; j ++)
            data.elements[i][j].density = 666;
}
int main(int argc, char** argv) {

    
    Area2d area =
            *(new Area2d(
                *(new Segment(1,10)),
                *(new Segment(1,10)),
                *(new Segment(1,10))));
    DataElement **elements;
    elements = new DataElement*[10];
    for(int i = 0; i < 10; i ++)
        elements[i] = new DataElement[10];
    for(int i = 0; i < 10; i ++)
        elements[0][i].density = 100;
//        for (int j = 0; j < 10 ; j ++)
//            elements[i][j].density = 0;
    Data2d data = *(new Data2d(area, elements, 0));
    Data2d newData = data;
    

    CalcData2d *calc = new CalcData2d(bound, limiter, newData);
    newData = calc->nextLayer(newData);
    for(int i = 0; i < 10; i++)
        for(int j = 0 ; j < 10 ; j ++)
            std::cout << newData.elements[i][j].density;
    //area.length = Segment(1.0,10);
    return 0;
}

