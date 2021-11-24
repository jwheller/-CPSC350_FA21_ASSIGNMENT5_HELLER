// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5


#include "GenQueue.h"
#include "Window.h"
#include "Student.h"
#include "Simulation.h"

using namespace std;

class SimStatistics{
    public:
    SimStatistics();
    SimStatistics(Simulation *sim);
    ~SimStatistics();

    private:
    GenQueue<Student*> *waitQueue;
    GenQueue<int> *idleQueue;

    float calcMeanWaitTime();
    float calcMeanIdleTime();
    int calcWaitingOverTen();
    int calcIdleOverFive();

    float numStudents;
    int meanWaitTime;
    int medWaitTime;
    int maxWaitTime;
    int numTenPlusWait;
    int waitTimes;
    int tenPlusWaits;

    float meanIdleTime;
    int maxIdleTime;
    int numFivePlusIdle;
    int idleTimes;
    float numTimesWinsOpened;
};

//#include "SimStatistics.h"

SimStatistics::SimStatistics(){
    numStudents = 0;

}

SimStatistics::SimStatistics(Simulation *sim){
    waitQueue = sim->helpedStudentQueue;
    idleQueue = sim->idleTimesQueue;

    numTimesWinsOpened = sim->getSumTimeOpn();

    numStudents = waitQueue->getSize(); //Size of waitQueue is always the same as waitQueue after the simulation
    //Outputs: 
    //cout << "Number of students waiting for 10+ minutes: ";
    //cout << calcWaitingOverTen() << endl;
    cout << "Mean Wait Time: ";
    cout << calcMeanWaitTime() << endl;
    cout << endl;
    cout << "Number of windows idling for 5+ minutes: " << endl;
    cout << "Mean Idle Time: ";
    cout << calcMeanIdleTime() << endl;


}

SimStatistics::~SimStatistics(){
    delete waitQueue, idleQueue;
}


// int SimStatistics::calcIdleOverFive(){

// }

int SimStatistics::calcWaitingOverTen(){ //Will have to do search then iterate for any key >= 10
    if ((waitQueue->returnEach())->getTimeWaiting() >= 10){
        tenPlusWaits ++;
    }
    return tenPlusWaits;
}


float SimStatistics::calcMeanWaitTime(){

    while(!waitQueue->isEmpty()){
        Student *waitingStudent = waitQueue->dequeue();
        meanWaitTime += waitingStudent->getTimeWaiting();
    }
    meanWaitTime = meanWaitTime/numStudents;
    return meanWaitTime; 
}

float SimStatistics::calcMeanIdleTime(){
    while(!idleQueue->isEmpty()){
        int idleT = idleQueue->dequeue();
        meanIdleTime += idleT;
    }
    meanIdleTime = meanIdleTime/numTimesWinsOpened;
    return meanIdleTime;
}


