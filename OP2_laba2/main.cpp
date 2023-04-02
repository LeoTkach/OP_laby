#include "myfunctions.h"

int main(){
    char ans;
    do{
        binaryFileProcessing();
        cout << "Do you want to restart the programm ? (If yes - press y or any other letter to exit the programm)" ;
        cin.ignore();
        cin >> ans;
    }while(ans=='y');
    return 0;
}