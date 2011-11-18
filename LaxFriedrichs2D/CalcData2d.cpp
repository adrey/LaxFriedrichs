/* 
 * File:   CalcData2d.cpp
 * Author: adray
 * 
 * Created on November 17, 2011, 2:59 AM
 */

#include "CalcData2d.h"

CalcData2d::CalcData2d
            (int (*_boundSetter)(Data2d),
            double (*_limiter)(double,double),
            Data2d data)
{
    limiter = _limiter;
    boundSetter = _boundSetter;

}

CalcData2d::CalcData2d(const CalcData2d& orig) {
}

CalcData2d::~CalcData2d() {
}
Data2d CalcData2d::nextLayer(Data2d data)
{
    DataElement** elms = new DataElement*[data.area.width.divisions];
    for (int i = 0; i < data.area.width.divisions; i ++)
        elms[i] = new DataElement[data.area.length.divisions];
    Data2d newData = *(new Data2d(data.area,elms, data.currentTimeStep + 1 ));
    for(int i = 0; i < data.area.width.divisions; i ++)
        for (int j = 0; j < data.area.length.divisions; j ++)
        {
            newData.elements[i][j].density = newData.currentTimeStep;
        }
    boundSetter(newData);
    return newData;
}

