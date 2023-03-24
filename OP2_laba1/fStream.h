#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

//виведення вмісту файлу
void printFile1(string &filename);
//додавання нових записів й файл
void appendtoFile1(string &filename);
//шифрування даних файлу
void rearrangeChars1(string &filename);
//копіювання строк парної довжини у новий файл
void copyOddLines1(string &filename);
//видалення введеного символу з файлу
void removeCharFromFile1(string &filename);
//створення нового файлу
void createFile1(string &filename);
//обробка файлу згідно умов завдання
void fileProcessing1();