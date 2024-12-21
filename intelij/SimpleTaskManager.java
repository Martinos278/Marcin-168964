import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SimpleTaskManager {

    static class Task {
        private String title;
        private String description;

        public Task(String title, String description) {
            this.title = title;
            this.description = description;
        }

        @Override
        public String toString() {
            return "Tytuł: " + title + ", Opis: " + description;
        }
    }

    public static void main(String[] args) {
        List<Task> tasks = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("\n--- Menadżer zadań ---");
            System.out.println("1. Dodaj zadanie");
            System.out.println("2. Wyświetl zadania");
            System.out.println("3. Usuń zadanie");
            System.out.println("4. Wyjdź");
            System.out.print("Wybierz opcję: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Clear the newline

            switch (choice) {
                case 1 -> {
                    System.out.print("Podaj nazwę zadania: ");
                    String title = scanner.nextLine();
                    System.out.print("Wpisz opis zadania: ");
                    String description = scanner.nextLine();
                    tasks.add(new Task(title, description));
                    System.out.println("Zadanie dodane!");
                }
                case 2 -> {
                    if (tasks.isEmpty()) {
                        System.out.println("Brak zadań do wyświetlenia.");
                    } else {
                        System.out.println("\nZadania:");
                        for (int i = 0; i < tasks.size(); i++) {
                            System.out.println((i + 1) + ". " + tasks.get(i));
                        }
                    }
                }
                case 3 -> {
                    System.out.print("Podaj numer zadania do usunięcia: ");
                    int taskNumber = scanner.nextInt();
                    if (taskNumber > 0 && taskNumber <= tasks.size()) {
                        tasks.remove(taskNumber - 1);
                        System.out.println("Zadanie usunięte!");
                    } else {
                        System.out.println("Nieprawidłowy numer zadania.");
                    }
                }
                case 4 -> {
                    running = false;
                    System.out.println("Wyjście... Do zobaczenia!");
                }
                default -> System.out.println("Nieprawidłowa operacja. Proszę spróbować ponownie.");
            }
        }

        scanner.close();
    }
}
