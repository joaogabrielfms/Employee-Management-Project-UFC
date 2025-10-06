# Employee-Management-Project-UFC
Academic project in C language for managing employees, positions and departments with data persistence in files.

## Employee Management System in C

An academic project developed in the C language that simulates a human resources management system for a small company. This is a console-based application that performs CRUD (Create, Read, Update, Delete) operations.

## Features

The system's main menu offers a complete set of operations to manage company data, referencing the original Portuguese functions:

* **1. Inserir:** Allows registering new employees, positions, or departments in the system.
* **2. Atualizar:** Provides the option to modify information of an existing employee, position, or department.
* **3. Excluir:** Removes a record (employee, position, or department) from the system.
* **4. Buscar:** Searches for a specific record and displays its detailed information.
* **5. Relatório por Departamento:** Generates a list of all employees, grouped by their respective department, making it easy to visualize the team structure.
* **6. Relatório de Salário:** Displays a report with employee salaries. The function can include sorting (from highest to lowest) for cost analysis.
* **0. Sair:** Saves all changes made during the session to data files and safely exits the program.

## Technologies Used

* **C Language** as the foundation for all program logic.
* **GCC (MinGW-w64)** as the compiler.
* **Data Structures (`structs`)** to model the entities (Employee, Position, Department).
* **File Handling (File I/O)** to ensure data persistence.

## How to Run the Project

To compile and run this project locally, follow the steps below.

### Prerequisites

A C compiler (like GCC via MinGW-w64) must be installed and correctly configured in the system's PATH.

### Step-by-Step

```bash
# 1. Clone the repository to your local machine
git clone [https://github.com/joaogabrielfms/Employee-Management-Project-UFC.git](https://github.com/joaogabrielfms/Employee-Management-Project-UFC.git)

# 2. Navigate to the project folder
cd YOUR-REPOSITORY-NAME

# 3. Compile all source files (.c) together
# This command creates an executable named "programa.exe"
gcc *.c -o programa.exe

# 4. Run the program
# On Windows, use:
./programa.exe
# Or simply:
# programa.exe
```

## Author

Made by João Gabriel Frota de Moura Santos.

* **LinkedIn:** `https://linkedin.com/in/joão-gabriel-frota-de-moura-santos`
* **GitHub:** `https://github.com/joaogabrielfms`
--
