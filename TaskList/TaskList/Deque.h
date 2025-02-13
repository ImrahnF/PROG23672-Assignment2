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
    int size() const;
    void pushLeft(const T& item);
    void pushRight(const T& item);
    T popLeft();
    T popRight();
    void clear();
    void print() const;
    void printRev() const;
};

#endif /* Deque_h */
