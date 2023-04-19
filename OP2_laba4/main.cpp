#include "mylib.h"

int main() {
    Point p1;
    Point p2(4, 3); 
    Point p3(p2);

    cout<<"Creating 3 points with different constructors."<<endl;
    cout<<"Coordinates of p1 are: x="<<p1.get_x()<<" ,y="<<p1.get_y()<<endl;
    cout<<"Coordinates of p2 are: x="<<p2.get_x()<<" ,y="<<p2.get_y()<<endl;
    cout<<"Coordinates of p3 are: x="<<p3.get_x()<<" ,y="<<p3.get_y()<<endl<<endl;

    cout<<"Increasing values of x-coordinate of p1 and y-coordinate of p2 by 1"<<endl;
    ++p1;
    p2++;
    cout<<"Coordinates of p1 are: x="<<p1.get_x()<<" ,y="<<p1.get_y()<<endl;
    cout<<"Coordinates of p2 are: x="<<p2.get_x()<<" ,y="<<p2.get_y()<<endl<<endl;

    cout<<"Calculating distance between p1 and p2"<<endl;
    cout<<"Distance between p1 and p2 is "<<p1-p2<<endl<<endl;

    cout<<"Definition of the quadrant to which the p3 belongs"<<endl;
    p3.quadrantIdentification();

    return 0;
}
