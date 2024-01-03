#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void removeTask(const std::string& description) {
        auto it = std::remove_if(tasks.begin(), tasks.end(),
                                 [&](const Task& task) { return task.description == description; });

        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            std::cout << "Task removed: " << description << std::endl;
        } else {
            std::cout << "Task not found: " << description << std::endl;
        }
    }

    void markTaskAsCompleted(const std::string& description) {
        auto it = std::find_if(tasks.begin(), tasks.end(),
                               [&](const Task& task) { return task.description == description; });

        if (it != tasks.end()) {
            it->completed = true;
            std::cout << "Task marked as completed: " << description << std::endl;
        } else {
            std::cout << "Task not found: " << description << std::endl;
        }
    }

    void displayTasks() const {
        std::cout << "Tasks:" << std::endl;
        for (const auto& task : tasks) {
            std::cout << "- " << (task.completed ? "[X]" : "[ ]") << " " << task.description << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "\nTask Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Display Tasks\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose option (1-5): ";

        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::cin.ignore();
                std::getline(std::cin, description);
                taskManager.addTask(description);
                break;
            }
            case 2: {
                std::cout << "Enter task description to remove: ";
                std::string description;
                std::cin.ignore();
                std::getline(std::cin, description);
                taskManager.removeTask(description);
                break;
            }
            case 3: {
                std::cout << "Enter task description to mark as completed: ";
                std::string description;
                std::cin.ignore();
                std::getline(std::cin, description);
                taskManager.markTaskAsCompleted(description);
                break;
            }
            case 4:
                taskManager.displayTasks();
                break;
            case 5:
                std::cout << "Exiting Task Manager. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option. Please choose again.\n";
        }
    }

    return 0;
}
