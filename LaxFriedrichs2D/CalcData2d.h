/* 
 * File:   CalcData2d.h
 * Author: adray
 *
 * Created on November 17, 2011, 2:59 AM
 */

#ifndef CALCDATA2D_H
#define	CALCDATA2D_H
#include "data.h"
class CalcData2d {
public:
    CalcData2d
            (int (*_boundSetter)(Data2d),
            double (*_limiter)(double,double),
            Data2d);
    CalcData2d(const CalcData2d& orig);
    virtual ~CalcData2d();

    Data2d nextLayer(Data2d);
    Data2d nextLayer(Data2d,int);
private:
    int (*boundSetter)(Data2d);
    double (*limiter)(double, double);
    Area2d area;
    DataElement **elements;
    Data2d predictor(Data2d data);
    Data2d corrector(Data2d data);
};

#endif	/* CALCDATA2D_H */

