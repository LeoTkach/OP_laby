#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

// структура для збереження дат
struct Date{
    int day;
    int month;
    int year;
};

// структура для збереження характеристик машин
struct Car{
    string name;
    Date manudate;
    Date recepdate; 
};

// створення нового бінарного файлу
void createNewBinaryFile(string &filename);

// зчитуваня та виведення списку машин та їх харакетристик, які наявні у файлі
void readAllCarsFromBinaryFile(string &filename);

// отримання сьогоднішньої дати
Date getCurrentDate();

// перевірка введеної дати на валідність
bool isDateValid(int day, int month, int year, int day1, int month1, int year1);

// додавання у бінарний файл записів про нову машину
void addCarToBinaryFile(string &filename);

// виведення списку машин, які було отримано для продажу у останній місяць 
void readCarsReceivedInLastMonth(string &filename);

// виведення списку машин, які були випущені більш ніж за рік до надходження у продаж 
void readCarsReleasedMoreThanYear(string &filename);

// обробка файлу згідно умов завдання
void binaryFileProcessing();