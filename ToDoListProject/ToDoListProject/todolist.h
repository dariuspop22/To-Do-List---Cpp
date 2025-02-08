#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <vector>

class ToDoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const Task& task);
    void showTasks() const;
    void markTaskCompleted(int index);
    void removeTask(int index);
    void saveToFile(const std::string& filename)const;
    void loadFromFile(const std::string& filename);
};

#endif
