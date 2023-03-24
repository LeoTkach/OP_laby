#include "fPointer.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//виведення вмісту файлу
void printFile(const char* filename) {
    FILE* filePtr = fopen(filename, "r");
    printf("\n----------%s----------\n",filename);
    char c;
    while ((c = fgetc(filePtr)) != EOF) { 
        printf("%c",c);
    }
    fclose(filePtr);
    printf("\n");
}
//додавання нових записів й файл
void appendtoFile(const char* filename) {
    char delimiter = '/';
    char str[1000]; 
    char ans;
    printf("Do you want to append information to the file? (If yes - press y or any other letter if not): ");
    cin.ignore();
    scanf("%c", &ans);
    if (ans == 'y'){
        FILE* filePtr = fopen(filename, "a"); 
        printf("Enter string (for ending enter '%c'): \n", delimiter);
        cin.ignore();
        int i = 0;
        int ch;
        while (i < 1000 - 1 && (ch = getchar()) != EOF && ch != delimiter) {
            str[i++] = (char) ch;
        }
        str[i] = '\0'; 
        fprintf(filePtr, "%s", str);
        printf("Data successfully appended to the File '%s'\n", filename);
        fclose(filePtr);
        printFile(filename);
    }
}
//шифрування даних файлу
void rearrangeChars(const char* filename) {
    char outputfilename[]="output1.txt";
    FILE* filePtr = fopen(filename, "r");
    FILE* outputfilePtr = fopen(outputfilename, "w");
    char line[1000];
    while (fgets(line, 1000, filePtr)) {
        int len = strlen(line);
        char evenCh[1000/2];
        char oddCh[1000/2];
        int evenIn = 0;
        int oddIn = 0;
        for (int i = 0; i < len-1; i++) {
            if (i % 2 == 1) {
                evenCh[evenIn++] = line[i];
            } else {
                oddCh[oddIn++] = line[i];
            }
        }
        evenCh[evenIn] = '\0';
        oddCh[oddIn] = '\0';
        fprintf(outputfilePtr, "%s%s\n", evenCh, oddCh);
    }
    fclose(filePtr);
    fclose(outputfilePtr);
    remove(filename);
    rename(outputfilename, filename);
}
//копіювання строк парної довжини у новий файл
void copyOddLines(const char* filename) {
    char outputfilename[]="createdFile.txt";
    FILE* filePtr = fopen(filename, "r");
    FILE* outputfilePtr = fopen(outputfilename, "w");
    char line[1000];
    while (fgets(line, sizeof(line), filePtr)) {
        int len = 0;
        while (line[len] != '\0' && line[len] != '\n') {
            len++;
        }
        if (len % 2 == 0) {
            fputs(line, outputfilePtr);
        }
    }
    fclose(filePtr);
    fclose(outputfilePtr);
}
//видалення введеного символу з файлу
void removeCharFromFile(const char* filename) {
    char c;
    printf("Changing entered file and creatiing new file...\n");
    printf("Enter the character to remove in created file: ");
    cin.ignore();
    scanf("%c",&c);
    char outputfilename[]="output3.txt";
    FILE* filePtr = fopen(filename, "r");
    FILE* outputfilePtr = fopen(outputfilename, "w");  
    char ch;
    while ((ch = fgetc(filePtr)) != EOF) {
        if (ch != c) {
            fputc(ch, outputfilePtr);
        }
    }
    fclose(filePtr);
    fclose(outputfilePtr);
    remove(filename);
    rename(outputfilename, filename);
}
//створення нового файлу
void createFile(const char* filename){
    FILE* filePtr = fopen(filename, "w");
    fclose(filePtr);
    printf("File %s has been successfully created!\n",filename);
}
//обробка файлу згідно умов завдання
void fileProcessing() {
    char filename[50];
    printf("Enter name of the file without extension: ");
    scanf("%s",filename);
    char str2[10]=".txt";
    strcat(filename,str2);
    FILE* filePtr = fopen(filename, "r");
    if (filePtr == NULL) { 
        fclose(filePtr);
        createFile(filename);
        appendtoFile(filename);
        rearrangeChars(filename);
        char crfilename[]="createdFile.txt";
        copyOddLines(filename);
        removeCharFromFile(crfilename);
        printFile(filename);
        printFile(crfilename);
    } else { 
        printf("File %s already exists.\n",filename);
        fclose(filePtr);
        printFile(filename);
        appendtoFile(filename);
        rearrangeChars(filename);
        char crfilename[]="createdFile.txt";
        copyOddLines(filename);
        removeCharFromFile(crfilename);
        printFile(filename);
        printFile(crfilename);
    }
}
