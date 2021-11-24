# CPSC350_FA21_ASSIGNMENT5_HELLER

Jaden Heller
2328279
jaheller@chapman.edu
CPSC-350-01
Assignment 5


Registrar’s Office Simulation


Classes:
DoubleLinkedList - A template class that creates the functionality of a double linked list

ListNode - Individual nodes, which are the objects that fill a double-linked list

ListInterface - The definitions AND implementation of an interface that utilizes the functionality of a double-linked lsit to make a Queue in GenQueue

GenQueue - A queue class that uses the functionality of the ListInterface class to build a Queue, of which will hold both Students and Ints in the main Simulation

Student - The class that holds all the info of a given student

Window - Class used to build a registrar window object

FileProcessor - Used to open and read from a specifed text file as well as create an array from it

Simulation - The main simulation class that combines all the previous listed classes to simulate the scenario

SimStatistics - Calculates the statistics of the simulation after an instance of it runs

main - The Main method


Problems:
Does not calculate max, med, or minumum wait or idle times

Sources used:
Used in Student.h/.cpp :
https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170 used to help me learn how to control what a "std::cout" will return when used on a Student object (so that it will display the amount of time each individual needed at a window as their printable info). 