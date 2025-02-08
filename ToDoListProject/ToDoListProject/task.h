#ifndef TASK_H
#define TASK_H

#include<string>

class Task {
private: 
	std::string title;
	std::string descriere;
	std::string deadline;
	bool completed;
	bool isValidDeadline(const std::string& date) const;

public:
	Task(std::string title, std::string desccriere, std::string deadline);
	void markCompleted();
	std::string getInfo() const;
	bool isCompleted() const;
	std::string toFileFormat() const;
};
#endif 
