#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string taskName;
    string status; 
};

class TaskManager 
{
private:
    vector<Task> tasks;

public:
   
    void addTask(const string &taskName) 
    {
        Task newTask = {taskName, "pending"};
        tasks.push_back(newTask);
        cout << "Task '" << taskName << "' added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].taskName << " - " << tasks[i].status << endl;
        }
    }

    void markTaskCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].status = "completed";
            cout << "Task " << taskNumber << " marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    void removeTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            cout << "Task '" << tasks[taskNumber - 1].taskName << "' removed." <<endl;
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            cout << "Invalid task number." <<endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int option, taskNumber;
    string taskName;

    while (true) {
        cout << "\nOptions:\n 1) Add Task \n 2) View Tasks \n 3) Mark Task as Completed \n 4) Remove Task \n 5) Exit" <<endl;
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore();  

        switch (option) {
            case 1:
                cout << "Enter the task: ";
                getline(cin, taskName);
                taskManager.addTask(taskName);
                break;

            case 2:
                taskManager.viewTasks();
                break;

            case 3:
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                taskManager.markTaskCompleted(taskNumber);
                break;

            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                taskManager.removeTask(taskNumber);
                break;

            case 5:
                cout << "Exiting the task manager."<<endl;
                return 0;

            default:
                cout << "Invalid option. Please try again." <<endl;
        }
    }
}
