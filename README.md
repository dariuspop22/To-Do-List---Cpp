# To-Do-List---Cpp
A simple To-Do List console application in C++ using OOP.

📝 To-Do List in C++

A simple command-line task manager written in **C++** that allows users to create, manage, and save tasks to a file for later use.

📌 Features

✅ **Add Task**  
   - The user enters a **title, description, and deadline** (validated in DD.MM.YYYY format).  
   - Tasks are added only if the entered date is valid.  

✅ **Display Tasks**  
   - Lists all saved tasks, indicating which are **completed** `[✔]` and which are not `[ ]`.  

✅ **Mark Task as Completed**  
   - The user selects a task to mark it as **completed**.  
   - Automatically saves the status in the file (`tasks.txt`).  

✅ **Delete Task**  
   - Allows the user to remove a specified task from the list and the file.  

✅ **Automatic Saving and Loading**  
   - **Automatic saving** after every modification.  
   - **Automatic loading** when the program starts, recognizing completed tasks.  

✅ **Validation and Error Handling**  
   - Strict validation of the date format (DD.MM.YYYY).  
   - **Recognizes leap years** and validates 29.02.YYYY.  
   - Prevents incorrect data input and file corruption.  
   - **Exception handling** (`std::invalid_argument` for invalid dates).  

## 🏗 Project Structure
📂 ToDoListProject ├── 📄 main.cpp # User interface and main menu ├── 📄 task.h/cpp # Task class for task management ├── 📄 todolist.h/cpp # ToDoList class for handling task lists ├── 📄 tasks.txt # File where tasks are stored

## 🚀 How to Use?
1. **Clone the repository:**

🛠 Technologies Used
C++ (OOP)
STL (vector, fstream, map)
File-based persistent storage

👨‍💻 Author
Developed by Pop Darius, Student
