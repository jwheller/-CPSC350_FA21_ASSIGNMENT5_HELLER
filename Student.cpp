// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5

#include "Student.h"

ostream& operator<<(ostream& os, const Student * st){
    os << st->timeNeeded;
    return os;
}

Student::Student(){
    timeNeeded = 0;
    timeWaiting = 0;
}

Student::Student(int time){
    timeNeeded = time;
    timeWaiting = 0;
}

Student::~Student(){

}

int Student::getTimeNeeded(){
    return timeNeeded;
}

int Student::getTimeWaiting(){
    timeWaiting = (clockTickWhenHelped - clockTickArrived) - 1;
    return timeWaiting;
}

void Student::incrementTimeWaiting(){
    timeWaiting++;
}

void Student::setClockTickArrived(int tick){
    clockTickArrived = tick;
}

int Student::getClockTickArrived(){
    return clockTickArrived;
}

void Student::setClockTickHelped(int time){
    clockTickWhenHelped = time;
}