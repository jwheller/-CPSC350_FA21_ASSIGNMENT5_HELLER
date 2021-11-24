// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 5

//Template class for a double-Linked list
#include "ListNode.h"

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

using namespace std;

template<class T>
class DoubleLinkedList{
    
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size; //the size of a list would never be negative, so this int can be unsigned

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void insertFront(T d);
        void insertBack(T d); 
        void removeFront();
        T returnFront(); 
        void removeBack(); 
        T returnBack();
        T find(T data);
        void insertAfter(T existingData, T newData);
        void print();
        T returnEachNode();
        void sort();
        bool isEmpty();
        unsigned int getSize();
};



template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    size = 0;
    front = NULL;
    back = NULL;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    delete front;
    delete back;
}

template<class T>
void DoubleLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(front == NULL){
        front = node;
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
        front = node;
    }
    ++size;
}

template<class T>
void DoubleLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);
 
    if(front == NULL){
        front = node;
        back = node;
           
    }
    else{
        node->prev = back;
        back->next = node;
        back = node;
    }
    ++size;
}

template<class T>
void DoubleLinkedList<T>::removeFront(){
    ListNode<T>* oldfront = front;

    if (front == NULL){
        cout << "Queue is empty" << endl;
    }

    else if (front == back){
        front = NULL;
        back = NULL;
        --size;
    }

    else{
        front = oldfront->next;
        --size;
    }
    delete oldfront;
}

template<class T>
T DoubleLinkedList<T>::returnFront(){
    return front->data;
}

template<class T>
void DoubleLinkedList<T>::removeBack(){
    ListNode<T> *oldback = back; //Create a pointer to the current node in the back
    back = back->prev; //Set the back pointer to the node before back
    delete oldback; //delete the pointer
    --size; //decrement the size
}

template<class T>
T DoubleLinkedList<T>::returnBack(){
    return front->data;
}

template<class T>
void DoubleLinkedList<T>::print(){
    ListNode<T>* currNode = front;
    if(front == NULL){
        cout << "Queue is empty" << endl;
    }
    else{
        while(currNode != NULL){
            cout << currNode->data << ", ";
            currNode = currNode->next;
        }
        cout << endl;
    }
    delete currNode;
}

template<class T>
T DoubleLinkedList<T>::returnEachNode(){
    ListNode<T>* currNode = front;
    while(currNode != NULL){
        return currNode->data;
        currNode = currNode->next;
    }
    delete currNode;
}

template<class T>
bool DoubleLinkedList<T>::isEmpty(){
    if (front == NULL){ //If the front is NULL, by definition the tail must be too
        return true;
    }
    else{
        return false;
    }
}

template<class T>
unsigned int DoubleLinkedList<T>::getSize(){
    return size;
}

template<class T>
void DoubleLinkedList<T>::sort(){ //Method from Zybooks
    if (front != NULL && front->next != NULL){

        ListNode<T> *currNode = front -> next;
        ListNode<T> *nextNode = currNode -> next;
        ListNode<T> *searchNode = front;
        while (currNode != NULL){
            nextNode = currNode -> next;
            searchNode = currNode -> prev;
            while (searchNode != NULL && searchNode->data > currNode -> data){
                searchNode = searchNode -> prev;
            }
            //Remove then reinsert currNode
            (currNode->prev)->next = currNode->next;
            (currNode->next)->prev = currNode->prev;
            if (searchNode == NULL){
                currNode->prev = NULL;
                //Insert currNode to front:
                currNode->next = front;
                front->prev = currNode;
                front = currNode;
            }
            else{
                currNode->prev = searchNode;
                currNode->next = searchNode -> next;
                (searchNode -> next) -> prev = currNode;
                searchNode->next = currNode;
            }
            currNode = nextNode;
        }
        delete currNode, nextNode, searchNode;
    }
}

#endif
