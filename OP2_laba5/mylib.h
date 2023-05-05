#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class TTriangle{
protected:
    float Ax, Ay, Bx, By, Cx, Cy;
public:
    
    TTriangle();
        
    virtual double calcS();
    double calcP();
};

class IsoTriangle:public TTriangle{
public:
    IsoTriangle(float Ax_, float Ay_, float Bx_, float By_, float Cx_, float Cy_);
};

class EquTriangle:public TTriangle{
public:
    EquTriangle(float Ax_, float Ay_, float Bx_, float By_, float Cx_, float Cy_);
    double calcS();
};

class RTriangle:public TTriangle{
public:
    RTriangle(float Ax_, float Ay_, float Bx_, float By_, float Cx_, float Cy_);
    double calcS();
};
