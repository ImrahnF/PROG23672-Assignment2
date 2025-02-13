//
//  main.cpp
//  TaskList
//
//  Created by Imrahn Faqiri on 2025-02-09.
//
#include "Deque.h"
#include <iostream>

using namespace std;

int main() {
    Deque<int> dq;
    
    dq.pushLeft(123);
    dq.pushRight(456);
    dq.pushRight(789);
    dq.print();
    dq.clear();
    dq.printRev();
    return 0;
}
