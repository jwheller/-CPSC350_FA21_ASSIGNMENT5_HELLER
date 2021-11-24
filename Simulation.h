// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5

#ifndef SIMULATION_H
#define SIMULATION_H

#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include <string>

using namespace std;

//Simulation class
class Simulation{
    
    public:
    Simulation();
    Simulation(string *inputArray, int arrSize);
    ~Simulation();
    void createWindows(int w);
    GenQueue<Student*> *studentQueue;
    GenQueue<Student*> *helpedStudentQueue;
    GenQueue<int> *idleTimesQueue;

    int rawInfoLen;
    int *rawInfo;
    void CreateInfoArray(string *array); //Creates an array that stores
    //the raw numbers/info that the text file has
    void FillQueue(); //Makes the "line" of waiting students from the file info array
    void PrintQueue();
    void updateWindows();
    void checkIfDone();

    int getSumTimeOpn();
    int waitTimes;

    void updateWaitTimes();

    private:

    int time; //The clock that ticks throughout the program
    int numTotalStudents;
    Window **regWindows;
    int numWindows;
    Student *waitingStudent;
    Student *frontStudent;

    int rawInfoIndex;
    int arrivalTime;
    int newWaitingStudents;
    bool helpedAllStudents;
    bool allWindowsOpen;
    int sumTimesOpened;
};
#endif