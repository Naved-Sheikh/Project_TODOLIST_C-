#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display_task(string task[], int task_count, vector<bool> &status) {
    cout << "\n\n\tTasks to do:  " << endl;
    cout << "*************************************************" << endl;
    for (int i = 0; i < task_count; i++) {
        cout << "Task " << i + 1 << ":  " << task[i];
        if (status[i]) {
            cout << "\t(It is completed)" << endl;
        } else {
            cout << endl;
        }
    }
    cout << "*************************************************\n\n" << endl;
}

int main() {
    string task[10] = { "" };
    vector<bool> visited(10, false);
    int option = -1, task_count = 0;

    while (option != 5) {
        cout << "<----------- To-Do List ----------->" << endl;
        cout << "Enter 1 To Add task" << endl;
        cout << "Enter 2 To View all your tasks" << endl;
        cout << "Enter 3 To Delete a task" << endl;
        cout << "Enter 4 To Mark a task as completed" << endl;
        cout << "Enter 5 To Exit" << endl;

        cin >> option;

        switch (option) {
        case 1: {
            if (task_count >= 10) {
                cout << "Task list is full!" << endl;
            } else {
                cout << "Enter a New Task: ";
                cin.ignore();
                getline(cin, task[task_count]);
                visited[task_count] = false; 
                task_count++;
            }
            break;
        }

        case 2: {
            display_task(task, task_count, visited);
            break;
        }

        case 3: {
            int del_task;
            cout << "Enter Task Number to delete: ";
            cin >> del_task;
            if (del_task < 1 || del_task > task_count) {
                cout << "Invalid task number!" << endl;
            } else {
                for (int i = del_task - 1; i < task_count - 1; i++) {
                    task[i] = task[i + 1];
                    visited[i] = visited[i + 1];
                }
                task_count--;
                cout << "Task " << del_task << " deleted successfully!" << endl;
            }
            break;
        }

        case 4: {
            int completion;
            cout << "Enter the Task Number to mark as completed: ";
            cin >> completion;
            if (completion < 1 || completion > task_count) {
                cout << "Invalid task number!" << endl;
            } else if (visited[completion - 1]) {
                cout << "Task already marked as completed." << endl;
            } else {
                visited[completion - 1] = true;
                cout << "Task " << completion << " marked as completed." << endl;
            }
            break;
        }

        case 5:
            cout << "Program terminated successfully." << endl;
            break;

        default:
            cout << "Invalid Option!" << endl;
            break;
        }
    }

    return 0;
}
