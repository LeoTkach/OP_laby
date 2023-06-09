#include "mylib.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
  
TTriangle::TTriangle(){
}
    
double TTriangle::calcS(){
    double a=pow(pow(Ax-Bx,2)+pow(Ay-By,2),0.5);
    double b=pow(pow(Cx-Bx,2)+pow(Cy-By,2),0.5);
    double c=pow(pow(Ax-Cx,2)+pow(Ay-Cy,2),0.5);
    return round(pow(((a+b+c)/2)*((a+b+c)/2-a)*((a+b+c)/2-b)*((a+b+c)/2-c),0.5)*100)/100;
}

double TTriangle::calcP(){
    double a=pow(pow(Ax-Bx,2)+pow(Ay-By,2),0.5);
    double b=pow(pow(Cx-Bx,2)+pow(Cy-By,2),0.5);
    double c=pow(pow(Ax-Cx,2)+pow(Ay-Cy,2),0.5);
    return round((a+b+c)*100)/100;
}

IsoTriangle::IsoTriangle(float Ax_, float Ay_, float Bx_, float By_, float Cx_, float Cy_) {
    int flag;
    do{
        flag=1;
        if (((Cx_==Ax_ && Cx_==Bx_) || (Cy_==Ay_ && Cy_==By_) || (((Cx_ - Ax_) *1.0)/ (Bx_ - Ax_) == ((Cy_ - Ay_) *1.0)/ (By_ - Ay_)))
        || !((abs(pow(Ax_-Bx_,2)+pow(Ay_-By_,2)-pow(Cx_-Bx_,2)-pow(Cy_-By_,2))<0.1) || (abs(pow(Ax_-Bx_,2)+pow(Ay_-By_,2)-pow(Ax_-Cx_,2)-pow(Ay_-Cy_,2))<0.1) || (abs(pow(Ax_-Cx_,2)+pow(Ay_-Cy_,2)-pow(Cx_-Bx_,2)-pow(Cy_-By_,2))<0.1))){
            cout<<"You entered invalid values triangle edges must not lie on one line and at least two sides of the triangle must be equal"<<endl;
            cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
            cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
            flag=0;
        }
        Ax=Ax_;
        Ay=Ay_;
        Bx=Bx_;
        By=By_;
        Cx=Cx_;
        Cy=Cy_;        
    }while(flag==0);
}

EquTriangle::EquTriangle(float Ax_, float Ay_, float Bx_, float By_, float Cx_, float Cy_) {
    int flag;
    do{
        flag=1;
        if ((Cx_==Ax_ && Cx_==Bx_) || (Cy_==Ay_ && Cy_==By_) || (((Cx_ - Ax_) *1.0)/ (Bx_ - Ax_) == ((Cy_ - Ay_) *1.0)/ (By_ - Ay_))
        || !((abs(pow(Ax_-Bx_,2)+pow(Ay_-By_,2)-pow(Cx_-Bx_,2)-pow(Cy_-By_,2))<0.1) && (abs(pow(Ax_-Bx_,2)+pow(Ay_-By_,2)-pow(Ax_-Cx_,2)-pow(Ay_-Cy_,2))<0.1)) ){
            cout<<"You entered invalid values triangle edges must not lie on one line and all three sides of the triangle must be equal"<<endl;
            cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
            cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
            flag=0;
        }
        Ax=Ax_;
        Ay=Ay_;
        Bx=Bx_;
        By=By_;
        Cx=Cx_;
        Cy=Cy_;        
    }while(flag==0);
}

double EquTriangle::calcS(){
    double a=pow(pow(Ax-Bx,2)+pow(Ay-By,2),0.5);
    return round(a*a*pow(3,0.5)/4*100)/100;
}

RTriangle::RTriangle(float Ax_, float Ay_, float Bx_, float By_, float Cx_, float Cy_){
    int flag;
    do{
        flag=1;
        if (((Cx_==Ax_ && Cx_==Bx_) || (Cy_==Ay_ && Cy_==By_) || (((Cx_ - Ax_) *1.0)/ (Bx_ - Ax_) == ((Cy_ - Ay_) *1.0)/ (By_ - Ay_)))
        || !((abs((Ax_-Cx_)*(Bx_-Cx_)+(Ay_-Cy_)*(By_-Cy_))<0.1) || (abs((Ax_-Bx_)*(Cx_-Bx_)+(Ay_-By_)*(Cy_-By_))<0.1) || (abs((Bx_-Ax_)*(Cx_-Ax_)+(By_-Ay_)*(Cy_-Ay_)<0.1))) ){
            cout<<"You entered invalid values triangle edges must not lie on one line and it must be a right-angled triangle"<<endl;
            cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
            cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
            flag=0;
        }
        Ax=Ax_;
        Ay=Ay_;
        Bx=Bx_;
        By=By_;
        Cx=Cx_;
        Cy=Cy_;        
    }while(flag==0);
}

double RTriangle::calcS(){
    double a=pow(pow(Ax-Bx,2)+pow(Ay-By,2),0.5);
    double b=pow(pow(Cx-Bx,2)+pow(Cy-By,2),0.5);
    double c=pow(pow(Ax-Cx,2)+pow(Ay-Cy,2),0.5);
    if (a>b && a>c){
        return round(b*c/2*100)/100;
    }else if(b>a && b>c){  
        return round(a*c/2*100)/100;
    }else{
        return round(a*b/2*100)/100;
    }
    
}
