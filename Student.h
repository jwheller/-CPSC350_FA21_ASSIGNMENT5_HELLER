// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;
//student class:
class Student{
    public:
    Student();
    Student(int time);
    ~Student();
    int getTimeNeeded();
    int getTimeWaiting();
    void setTimeWaiting(int w);
    void incrementTimeWaiting();
    void setClockTickHelped(int tick);
    void setClockTickArrived(int tick);
    int getClockTickArrived();

    friend ostream& operator<<(ostream& os, const Student * st); //Learned this line 
    //(and its implementation on line 9 of Student.cpp) 
    //from: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170

    private:
    int clockTickArrived;
    int clockTickWhenHelped;
    int timeWaiting;
    int timeNeeded; 
};

#endif