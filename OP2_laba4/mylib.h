#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point {
    int x, y;
public:
    // конструктор за замовченням
    Point();
    // конструктор з параметрами
    Point(int x_, int y_);
    // конструктор копіювання
    Point(const Point &p);
    // метод визначенння квадранта, якому належить точка
    void quadrantIdentification();
    // геттер для отримання значення координти по осі x
    int get_x();
    // геттер для отримання значення координти по осі y
    int get_y();
    // перевантажений префіксний оператор інкрементації "++"
    Point operator++();
    // перевантажений постфіксний оператор інкрементації "++"
    Point operator++(int i);
    // перевантажений оператор "-" для визначення відстані між точками
    float operator-(Point& p);
};