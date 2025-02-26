#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdexcept>

// Using a forward declartion so that it can be aware of Deque when declaring it as a friend class
// Had many errors there ^
template <typename E>
class DoublyLinkedList;

template <typename E>
class SNode {
public:
    E elem;
    SNode<E>* next;
    SNode<E>* prev;
    SNode(const E& e = E{}, SNode<E>* p = nullptr, SNode<E>* n = nullptr) : elem(e), prev(p), next(n) {}
    friend class DoublyLinkedList<E>;
};

template<typename E>
class DoublyLinkedList {
public:
    DoublyLinkedList() : sz(0) {
        head = new SNode<E>;
        tail = new SNode<E>;
        head->next = tail;
        tail->prev = head;
    }
    
    // Get head and tail elements
    const SNode<E>* getHead() const { return head; }
    const SNode<E>* getTail() const { return tail; }
    
    // Return size of list
    int size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    const E& first() const {
        if (empty()) throw std::runtime_error("List is empty");
        return head->next->elem;
    }

    const E& last() const {
        if (empty()) throw std::runtime_error("List is empty");
        return tail->prev->elem;
    }

    void addFirst(const E& e) {
        addBetween(e, head, head->next);
    }

    void addLast(const E& e) {
        addBetween(e, tail->prev, tail);
    }

    void removeFirst() {
        if (empty()) throw std::runtime_error("List is empty");
        remove(head->next);
    }

    void removeLast() {
        if (empty()) throw std::runtime_error("List is empty");
        remove(tail->prev);
    }

    void clear() {
        while (!empty()) {
            removeFirst();
        }
    }

private:
    SNode<E>* head;
    SNode<E>* tail;
    int sz;

    void addBetween(const E& e, SNode<E>* pred, SNode<E>* succ) {
        SNode<E>* newNode = new SNode<E>(e, pred, succ);
        pred->next = newNode;
        succ->prev = newNode;
        sz++;
    }

    void remove(SNode<E>* p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        sz--;
    }
};

#endif
