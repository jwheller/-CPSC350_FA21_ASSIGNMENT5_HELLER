//Registrar window class:
#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"
#include <string>

using namespace std;

class Window{
    public:
    Window();
    Window(int n);
    ~Window();
    void setStudent(Student *s);
    int getInUseTime();
    int getIdleTime();
    void setWindOpenedTime(int clockTick);
    void setWindClosedTime(int clockTick);
    void decrementInUseTime();
    bool isOpen();
    void setTime(int clockTick);
    int getNumTimesOpened();
    void printInfo();

    Student* myStudent;

    private:
    int numTimesOpened;
    bool windowOpen;
    int windowNum;
    int inUseTime;
    int idleTime;
    int windOpenedTick;
    int windClosedTick;
    int time;
};

#endif