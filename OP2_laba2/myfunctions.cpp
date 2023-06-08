#include "myfunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

// створення нового бінарного файлу
void createNewBinaryFile(string &filename) {
    ofstream file(filename,ios::binary);
    file.close();
    cout << "File " << filename << " has been successfully created!" << endl;
}

// зчитуваня та виведення списку машин та їх харакетристик, які наявні у файлі
void readAllCarsFromBinaryFile(string &filename) {
    ifstream file(filename, ios::binary);
    Car car;
    cout << setw(20) << left << "Car name" << setw(17) << right << "Manufacture date" << setw(19) << right << "Reception date" << endl;
    int namelength;
    while (file.read((char*)(&namelength), sizeof(int))) {
        string name(namelength, '\0');
        file.read((char*)name.c_str(), namelength);
        car.name = name;
        
        file.read((char*)(&car.manudate), sizeof(Date));
        file.read((char*)(&car.recepdate), sizeof(Date));

        cout << setw(24) << left << car.name 
        << setw(2) << right << car.manudate.day << "." << setw(2) << right << car.manudate.month << "." << setw(4) << right << car.manudate.year
        << setw(14) << right << car.recepdate.day << "." << setw(2) << right << car.recepdate.month << "." << setw(4) << right << car.recepdate.year << endl;
    }
    file.close();
}

// отримання сьогоднішньої дати
Date getCurrentDate() {
    time_t now = time(0);
    tm* currentTime = localtime(&now);

    Date currentDate;
    currentDate.day = (*currentTime).tm_mday;
    currentDate.month = (*currentTime).tm_mon + 1;
    currentDate.year = (*currentTime).tm_year + 1900;
    return currentDate;
}

// перевірка введеної дати на валідність
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

// додавання у бінарний файл записів про нову машину
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
            // записуємо машину у файл
            // записуємо доавжину імені
            int namelength = car.name.size();
            file.seekp(0, std::ios::beg);
            file.seekp(0, std::ios::beg);
            cout << file.tellp() << endl;
            // file.seekp(0,ios::end);
            file.write((char*)(&namelength), sizeof(int));
            // записуємо ім'я
            file.write(car.name.c_str(), namelength);
            // записуємо дату створення та отримання для продажу
            file.write(reinterpret_cast<const char*>(&car.manudate), sizeof(Date));
            file.write(reinterpret_cast<const char*>(&car.recepdate), sizeof(Date));
            cout << file.tellp() << endl;
            string asd="ASDF";
            do{
                cout << "Enter the date of manufacture (day month year): ";
                cin >> car.manudate.day >> car.manudate.month >> car.manudate.year;
            }while(isDateValid(car.manudate.day, car.manudate.month, car.manudate.year)==false);
            do{
                cout << "Enter the date of reception (day month year): ";
                cin >> car.recepdate.day >> car.recepdate.month >> car.recepdate.year;
            }while(isDateValid(car.recepdate.day, car.recepdate.month, car.recepdate.year, car.manudate.day, car.manudate.month, car.manudate.year)==false);
            // записуємо машину у файл
            // записуємо доавжину імені
            namelength = asd.size();
            file.seekp(0, std::ios::beg);
            file.seekp(-31, std::ios::cur);
            cout << file.tellp() << endl;
            // file.seekp(0,ios::end);
            file.write(reinterpret_cast<const char*>(&namelength), sizeof(int));
            // записуємо ім'я
            file.write(asd.c_str(), namelength);
            // записуємо дату створення та отримання для продажу
            file.write(reinterpret_cast<const char*>(&car.manudate), sizeof(Date));
            file.write(reinterpret_cast<const char*>(&car.recepdate), sizeof(Date));
            cout << file.tellp() << endl;
            cout << "\nCar successfully added to the file " << filename << endl;
            file.close();
            readAllCarsFromBinaryFile(filename);
        }  
    }while(ans=='y');
}

// виведення списку машин, які було отримано для продажу у останній місяць 
void readCarsReceivedInLastMonth(string &filename) {
    Date currentDate = getCurrentDate();
    ifstream file(filename, ios::binary);
    Car car;
    cout <<"\nList of cars received for sale in last month:"<<endl;
    cout << setw(20) << left << "Car name" << setw(17) << right << "Manufacture date" << setw(19) << right << "Reception date" << endl;
    int namelength;
    while (file.read((char*)(&namelength), sizeof(int))) {
        // зчитування імені машини
        string name(namelength, '\0');
        file.read((char*)name.c_str(), namelength);
        car.name = name;
        // зчитування дат
        file.read((char*)(&car.manudate), sizeof(Date));
        file.read((char*)(&car.recepdate), sizeof(Date));
        // у разі виконання вимог виведення на екран
        if ((car.recepdate.month == currentDate.month)&&(car.recepdate.year == currentDate.year)) {
            cout << setw(24) << left << car.name 
            << setw(2) << right << car.manudate.day << "." << setw(2) << right << car.manudate.month << "." << setw(4) << right << car.manudate.year
            << setw(14) << right << car.recepdate.day << "." << setw(2) << right << car.recepdate.month << "." << setw(4) << right << car.recepdate.year << endl;
        }
    }
    file.close();
}

// виведення списку машин, які були випущені більш ніж за рік до надходження у продаж 
void readCarsReleasedMoreThanYear(string &filename) {
    ifstream file(filename, ios::binary);
    Car car;
    cout <<"\nList of the cars released more than a year before coming to sale:"<<endl;
    cout << setw(20) << left << "Car name" << setw(17) << right << "Manufacture date" << setw(19) << right << "Reception date" << endl;
    int namelength;
    while (file.read((char*)(&namelength), sizeof(int))) {
        // зчитування імені машини
        string name(namelength, '\0');
        file.read((char*)name.c_str(), namelength);
        car.name = name;
        // зчитування дат
        file.read((char*)(&car.manudate), sizeof(Date));
        file.read((char*)(&car.recepdate), sizeof(Date));
        // у разі виконання вимог виведення на екран
        if (car.recepdate.year - car.manudate.year > 1) {
            cout << setw(24) << left << car.name 
            << setw(2) << right << car.manudate.day << "." << setw(2) << right << car.manudate.month << "." << setw(4) << right << car.manudate.year
            << setw(14) << right << car.recepdate.day << "." << setw(2) << right << car.recepdate.month << "." << setw(4) << right << car.recepdate.year << endl;
        }
    }
    file.close();
}

// обробка файлу згідно умов завдання
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
        readCarsReceivedInLastMonth(filename);
        readCarsReleasedMoreThanYear(filename);
    } else { 
        cout << "\nFile " << filename << " already exists. " << endl;
        cout << "\nHere is list of cars this binary file contains: " << endl;
        file.close();
        readAllCarsFromBinaryFile(filename);
        addCarToBinaryFile(filename);
        readCarsReceivedInLastMonth(filename);
        readCarsReleasedMoreThanYear(filename);
    }
}