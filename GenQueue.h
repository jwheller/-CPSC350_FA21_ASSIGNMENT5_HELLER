#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
#include "DoubleLinkedList.h"
#include "ListInterface.h"

using namespace std;

template<class T>
class GenQueue{
    public:
    GenQueue();
    ~GenQueue();
    void enqueue(T data); 
    T dequeue();
    bool isEmpty();
    size_t getSize();
    T peek();
    void printQueue();
    T returnEach(); //Returns each individual node (in the specified type rather than
    // a cout)
    void sort();

    private:
    myList<T> *queueList;
    int front;
    int rear;
    size_t numElements;
};


template<class T>
GenQueue<T>::GenQueue(){
    queueList = new myList<T>();
}

template<class T>
GenQueue<T>::~GenQueue(){
    delete queueList;
}

template<class T>
void GenQueue<T>::enqueue(T data){
    queueList->Append(data);
}

template<class T>
T GenQueue<T>::dequeue(){
    if(queueList->IsEmpty()){
        throw runtime_error("queue is empty!");
    }
    else{
        T oldfront = queueList->ReturnFront();
        queueList->RemoveFront();
        return oldfront;
    }
}

template<class T>
T GenQueue<T>::peek(){
    if (queueList->IsEmpty()){
        throw runtime_error("queue is empty!");
    }
    else{
        return queueList->ReturnFront();
    }
}

template<class T>
bool GenQueue<T>::isEmpty(){
    if(queueList->IsEmpty()){
        return true;
    }
    else
        return false;
}

template<class T>
size_t GenQueue<T>::getSize(){
    return queueList->GetLength();
}

template<class T>
void GenQueue<T>::printQueue(){
    queueList->Print();
}

template<class T>
T GenQueue<T>::returnEach(){
    queueList->ReturnAll();
}

template<class T>
void GenQueue<T>::sort(){
    queueList->Sort();
}

#endif