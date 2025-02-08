#include "task.h"
#include<iostream>
#include <stdexcept> 
#include <cctype>   

Task::Task(std::string t, std::string d, std::string dl)
{
    if (!isValidDeadline(dl)) {
        throw std::invalid_argument("Data invalida! Task-ul nu va fi adaugat.");
    }
	title = t;
	descriere = d;
	deadline = dl;
	completed=false;

}
void Task::markCompleted() {
	completed = true;
}
std::string Task::getInfo() const {
	return (completed ? "[✔] " : "[ ] ") + title + " - " + descriere + " (Due: " + deadline + ")";
}
bool Task::isCompleted() const {
	return completed;
}
std::string Task::toFileFormat() const {
	return title + "|" + descriere + "|" + deadline + "|"+ (completed ? "1" : "0");
}
bool Task::isValidDeadline(const std::string& date) const {
    // Verifică dacă lungimea este exact 10 caractere
    if (date.length() != 10) {
        return false;
    }

    // Verifică pozițiile punctelor
    if (date[2] != '.' || date[5] != '.') {
        return false;
    }

    // Verifică dacă toate celelalte caractere sunt cifre
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 2 || i == 5) continue; // Sari peste puncte
        if (!isdigit(date[i])) {
            return false;
        }
    }

    // Extrage ziua, luna și anul pentru validare suplimentară
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    // Verifică limitele pentru zi, lună și an
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }

    // Verifică zilele pentru luni specifice (ex. februarie, aprilie, etc.)
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    // Verifică anul bisect pentru februarie
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) {
            return false;
        }
    }

    return true; // Data este validă
}