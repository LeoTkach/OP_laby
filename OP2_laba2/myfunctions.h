#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Car{
    string name;
    Date manudate;
    Date recepdate; 
};

void createNewBinaryFile(string &filename);

void readCarsFromBinaryFile(string &filename);

Date getCurrentDate();

bool isDateValid(int day, int month, int year, int day1, int month1, int year1);

void addCarToBinaryFile(string &filename);

void carsReceivedInLastMonth(string &filename);

void carsReleasedMoreThanYear(string &filename);

void binaryFileProcessing();