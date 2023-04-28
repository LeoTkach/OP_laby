#include "mylib.h"
int main(){
    
    cout<<"Enter the total number of triangles of all types: ";
    int n;
    cin>>n;
    TTriangle T3[n];
    int i;
    float Perim=0;
    float Square=0;
    cout<<"Isosceles triangles: "<<endl;
    for(i=0;i<n/3+(n-(n/3)*3)/2+(n-(n/3)*3)%2;i++){
        float Ax_, Ay_, Bx_, By_, Cx_, Cy_;
        cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
        cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
        T3[i]=IsoTriangle (Ax_, Ay_, Bx_, By_, Cx_, Cy_);
        Perim+=T3[i].calcP();
    }
    cout<<"Equilateral triangles: "<<endl;
    for(i=i;i<(n/3)*2+((n-(n/3)*3)/2)*2+(n-(n/3)*3)%2;i++){
        float Ax_, Ay_, Bx_, By_, Cx_, Cy_;
        cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
        cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
        T3[i]=EquTriangle (Ax_, Ay_, Bx_, By_, Cx_, Cy_);
        Square+=T3[i].calcS();
    }
    cout<<"Right triangles: "<<endl;
    for(i=i;i<n;i++){
        float Ax_, Ay_, Bx_, By_, Cx_, Cy_;
        cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
        cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
        T3[i]=RTriangle (Ax_, Ay_, Bx_, By_, Cx_, Cy_);
        Square+=T3[i].calcS();
    }
    cout<<"The total perimeter of all isosceles triangles: "<<Perim<<endl;
    cout<<"The total area of all equilateral and right triangles: "<<Square<<endl;
    // IsoTriangle T4 (1,2,3,4,5,6);
    // cout<<"Perimeter of triangle T2 equails: "<<T3[0].calcP()<<endl;
    // cout<<"Square of triangle T2 equails: "<<T3[0].calcS()<<endl;
    
}   