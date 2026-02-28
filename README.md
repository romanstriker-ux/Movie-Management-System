# Movie-Management-System
A modular C++ application for managing movie records with file I/O, OOP principles, and formatted data visualization.

## Key Features
* **Object-Oriented Design:** Implements a `Movie` class with private attributes and public encapsulation (getters/setters).
* **File Persistence:** Reads data from `movie.txt` and can save updates to `outMovie.txt`.
* **Advanced Search:** Filter and display movies by specific **Director** or individual **Film Title**.
* **Data Validation:** Includes robust input validation to prevent program crashes on invalid user entries.
* **Formatted UI:** Features a clean, table-based console interface with horizontal dividers for high readability.

## Technical Stack
* **Language:** C++
* **Concepts:** Classes & Objects, STL Vectors, File I/O (fstream), Input Validation, String Manipulation.
* **Tools:** Formatted output using `<iomanip>` (setw, left, fixed).

## How to Run
1.  Ensure you have `main.cpp`, `Movie.cpp`, `Movie.h`, and `movie.txt` in the same directory.
2.  Compile the project:
    ```bash
    g++ main.cpp Movie.cpp -o MovieApp
    ```
3.  Run the executable:
    ```bash
    ./MovieApp
    ```
