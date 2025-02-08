#include "todolist.h"
#include<iostream>
#include<thread>
using namespace std;


int main()
{
    ToDoList list;
    int choice;
    list.loadFromFile("tasks.txt");

    do {
        // Afișează meniul
        cout << "\n--- To-Do List ---\n";
        std::cout << "1. Adauga sarcina\n";
        std::cout << "2. Afiseaza sarcini\n";
        std::cout << "3. Marcheaza ca finalizata\n";
        std::cout << "4. Sterge o sarcina\n";
        std::cout << "5. Salveaza sarcinile in fisier\n";
        std::cout << "0. Iesire\n";
        std::cout << "Alege optiunea: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 0:
        {
            //autosave
            std::cout << "Saving...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            list.saveToFile("tasks.txt");
            exit(0);
        }
        case 1: {
            string titlu, descriere, deadline;
            cout << "Titlu: ";
            getline(cin, titlu);
            cout << "Descriere: ";
            getline(cin, descriere);
            cout << "Deadline (dd.mm.yyyy): ";
            getline(cin, deadline);

            try {
                // Creează și adaugă task-ul
                Task task(titlu, descriere, deadline);
                list.addTask(task); // Adaugă task-ul în listă
                std::cout << "Sarcina a fost adaugata cu succes!\n";
            }
            catch (const std::invalid_argument& e) {
                // Prinde excepția și afișează mesajul de eroare
                std::cerr << "Eroare: " << e.what() << "\n";
            }
        }
              break;
        case 2: {
            list.showTasks();
        }
            break;
        case 3: {
            int index;
            cout << "Introduceti indexul taskului pe care il doriti finalizat \n";
            cin >> index;
            cin.ignore();
            list.markTaskCompleted(index - 1);
            cout << "Sarcina a fost marcata ca finalizata\n";
        }
            break;
        case 4: {
            int index;
            cout << "Introduceti indexul taskului pe care il doriti sters \n";
            cin >> index;
            cin.ignore();
            list.removeTask(index - 1);
        }
            break;
        case 5:{
            list.saveToFile("tasks.txt"); 
            break;
        }
            break;
        default:cout << "Optiune invalida. Mai incearca!\n";
            break;
        }
    } while (choice!=0);
    return 0;
}