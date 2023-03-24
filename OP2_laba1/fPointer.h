#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//виведення вмісту файлу
void printFile(const char* filename);
//додавання нових записів й файл
void appendtoFile(const char* filename);
//шифрування даних файлу
void rearrangeChars(const char* filename);
//копіювання строк парної довжини у новий файл
void copyOddLines(const char* filename);
//видалення введеного символу з файлу
void removeCharFromFile(const char* filename);
//створення нового файлу
void createFile(const char* filename);
//обробка файлу згідно умов завдання
void fileProcessing();
