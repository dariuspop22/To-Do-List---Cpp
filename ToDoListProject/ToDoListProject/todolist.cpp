#include "todolist.h"
#include <iostream>
#include<fstream>
#include <sstream>      
#include <iostream>     


void ToDoList::addTask(const Task& task)
{
	tasks.push_back(task);
}
void ToDoList::showTasks() const {
	if (tasks.empty()) {
		std::cout << "Nu aveti niciun task!\n";
		return;
	}
	for (size_t i = 0; i < tasks.size(); ++i)
	{
		std::cout << i + 1 << ". " << tasks[i].getInfo() << std::endl;
	}
}
void ToDoList::markTaskCompleted(int index) {
	if (index >= 0 && index < tasks.size())
	{
		tasks[index].markCompleted();
	}
	else {
		std::cout << "Index inexistent \n";
	}
}
void ToDoList::removeTask(int index) {
		if (index >= 0 && index < tasks.size()) {
			tasks.erase(tasks.begin() + index); 
			std::cout << "Sarcina a fost stearsa cu succes!\n";
		}
		else {
			std::cout << "Index invalid! Nu exista o sarcina la acest index.\n";
		}
	}
void ToDoList::saveToFile(const std::string& filename)const {
	std::ofstream outFile(filename);
	if (!outFile) {
		std::cerr << "Eroare la deschiderea fisierului pentru scriere!\n";
		return;
	}
	for (const auto& task : tasks)
	{
		outFile << task.toFileFormat() << std::endl;
	}
	outFile.close();
	std::cout << "Sarcinile au fost salvate cu succes in fisierul \"" << filename << "\".\n";
}
void ToDoList::loadFromFile(const std::string& filename) {
	std::ifstream inFile(filename);

	if (!inFile) {
		std::cerr << "Fisierul \"" << filename << "\" nu a fost gasit. O lista noua va fi creata.\n";
		return;
	}

	tasks.clear(); 

	std::string line;
	while (std::getline(inFile, line)) {
		std::istringstream iss(line);
		std::string title, description, deadline, completedStr;

		std::getline(iss, title, '|');
		std::getline(iss, description, '|');
		std::getline(iss, deadline, '|');
		std::getline(iss, completedStr);

		// Elimină spațiile și caracterele de linie nouă din `completedStr`
		completedStr.erase(0, completedStr.find_first_not_of(" \t\r\n"));
		completedStr.erase(completedStr.find_last_not_of(" \t\r\n") + 1);

		try {
			Task task(title, description, deadline);
			tasks.push_back(task);

			if (completedStr == "1") {
				markTaskCompleted(tasks.size() - 1); // Modifică ultimul task adăugat
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Eroare la incarcarea taskului: " << e.what() << "\n";
		}
	}

	inFile.close();
	std::cout << "Sarcinile au fost incarcate din fisierul \"" << filename << "\".\n";
}
