#pragma once
#include <iostream>
using namespace std;
class Train{
    int num;
    string name;
    int h;
    int m;
public:
    // метод для отримання значення номера потяга
    int get_num();
    // метод для валідації строки часу відправлення потяга, яку я передаю в конструктор з параметрами
    bool TimeValidation(string h_m);
    // порожній конструктор для початкової ініціалізації масиву об'єктів класа Train 
    Train();
    // конструктор за параметрами для ініціалізації об'єктів масиву конкретними значеннями
    Train(int num1,string name1,string h_m);
    // метод для перевірки, чи відправляється потяг у вказаний інтервал
    bool DepartureValidation(int h1, int h2);
};
// функція, яка виконує умови завдання і виводить номери потягів, які відправляться у заданий інтервал часу
void TrainsDeparting(int q,Train trains[]);



