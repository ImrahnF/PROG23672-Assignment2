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
    Deque() { cout << "Deque has been created!" << endl; }
    ~Deque() { cout << "Deque has been destroyed." << endl; }

    // strucyutre
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
    
    T popLeft() {
        if (isEmpty()) { cerr << "Error: list is empty; cannot popLeft()" << endl;}
        T elem = list.first();
        list.removeFirst();
        return elem;
    }
    
    T popRight() {
        if (isEmpty()) { cerr << "Error: list is empty; cannot popRight()" << endl;}
        T elem = list.last();
        list.removeLast();
        return elem;
    }
    
    void clear() {
        
    }
    
    void print() {
        
    }
    
    void printRev() {
        
    }
    
};

#endif /* Deque_h */
