#include "mylib.h"
int main(){
    
    cout<<"Enter the total number of triangles of all types: ";
    int n;
    cin>>n;
    TTriangle *Triangles[n];
    int i;
    float Perim=0;
    float Square=0;
    cout<<"Isosceles triangles: "<<endl;
    for(i=0;i<n/3+(n-(n/3)*3)/2+(n-(n/3)*3)%2;i++){
        float Ax_, Ay_, Bx_, By_, Cx_, Cy_;
        cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
        cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
        IsoTriangle Tr(Ax_, Ay_, Bx_, By_, Cx_, Cy_);
        Triangles[i]= &Tr;
        Perim+=Triangles[i]->calcP();
    }
    cout<<"Equilateral triangles: "<<endl;
    for(i=i;i<(n/3)*2+((n-(n/3)*3)/2)*2+(n-(n/3)*3)%2;i++){
        float Ax_, Ay_, Bx_, By_, Cx_, Cy_;
        cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
        cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
        EquTriangle Tr(Ax_, Ay_, Bx_, By_, Cx_, Cy_);
        Triangles[i]= &Tr;
        Square+=Triangles[i]->calcS();
    }
    cout<<"Right triangles: "<<endl;
    for(i=i;i<n;i++){
        float Ax_, Ay_, Bx_, By_, Cx_, Cy_;
        cout<<"Enter coordinates of the edges of the triangle(Ax, Ay, Bx, By, Cx, Cy): ";
        cin>>Ax_>>Ay_>>Bx_>>By_>>Cx_>>Cy_;
        RTriangle Tr(Ax_, Ay_, Bx_, By_, Cx_, Cy_);
        Triangles[i]= &Tr;
        Square+=Triangles[i]->calcS();
    }
    cout<<"The total perimeter of all isosceles triangles: "<<Perim<<endl;
    cout<<"The total area of all equilateral and right triangles: "<<Square<<endl;
    
}   