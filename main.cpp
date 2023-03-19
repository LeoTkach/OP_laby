#include "fPointer.h"
#include "fStream.h"
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 3. || strcmp(argv[1], "-mode") ){
        cout << "Enter the command line mode: -mode FilePointer (FileStream)";
    }
    else if (!strcmp(argv[2], "FileStream")){
        cout << "FileStream mode activated\n";
        char ans;
        do{
            fileProcessing1();
            cout << "Do you want to restart the programm ? (If yes - press y or any other letter to exit the programm)" ;
            cin.ignore();
            cin >> ans;
        }while(ans=='y');
    }
    else if (!strcmp(argv[2], "FilePointer")){
        cout << "FilePointer mode activated\n";
        char ans;
        do{
            fileProcessing();
            cout << "Do you want to restart the programm ? (If yes - press y or any other letter to exit the programm)" ;
            cin.ignore();
            cin >> ans;
        }while(ans=='y');
    }
    else{
        cout << "Unknown mode" << endl << "Available modes: FilePointer, FileStream";
    }
    return 0;
}