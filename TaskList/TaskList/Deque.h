//
//  Deque.h
//  TaskList
//
//  Created by Imrahn Faqiri on 2025-02-09.
//
#pragma once
#ifndef Deque_h
#define Deque_h

#include <iostream>

using namespace std;

// Using a forward declartion so that it can be aware of Deque when declaring it as a friend class
// Had many errors there ^
template <typename T>
class Deque;

template <typename T>
class Node {
public:
    T element;
    Node<T>* next;
    Node<T>* previous;
    
    // Constructor
    Node(const T& e = T{}, Node<T>* n = nullptr, Node<T>* p = nullptr) :
    element(e), next(n), previous(p) {}
    
    friend class Deque<T>;
};

template <typename T>
class Deque {
private:
    Node<T>* head;
    Node<T>* tail;
    int sz = 0;
public:
    // Constructor and Destructor
    Deque() { cout << "Deque has been created!" << endl; }
    ~Deque() { cout << "Deque has been destroyed." << endl; }

    // strucyutre
    bool isEmpty() const;
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
