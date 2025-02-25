//
//  main.cpp
//  TaskList
//
//  Created by Imrahn Faqiri on 2025-02-09.
//
#include "Deque.h"
#include <iostream>

using namespace std;

void display_options() {
    cout << "===== TASK LIST MENU =====" << endl;
    cout << "1. Add High Priority Task" << endl;
    cout << "2. Add Low Priority Task" << endl;
    cout << "3. View Tasks" << endl;
    cout << "4. View Tasks (reversed order)" << endl;
    cout << "5. Complete Highest Priority Task" << endl;
    cout << "6. Complete Lowest Priority Task" << endl;
    cout << "7. Clear Tasks" << endl;
    cout << "8. Exit" << endl;
    cout << "==========================\n" << endl;
    cout << "Please enter your choice:" << endl;
}

// Input validation
bool validateDigits(int& choice) {
    cin >> choice;

    // Check if it is a valid number
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }

    // If it doesn't fail, we have a valid input!
    cin.clear();
    cin.ignore(256, '\n');
    return true;
}

bool validateString(string& choice) {
    cin >> choice;

    if (choice.empty()) {
        return false; // empty string
    }
    cin.clear();
    cin.ignore(256, '\n');
    return true; // non-empty
}

void validatePop(Deque<string>& dq, int priority) {
    if (dq.isEmpty()) {
        cout << "There are currently no pending tasks to complete.\n" << endl;
    } else {
        cout << "\nCompleted Task: ";
        if (priority == 0) {
            cout << dq.popLeft();
        } else {
            cout << dq.popRight();
        } cout << "\nPending Tasks: " << dq.size() << "\n\n" << endl;
    }
    
}

string createTask() {
    string task;
    cout << "\n\n--||Creating a Task||--" << endl;
    cout << "Please enter the task you would like to add:" << endl;
    while (!validateString(task)) {
        cout << "Please enter a non-empty string." << endl;
    }
    
    cout << "\n* Successfully added '" << task << "' to your Task List. *\n" << endl;
    return task;
}


int main() {
    cout << "Welcome to the Task List where you can manage your tasks!\nHere are your options:\n\n";
    
    int choice = 0;
    Deque<string> dq;
    /*
    dq.pushRight("Important");
    dq.pushRight("Neutral");
    dq.pushRight("Not Important");
    */
    do {
        display_options();
        
        if (!validateDigits(choice)) {
            cout << "\n\n--||Invalid input. Please try again||--\n\n" << endl;
            continue;
        }
        
        switch (choice) {
            case 1: // Add high priority
                dq.pushLeft(createTask());
                break;
            case 2: // Add low priority
                dq.pushRight(createTask());
                break;
            case 3: // View Tasks
                dq.print();
                break;
            case 4: // View tasks (reversed)
                dq.printRev();
                break;
            case 5: // Complete (pop) highest priority
                validatePop(dq, 0); // 0 - left/high priority
                break;
            case 6: // Complete (pop) lowest priority
                validatePop(dq, 1); // 1 - right/low priority
                break;
            case 7: // Clear list
                dq.clear();
                break;
            case 8:
                cout << "\nThank you for using the program!" << endl;
                break;
            default:
                cout << "\nThank you for using the program!" << endl;
                break;
        }
        
    }
    while (choice != 8);
    return 0;
}
