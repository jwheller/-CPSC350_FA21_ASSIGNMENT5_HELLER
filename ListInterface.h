// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5

//Abstract Interface list class
#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include "DoubleLinkedList.h"


template <class T>
class ListInterface{

    public:
    virtual void Append(T data) = 0;
    virtual void Prepend(T data) = 0;
    virtual void InsertAfter(T existingData,T insertData) = 0;
    virtual void Search(T data) = 0; //change to T eventually
    virtual void Print() = 0;
    virtual void PrintReverse() = 0;
    virtual void Sort() = 0;
    virtual bool IsEmpty() = 0;
    virtual int GetLength() = 0;
};


//implementation of ListInterface:
template <class T>
class myList : ListInterface<T>{

    //Ask if we need to impliment all, even ones not used in this assignment,
    //otherwise delete the functions you dont end up using

    public:
    myList();
    ~myList();
    DoubleLinkedList<T> *doubleList;
    void Append(T data);
    void Prepend(T data);
    void InsertAfter(T existingData,T insertData);
    void RemoveFront();
    void RemoveBack();
    void Search(T data); //change back to type T eventually
    void Print();
    T ReturnAll();
    T ReturnFront();
    T ReturnBack();
    void PrintReverse();
    void Sort();
    bool IsEmpty();
    int GetLength();
};

template<class T>
myList<T>::myList(){
    doubleList = new DoubleLinkedList<T>();
}

template<class T>
myList<T>::~myList(){
    delete doubleList;
}

template<class T>
void myList<T>::Append(T data){
    doubleList->insertBack(data);
}

template<class T>
void myList<T>::Prepend(T data){
    doubleList->insertFront(data);
}

template<class T>
void myList<T>::RemoveFront(){
    doubleList->removeFront();
}

template<class T>
void myList<T>::RemoveBack(){
    doubleList->removeBack();
}

template<class T>
T myList<T>::ReturnFront(){
    return doubleList->returnFront();
}

template<class T>
T myList<T>::ReturnBack(){
    return doubleList->returnBack();
}

template<class T>
bool myList<T>::IsEmpty(){
    return doubleList->isEmpty();
}

template<class T>
int myList<T>::GetLength(){
    return doubleList->getSize();
}

template<class T>
void myList<T>::Print(){
    doubleList->print();
}

template<class T>
T myList<T>::ReturnAll(){
    doubleList->returnEachNode();
}

template<class T>
void myList<T>::InsertAfter(T existingData, T insertData){
    cout << "Temporary" << endl;
}

template<class T>
void myList<T>::Search(T data){
    cout << "Temporary" << endl;
}

template<class T>
void myList<T>::PrintReverse(){
    cout << "Temporary" << endl;
}

template<class T>
void myList<T>::Sort(){
    doubleList->sort();
    cout << "Temporary" << endl;
}

#endif


