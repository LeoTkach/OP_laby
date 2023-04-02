#include "myfunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

void createNewBinaryFile(string &filename) {
    ofstream file(filename,ios::binary);
    file.close();
    cout << "File " << filename << " has been successfully created!" << endl;
}

void readCarsFromBinaryFile(string &filename) {
    ifstream file(filename, ios::binary);
    Car car;
    cout << setw(20) << left << "Car name" << setw(17) << right << "Manufacture date" << setw(19) << right << "Reception date" << endl;
    int namelength=car.name.size();
    while (file.read(reinterpret_cast<char*>(&namelength), sizeof(int))) {
        string name(namelength, '\0');
        file.read(&name[0], namelength);
        car.name = name;
        file.read(reinterpret_cast<char*>(&car.manudate), sizeof(Date));
        file.read(reinterpret_cast<char*>(&car.recepdate), sizeof(Date));

        cout << setw(24) << left << car.name 
        << setw(2) << right << car.manudate.day << "." << setw(2) << right << car.manudate.month << "." << setw(4) << right << car.manudate.year
        << setw(14) << right << car.recepdate.day << "." << setw(2) << right << car.recepdate.month << "." << setw(4) << right << car.recepdate.year << endl;
        namelength=car.name.size();
    }
    file.close();
}

Date getCurrentDate() {
    time_t now = time(0);
    tm* currentTime = localtime(&now);

    Date currentDate;
    currentDate.day = (*currentTime).tm_mday;
    currentDate.month = (*currentTime).tm_mon + 1;
    currentDate.year = (*currentTime).tm_year + 1900;
    return currentDate;
}

bool isDateValid(int day, int month, int year, int day1=0, int month1=0, int year1=0) {
    if (month < 1 || month > 12) {
        cout<<"Wrong date!"<<endl;
        return false;
    }
    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    }
    if (day < 1 || day > maxDay) {
        cout<<"Wrong date!"<<endl;
        return false;
    }
    Date currentDate=getCurrentDate();
    if (currentDate.year<year){
        cout<<"Wrong date!"<<endl;
        return false;
    }else if(currentDate.year==year){
        if (currentDate.month<month){
            cout<<"Wrong date!"<<endl;
            return false;
        }else if(currentDate.month==month){
            if(currentDate.day<day){
                cout<<"Wrong date!"<<endl;
                return false;
            }
        }
    }
    if (year<year1){
        cout<<"Wrong date!"<<endl;
        return false;
    }else if(year==year1){
        if (month<month1){
            cout<<"Wrong date!"<<endl;
            return false;
        }else if(month==month1){
            if(day<day1){
                cout<<"Wrong date!"<<endl;
                return false;
            }
        }
    }
    return true;
}

void addCarToBinaryFile(string &filename) {
    char ans;
    do{
        cout << "\nDo you want to add a car to the file? (If yes - press y or any other letter if not): ";
        cin >> ans;
        if (ans == 'y') {
            ofstream file(filename, ios::binary | ios::app);
            Car car;
            
            cout << "Enter the name of the car: ";
            cin >> car.name;
            do{
                cout << "Enter the date of manufacture (day month year): ";
                cin >> car.manudate.day >> car.manudate.month >> car.manudate.year;
            }while(isDateValid(car.manudate.day, car.manudate.month, car.manudate.year)==false);
            do{
                cout << "Enter the date of reception (day month year): ";
                cin >> car.recepdate.day >> car.recepdate.month >> car.recepdate.year;
            }while(isDateValid(car.recepdate.day, car.recepdate.month, car.recepdate.year, car.manudate.day, car.manudate.month, car.manudate.year)==false);
            // записываем машину в файл
            // сначала записываем длину имени машины
            int namelength = car.name.size();
            file.write(reinterpret_cast<const char*>(&namelength), sizeof(int));
            // затем записываем само имя
            file.write(car.name.c_str(), namelength);
            // затем записываем даты
            file.write(reinterpret_cast<const char*>(&car.manudate), sizeof(Date));
            file.write(reinterpret_cast<const char*>(&car.recepdate), sizeof(Date));

            cout << "\nCar successfully added to the file " << filename << endl;
            file.close();
            readCarsFromBinaryFile(filename);
        }  
    }while(ans=='y');
}

void carsReceivedInLastMonth(string &filename) {
    Date currentDate = getCurrentDate();
    ifstream file(filename, ios::binary);
    // read cars from file and output those sold in the given month
    Car car;
    cout <<"\nList of cars received for sale in last month:"<<endl;
    cout << setw(20) << left << "Car name" << setw(17) << right << "Manufacture date" << setw(19) << right << "Reception date" << endl;
    int namelength=car.name.size();
    while (file.read(reinterpret_cast<char*>(&namelength), sizeof(int))) {
        string name(namelength, '\0');
        file.read(&name[0], namelength);
        car.name = name;
        file.read(reinterpret_cast<char*>(&car.manudate), sizeof(Date));
        file.read(reinterpret_cast<char*>(&car.recepdate), sizeof(Date));
        // check if car was sold in the given month and output its info
        if ((car.recepdate.month == currentDate.month)&&(car.recepdate.year == currentDate.year)) {
            cout << setw(24) << left << car.name 
            << setw(2) << right << car.manudate.day << "." << setw(2) << right << car.manudate.month << "." << setw(4) << right << car.manudate.year
            << setw(14) << right << car.recepdate.day << "." << setw(2) << right << car.recepdate.month << "." << setw(4) << right << car.recepdate.year << endl;
        }
        namelength=car.name.size();
    }
    file.close();
}

void carsReleasedMoreThanYear(string &filename) {
    ifstream file(filename, ios::binary);
    // read cars from file and output those sold in the given month
    Car car;
    cout <<"\nList of the cars released more than a year before coming to sale:"<<endl;
    cout << setw(20) << left << "Car name" << setw(17) << right << "Manufacture date" << setw(19) << right << "Reception date" << endl;
    int namelength=car.name.size();
    while (file.read(reinterpret_cast<char*>(&namelength), sizeof(int))) {
        string name(namelength, '\0');
        file.read(&name[0], namelength);
        car.name = name;
        file.read(reinterpret_cast<char*>(&car.manudate), sizeof(Date));
        file.read(reinterpret_cast<char*>(&car.recepdate), sizeof(Date));
        // check if car was sold in the given month and output its info
        if (car.recepdate.year - car.manudate.year > 1) {
            cout << setw(24) << left << car.name 
            << setw(2) << right << car.manudate.day << "." << setw(2) << right << car.manudate.month << "." << setw(4) << right << car.manudate.year
            << setw(14) << right << car.recepdate.day << "." << setw(2) << right << car.recepdate.month << "." << setw(4) << right << car.recepdate.year << endl;
        }
        namelength=car.name.size();
    }
    file.close();
}

//обробка файлу згідно умов завдання
void binaryFileProcessing() {
    string filename;
    cout << "Enter name of the file without extension: ";
    cin >> filename;
    filename += ".bin";
    ifstream file(filename,ios::binary);
    if (!file) { 
        file.close();
        createNewBinaryFile(filename);
        addCarToBinaryFile(filename);
        carsReceivedInLastMonth(filename);
        carsReleasedMoreThanYear(filename);
    } else { 
        cout << "\nFile " << filename << " already exists. " << endl;
        cout << "\nHere is list of cars this binary file contains: " << endl;
        file.close();
        readCarsFromBinaryFile(filename);
        addCarToBinaryFile(filename);
        carsReceivedInLastMonth(filename);
        carsReleasedMoreThanYear(filename);
    }
}