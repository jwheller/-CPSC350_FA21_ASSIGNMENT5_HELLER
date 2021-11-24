// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 4

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileProcessor{

    public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string f, string o);
    string getLinesFromFile(string readFileName);
    void makeArrayFromFile(string readFileName);
    void getLengthOfFile(string readFileName);
    void writeToFile(string writeFileName, string input1, string input2);
    bool isTxtFile(string name);
    string *linesArray;
    string untranslatedLine;
    string outputFile;
    string translatedText;
    int lineCounter;

    private:
    string fileOpenErr;
    fstream readFile;
    fstream writeFile;
    string fileAsString;
    string fullLineOfFile;
    int numLines;
    
};
#endif