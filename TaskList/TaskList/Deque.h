//
//  Deque.h
//  TaskList
//
//  Created by Imrahn Faqiri on 2025-02-09.
//
#pragma once
#ifndef Deque_h
#define Deque_h

#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
class Deque {
private:
    DoublyLinkedList<T> list;
public:
    // Constructor and Destructor
    //Deque(){}
    //~Deque(){}

    // Self explanatory methods
    bool isEmpty() const {
        return list.empty();
    }
    
    int size() const {
        return list.size();
    }
    
    void pushLeft(const T& item) {
        list.addFirst(item);
    }
    
    void pushRight(const T& item) {
        list.addLast(item);
    }
    
    // Throw error if we have an empty list. If not, return the element and delete.
    T popLeft() {
        if (isEmpty()) {
            throw std::runtime_error("\nError: list is empty; cannot popLeft()");
        } else {
            T elem = list.first();
            list.removeFirst();
            return elem;
        }
    }
    
    // Throw error if we have an empty list. If not, return the element and delete.
    T popRight() {
        if (isEmpty()) {
            throw std::runtime_error("\nError: list is empty; cannot popRight()");
        } else {
            T elem = list.last();
            list.removeLast();
            return elem;
        }
    }
    
    // Attempt to clear list and notify result.
    void clear() {
        cout << "\n/////////////////////////////" << endl;
        if (isEmpty()) {
            cout << "There were no pending tasks to clear." << endl;
        } else {
            list.clear();
            cout << "Cleared all pending tasks." << endl;
        }
        cout << "/////////////////////////////\n" << endl;
    }
    
    // Print in normal order
    void print() const {
        if (isEmpty()) {
            cout << "There are currently no pending tasks.\n" << endl;
            return;
        }
        
        int counter = 1; // Used to show priority of task
        SNode<T>* currentItem = list.getHead()->next; // Iteratable Node
        
        
        cout << "Tasks to Complete (" << size() << "): " << endl;
        while (currentItem->next != nullptr) { // Make sure the next item isn't null
            cout << counter++ << ". [" << currentItem->elem << "]" << endl; // Print task
            currentItem = currentItem->next; // Incremenet it
        }
        cout << endl << endl;
        
    }
    
    void printRev() const {
        if (isEmpty()) {
            cout << "There are currently no pending tasks.\n" << endl;
            return;
        }
        
        int counter = size(); // Priority starts in reversed order
        SNode<T>* currentItem = list.getTail()->prev;
        // Same as print()
        cout << "Tasks to Complete (reversed) (" << size() << "): " << endl;
        while (currentItem != list.getHead()) {
            cout << counter-- << ". [" << currentItem->elem << "] " << endl;
            currentItem = currentItem->prev; // incremenet it
        }
        cout << endl << endl;
        
    }
    
};

#endif /* Deque_h */
