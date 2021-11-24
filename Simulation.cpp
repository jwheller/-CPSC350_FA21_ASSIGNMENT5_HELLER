// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5

#include "Simulation.h"

Simulation::Simulation(){

}
Simulation::Simulation(string *inputArray, int arrSize){
    rawInfoLen = arrSize;
    CreateInfoArray(inputArray);

    studentQueue = new GenQueue<Student*>();
    helpedStudentQueue = new GenQueue<Student*>();
    idleTimesQueue = new GenQueue<int>();

    time = 0; //Clock used throughout the simulation
    rawInfoIndex = 0; //Index that searches over the data array
    numWindows = rawInfo[rawInfoIndex]; //Number of available windows is the first number 
    //(index: 0)
    regWindows = new Window*[numWindows];
    for (int i = 0; i < numWindows; i++){
        regWindows[i] = new Window(i);
        ++sumTimesOpened;
    }
    createWindows(rawInfo[rawInfoIndex]); //Creates the amount of windows
    //specified by the first number
    rawInfoIndex++;
    int loopCount = 0;

    //This gets the initial "line" of students forming
    while(studentQueue->isEmpty() && loopCount < 10){ //Loopcount ensures that 
    //this part doesnt get stuck in a loop searching through the index
        cout << "TIME IS: " << time << endl;
        FillQueue();
        cout << "Queue is: " << endl;
        PrintQueue();
        time++;
        loopCount++;
        cout << endl;
        checkIfDone();
        helpedAllStudents = false;
    }

    //Once there's a line, repeate this loop until all the students in the 
    //line have been helped (the line will grow and shrink as more are added)
    while(!helpedAllStudents){
        cout << "TIME IS " << time << endl;
        updateWindows();
        FillQueue();
        cout << "Queue is: " << endl;
        PrintQueue();
        cout << endl;
        time++;
        cout << endl;
        checkIfDone();
    }
}

Simulation::~Simulation(){
    delete studentQueue, helpedStudentQueue, idleTimesQueue;
}

void Simulation::CreateInfoArray(string *array){ //Creates the array of the files's information
    rawInfo = new int[rawInfoLen];
    for (int i = 0; i < rawInfoLen; i++){
        int tempNum = stoi(array[i]); //Convert the string-values of the file into
        //ints that can be used by the simulation
        rawInfo[i] = tempNum;
    }
}

void Simulation::createWindows(int w){
    Window *regWindows[w];
    for (int i = 0; i < w; i++){
        regWindows[i] = new Window(i);
        regWindows[i]->setWindOpenedTime(0);
    }
}

void Simulation::FillQueue(){
    arrivalTime = rawInfo[rawInfoIndex];
    cout << "arrival time is: " << arrivalTime << endl;
    if (time == arrivalTime && rawInfoIndex < 8){
        rawInfoIndex++;
        newWaitingStudents = rawInfo[rawInfoIndex];
        rawInfoIndex++;
        for (int i = 0; i < newWaitingStudents; i++){
            waitingStudent = new Student(rawInfo[rawInfoIndex]);
            studentQueue->enqueue(waitingStudent);
            waitingStudent->setClockTickArrived(time);
            rawInfoIndex++;
        }
    }
}

void Simulation::PrintQueue(){
    studentQueue->printQueue();
}

void Simulation::updateWindows(){
    allWindowsOpen = true; //This variable is set to true just temporarily, and is
    //Over-written by the operation at then very bottom of this function*. This is
    //so it has a starting value of "1" and will be set to "0" (false) if ANY of
    //the windows are closed

    for(int w = 0; w < numWindows; w++){
        regWindows[w]->setTime(time); 
        if(regWindows[w]->isOpen() && !studentQueue->isEmpty()){
            frontStudent = studentQueue-> dequeue();
            frontStudent->setClockTickHelped(time);
            helpedStudentQueue->enqueue(frontStudent);
            regWindows[w]->setStudent(frontStudent);
            regWindows[w]->setWindClosedTime(time);
            idleTimesQueue->enqueue(regWindows[w]->getIdleTime());
            ++sumTimesOpened;
        }
        else{
            regWindows[w]->decrementInUseTime();   
        }
        allWindowsOpen *= regWindows[w]->isOpen(); //*Operation where allWindowsOpen
        //is over-written based on the status of all windows
        regWindows[w]->printInfo();
    }
}

void Simulation::checkIfDone(){
    if (rawInfoIndex >= rawInfoLen){
        if (allWindowsOpen){
            helpedAllStudents = true;
        }
        else{
            helpedAllStudents = false;
        }
    }
    else{
        helpedAllStudents = false;
    }
}

int Simulation::getSumTimeOpn(){
    return sumTimesOpened;
}
