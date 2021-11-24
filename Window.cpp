#include "Window.h"

Window::Window(){
    windowNum = 0;
    myStudent = new Student(0);
    inUseTime = 0;
    idleTime = 0;
    windowOpen = true;
    numTimesOpened = 1;
}

Window::Window(int n){
    windowNum = n + 1;
    myStudent = new Student(0);
    inUseTime = 0;
    idleTime = 0;
    windowOpen = true;
    numTimesOpened = 1;
}

Window::~Window(){

}

void Window::setStudent(Student *s){
    myStudent = s;
    inUseTime = myStudent->getTimeNeeded();
    if(inUseTime > 0){
        windowOpen = false;
    }
}

bool Window::isOpen(){
    if(windowOpen){
        return true;
    }
    else{
        return false;
    }
}


int Window::getInUseTime(){
    return inUseTime;
}

void Window::decrementInUseTime(){
    inUseTime --;
    if(inUseTime == 0){
        windowOpen = true;
        setWindOpenedTime(time);
        ++numTimesOpened;
    }
}

int Window::getIdleTime(){
    idleTime = abs(windOpenedTick - windClosedTick);
    return idleTime;
}

void Window::setWindOpenedTime(int clockTick){
    windOpenedTick = clockTick;
}

void Window::setWindClosedTime(int clockTick){
    windClosedTick = clockTick;
}

void Window::setTime(int clockTick){
    time = clockTick;
}

int Window::getNumTimesOpened(){
    return numTimesOpened;
}

void Window::printInfo(){
    cout << "Window Number #" << windowNum << ":" << endl;
    if(windowOpen){
        cout << "Open";
    }
    else{
        cout << "closed-> ";
        cout << "Student: " << myStudent << ", ";
        cout << "Idle: " << inUseTime << " min";
    }
    cout << endl;
}