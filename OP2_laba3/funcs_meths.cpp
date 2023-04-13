#include "funcs_meths.h"
#include <iostream>
using namespace std;
// метод для отримання значення номера потяга
int Train::get_num(){
    return num;
}
// метод для валідації строки часу відправлення потяга, яку я передаю в конструктор з параметрами
bool Train::TimeValidation(string h_m){
    if (h_m.length() != 5) {
        return false;
    }
    if (h_m[0] < '0' || h_m[0] > '2' || h_m[1] < '0' || h_m[1] > '9' || h_m[2] != '-' || h_m[3] < '0' || h_m[3] > '5' || h_m[4] < '0' || h_m[4] > '9') {
        return false;
    }
    int h_ = stoi(h_m.substr(0, 2));
    if (h_ < 0 || h_ > 23) {
        return false;
    }
    int m_ = stoi(h_m.substr(3, 2));
    if (m_ < 0 || m_ > 59) {
        return false;
    }

    return true;
}
// порожній конструктор для початкової ініціалізації масиву об'єктів класа Train 
Train::Train(){}
// конструктор за параметрами для ініціалізації об'єктів масиву конкретними значеннями
Train::Train(int num1,string name1,string h_m){
    do{
        if(TimeValidation(h_m)==false){
            cout<<"Wrong time, enter it again(HH-MM): ";
            cin>>h_m;
        }
        num=num1;
        name=name1;
        string h_str = h_m.substr(0, 2);
        h = stoi(h_str);
        string m_str = h_m.substr(3, 2);
        m = stoi(m_str);
        
    }while(TimeValidation(h_m)==false);
}
// метод для перевірки, чи відправляється потяг у вказаний інтервал
bool Train::DepartureValidation(int h1, int h2){
    if(h1*60<h*60+m && h*60+m<h2*60){
        return true;
    }else{
        return false;
    }
}
// функція, яка виконую умови завдання і виводить номери потягів, які відправляться у заданий інтервал часу
void TrainsDeparting(int q,Train trains[]){
    cout<<endl;
    int h1;
    do{
        cout<<"Enter the left boundary of the interval: ";
        cin>>h1;
        if(h1<0 || h1>24){
            cout<<"The left boundary of the interval must not be smaller than 0 and bigger than 24!"<<endl;
        }
    }while(h1<0 || h1>24);
    cout<<endl;
    int h2;
    do{
        cout<<"Enter the right boundary of the interval: ";
        cin>>h2;
        if(h2<=h1){
            cout<<"The right boundary of the interval must be greater than left!"<<endl;
        }else if( h2>24){
            cout<<"The right boundary of the interval must not bigger than 24!"<<endl;
        }
    }while(h2<=h1 || h2>24);
    
    int k=0;
    for(int i=0;i<q;i++){
        if(trains[i].DepartureValidation(h1,h2)==true){
            if(k==0){
                cout<<endl<<"Numbers of the trains that departure between "<<h1<<" and "<<h2<<":"<<endl;
            }
            cout<<trains[i].get_num()<<" ";
            k+=1;
        }
    }
    if(k==0){
        cout<<endl<<"There are no trains that departure between "<<h1<<" and "<<h2<<endl;
    }
    cout<<endl;
}


