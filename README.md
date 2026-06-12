# Object-Oriented Programming (OOP) Assignments

This repository contains academic assignments and projects for the Object-Oriented Programming course, implemented in **C++** and **Java**.

---

## 📂 Repository Structure

*   **[Offline-1](./Offline-1)** (C++)
    *   **Topic:** Classes, Objects, Constructor Overloading, and Destructors.
    *   **Description:** Implements a student database structure with custom getter/setter methods.
*   **[Offline-2](./Offline-2)** (C++)
    *   **Topic:** Class Associations and Game Loop.
    *   **Description:** A text-based interactive implementation of the classic **Wumpus World** game.
*   **[Offline-3](./Offline-3)** (C++)
    *   **Topic:** Operator Overloading.
    *   **Description:** Overloads mathematical (`+`, `-`, `*`), increment (`++`), and comparison (`==`, `>`, `<`, etc.) operators for custom 2D shapes like `Point2D`, `Circle`, and `Rectangle`.
*   **[Offline-4](./Offline-4)** (Java)
    *   **Topic:** Aggregation, Encapsulation, and File Input in Java.
    *   **Description:** A console-based **Festival Management System** that allows registering/canceling student participants across multiple festival events.

---

## 🚀 How to Run

### C++ Assignments (Offline 1, 2, & 3)

1.  Navigate into the specific offline directory (e.g., `Offline-1`):
    ```bash
    cd Offline-1
    ```
2.  Compile the source file:
    ```bash
    g++ 2105152.cpp -o program
    ```
3.  Run the program:
    *   On Windows:
        ```bash
        program.exe
        ```
    *   On Linux/macOS:
        ```bash
        ./program
        ```

### Java Assignment (Offline 4)

1.  Navigate into the `Offline-4` directory:
    ```bash
    cd Offline-4
    ```
2.  Compile the Java files:
    ```bash
    javac -d . *.java
    ```
3.  Run the program by passing the appropriate command-line arguments (e.g., `<Festival-Name> <Start-Date> <Max-Events>`):
    ```bash
    java com.company.FestivalApp "CSE Fest 2023" "2023-07-15" 10
    ```
