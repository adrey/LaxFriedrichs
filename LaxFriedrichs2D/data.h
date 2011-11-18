/* 
 * File:   data.h
 * Author: adray
 *
 * Created on November 15, 2011, 8:18 AM
 */

#ifndef DATA_H
#define DATA_H
struct DataElement
{
    double fullEnergy;
    double innerEnergy;
    double pressure;
    double density;
    double velocityX;
    double velocityY;
};
struct Segment
{
    Segment()
    {
        
    }
    Segment(double _length, int _divisions)
    {
        length = _length;
        divisions = _divisions;
    };
    Segment(Segment& orig)
    {
        length = orig.length;
        divisions = orig.divisions;
    }
    double length;
    int divisions;
};
struct Area2d
{
    Area2d(){}
    Area2d(Segment _lenght, Segment _width, Segment _time)
    {

        length = _lenght;
        width = _width;
        time = _time;
    }
    Segment length;
    Segment width;
    Segment time;
};
struct Data2d
{

    
    Data2d(const char*);
    Data2d(Area2d _area, DataElement ** _elements, int timeStep)
    {
        area = _area;
        elements = _elements;
        currentTimeStep = timeStep;
    };
    //Data2d(const Data2d& orig);


    //DataElement** getElements();
    int toFile(const char*);


    Area2d area;
    int currentTimeStep;
    DataElement **elements;

};
#endif