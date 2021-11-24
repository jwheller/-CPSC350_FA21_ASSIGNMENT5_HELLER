#include "Simulation.h"
#include "SimStatistics.h"
#include "FileProcessor.h"

//Temporary I think:
#include "ListInterface.h"
//#include "DoubleLinkedList.h"


int main(int argc, char **argv){
    string openFile;
    FileProcessor *fp = new FileProcessor();
    while(!fp->isTxtFile(openFile)){ //Loop until a valid "txt" file is supplied
        cout << "Enter a text file you would like to read from: " << endl;
        cin >> openFile;
    }
    fp->makeArrayFromFile(openFile);
    Simulation *sim = new Simulation(fp->linesArray, fp->lineCounter); 
    SimStatistics *stats = new SimStatistics(sim);


    delete stats, fp, sim;
    return 0;
}