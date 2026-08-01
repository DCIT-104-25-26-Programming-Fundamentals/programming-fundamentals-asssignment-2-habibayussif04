// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// -----------------------------------------------------------------------------
// FEATURE 1: Add a Task
// -----------------------------------------------------------------------------
void addTask(vector<string>& tasks) {
    cout << "Enter task: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline buffer
    string task;
    getline(cin, task);

    if (!task.empty()) {
        tasks.push_back(task);
        cout << "Task added: \"" << task << "\"" << endl;
    } else {
        cout << "Task description cannot be empty." << endl;
    }
}

// -----------------------------------------------------------------------------
// FEATURE 2: View All Tasks
// -----------------------------------------------------------------------------
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!" << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// -----------------------------------------------------------------------------
// FEATURE 3: Delete a Task
// -----------------------------------------------------------------------------
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty! Nothing to delete." << endl;
        return;
    }

    // Display current list first
    viewTasks(tasks);

    cout << "\nEnter task number to delete: ";
    int index;
    cin >> index;

    // Check bounds
    if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
        string removedTask = tasks[index - 1];
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task \"" << removedTask << "\" has been removed." << endl;
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

// -----------------------------------------------------------------------------
// MENU HELPER
// -----------------------------------------------------------------------------
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "       TO-DO LIST MENU      " << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<string> tasks;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cin >> choice;

        // Check for non-numeric or broken input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please pick an option from 1 to 4." << endl;
                break;
        }
    }

    return 0;
}
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

