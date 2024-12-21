#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string title;
    std::string description;
    bool completed;

public:
    Task(const std::string& title, const std::string& description)
        : title(title), description(description), completed(false) {
        if (title.empty() || description.empty()) {
            throw std::invalid_argument("Tytuł i opis nie mogą być puste.");
        }
    }

    void markAsCompleted() {
        completed = true;
    }

    std::string getStatus() const {
        return completed ? "Zakończono" : "Trwające";
    }

    void displayTask() const {
        std::cout << "Tytuł: " << title << ", Opis: " << description
                  << ", Status: " << getStatus() << std::endl;
    }
};

void displayMenu() {
    std::cout << "\n--- Menadżer zadań ---\n";
    std::cout << "1. Dodaj zadanie\n";
    std::cout << "2. Wyświetl zadania\n";
    std::cout << "3. Oznacz jako zrobione\n";
    std::cout << "4. Usuń zadanie\n";
    std::cout << "5. Wyjdź\n";
    std::cout << "Wybierz opcję: ";
}

int main() {
    std::vector<Task> tasks;
    bool running = true;

    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1: {
                std::string title, description;
                std::cout << "Wpisz nazwe zadania: ";
                std::getline(std::cin, title);
                std::cout << "Wpisz opis zadania: ";
                std::getline(std::cin, description);

                try {
                    tasks.emplace_back(title, description);
                    std::cout << "Dodano zadanie!\n";
                } catch (const std::invalid_argument& e) {
                    std::cout << "Blad: " << e.what() << " Sprobuj ponownie.\n";
                }
                break;
            }
            case 2: {
                if (tasks.empty()) {
                    std::cout << "Brak zadan do wyswietlenia.\n";
                } else {
                    std::cout << "\nZadania:\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        std::cout << (i + 1) << ". ";
                        tasks[i].displayTask();
                    }
                }
                break;
            }
            case 3: {
                size_t taskNumber;
                std::cout << "Podaj numer zadania do oznaczenia: ";
                std::cin >> taskNumber;

                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks[taskNumber - 1].markAsCompleted();
                    std::cout << "Oznaczono zadanie jako ukonczone!\n";
                } else {
                    std::cout << "Nieprawidlowy numer zadania.\n";
                }
                break;
            }
            case 4: {
                size_t taskNumber;
                std::cout << "Podaj numer zadania do usuniecia: ";
                std::cin >> taskNumber;

                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    std::cout << "Zadanie usunieto!\n";
                } else {
                    std::cout << "Nieprawidlowy numer zadania.\n";
                }
                break;
            }
            case 5:
                running = false;
                std::cout << "Wychodzenie!\n";
                break;
            default:
                std::cout << "Nieprawidlowy wybor.\n";
        }
    }

    return 0;
}
