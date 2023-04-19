#include "mylib.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// конструктор за замовченням
Point::Point() { 
    x = 0;
    y = 0;
    // cout<<"Default constructor!"<<endl;
}
// конструктор з параметрами
Point::Point(int x_, int y_){
    x = x_;
    y = y_;
    // cout <<"Parametric constructor!"<<endl;
}
// конструктор копіювання
Point::Point(const Point &p){
    x=p.x;
    y=p.y;
    // cout<<"Copy constructor!"<<endl;
}
// метод визначенння квадранта, якому належить точка
void Point::quadrantIdentification(){
    if(this->x>0 && this->y>0){
        cout<<"This point belongs to 1 quadrant."<<endl;
    }else if(this->x<0 && this->y>0){
        cout<<"This point belongs to 2 quadrant."<<endl;
    }else if(this->x<0 && this->y<0){
        cout<<"This point belongs to 3 quadrant."<<endl;
    }else if(this->x>0 && this->y<0){
        cout<<"This point belongs to 4 quadrant."<<endl;
    }else{
        cout<<"This point do not belong to any quadrant"<<endl;
    }
}
// геттер для отримання значення координти по осі x
int Point::get_x(){
    return x;
}
// геттер для отримання значення координти по осі y
int Point::get_y(){
    return y;
}
// перевантажений префіксний оператор інкрементації "++"
Point Point::operator++(){
    x +=1;
    return *this;
}
// перевантажений постфіксний оператор інкрементації "++"
Point Point::operator++(int i){
    y +=1;
    return *this;
}
// перевантажений оператор "-" для визначення відстані між точками
float Point::operator-(Point& p){
    return pow(pow(this->x-p.x,2)+pow(this->y-p.y,2),(0.5));
}