#include "funcs_meths.h"

int main(){
    cout<<"Enter the quantity of trains: ";
    int q;
    cin>>q;
    Train trains[q];
    for (int i=0;i<q;i++){
        cout<<endl;
        cout<<"Enter the number of the "<<i+1<<" train: ";
        int num;
        cin>>num;
        cout<<"Enter the name of the destination place: ";
        string name;
        cin>>name;
        cout<<"Enter the time of the departure(HH-MM): ";
        string h_m;
        cin>>h_m;
        
        trains[i]=Train(num,name,h_m);
    }
    TrainsDeparting(q, trains);
    return 0;
}

