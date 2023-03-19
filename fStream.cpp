#include "fStream.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <fstream>
using namespace std;

void printFile1( string &filename){
    ifstream file(filename);
    cout << "\n----------" << filename << "----------" << endl;
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();
    cout << "\n";
}

void appendtoFile1(string& filename) {
    char delimiter = '/';
    string str;
    char ans;
    cout << "Do you want to append information to the file? (If yes - press y or any other letter if not): ";
    cin.ignore();
    cin >> ans;
    if (ans == 'y') {
        ofstream file(filename, ios::app);
        cout << "Enter string (for ending enter '" << delimiter << "') " << endl;
        cin.ignore();
        getline(cin, str, delimiter);
        file << str;
        cout << "Data successfully uploaded to the File '" << filename << "'" << endl;
        file.close();
        printFile1(filename);
    }
}

void rearrangeChars1( string& filename) {
    string outputfilename = "output1.txt";
    ifstream infile(filename);
    ofstream outfile(outputfilename);

    string line;
    while (getline(infile, line)) {
        int len = line.length();
        if (len > 0 && line[len-1] == '\n') {
            line.erase(len-1);
        }

        string evenCh;
        string oddCh;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 1) {
                evenCh += line[i];
            } else {
                oddCh += line[i];
            }
        }
        outfile << evenCh << oddCh << endl;
    }
    infile.close();
    outfile.close();
    remove(filename.c_str());
    rename(outputfilename.c_str(), filename.c_str());
}

void copyOddLines1( string& filename) {
    string outputfilename = "createdFile.txt";
    ifstream infile(filename);
    ofstream outfile(outputfilename);

    string line;
    while (getline(infile, line)) {
        if (line.length() % 2 != 1) {
            outfile << line << endl;
        }
    }
    infile.close();
    outfile.close();
}

void removeCharFromFile1( string& filename) {
    char c;
    cout << "Changing entered file and creating new file..." << endl;
    cout << "Enter the character to remove in created file: ";
    cin >> c;
    string outputfilename = "output3.txt";
    ifstream infile(filename);
    ofstream outfile(outputfilename);
    char ch;
    while (infile.get(ch)) {
        if (ch != c) {
            outfile.put(ch);
        }
    }
    infile.close();
    outfile.close();
    remove(filename.c_str());
    rename(outputfilename.c_str(), filename.c_str());
}

void createFile1( string& filename) {
    ofstream file(filename);
    file.close();
    cout << "File " << filename << " has been successfully created!" << endl;
}

void fileProcessing1() {
    string filename;
    cout << "Enter name of the file without extension: ";
    cin >> filename;
    filename += ".txt";
    ifstream file(filename);
    if (!file) { 
        file.close();
        createFile1(filename);
        appendtoFile1(filename);
        rearrangeChars1(filename);
        string crfilename = "createdFile.txt";
        copyOddLines1(filename);
        removeCharFromFile1(crfilename);
        printFile1(filename);
        printFile1(crfilename);
    } else { 
        cout << "File " << filename << " already exists. " << endl;
        file.close();
        printFile1(filename);
        appendtoFile1(filename);
        rearrangeChars1(filename);
        string crfilename = "createdFile.txt";
        copyOddLines1(filename);
        removeCharFromFile1(crfilename);
        printFile1(filename);
        printFile1(crfilename);
    }
}

