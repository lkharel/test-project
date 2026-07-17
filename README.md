# C++ Learning Repository

A personal repository for learning and practicing modern **C++ (C++20)**. It contains progressively organized examples ranging from basic syntax to object-oriented programming, STL, algorithms, multithreading, and larger projects.

> **Status:** 🚧 Actively learning and expanding the repository.

---

## Repository Structure

```text
test-project/
├── algorithms/          # Algorithms and problem-solving examples
├── basics/              # Basic C++ syntax and programming exercises
├── data_structures/     # Graphs, trees, linked lists, etc.
├── file_io/             # File input/output examples
├── functions/           # Function-related examples
├── include/             # Shared header files
├── multithreading/      # Threading and concurrency examples
├── oop/                 # Object-Oriented Programming examples
├── projects/            # Larger C++ projects
├── scripts/
│   └── build-debug.sh   # Build automation script
├── stl/                 # Standard Template Library examples
├── tests/               # Unit tests
├── build/               # Generated build files (ignored by Git)
├── build.xml            # Apache Ant build configuration
├── .gitignore
└── README.md
```

---

## Features

- Modern C++20 examples
- Organized by topic
- Apache Ant build automation
- Debug build support
- Git-friendly project structure
- Ready for future unit testing

---

## Requirements

- macOS or Linux
- C++20 compatible compiler
  - Apple Clang
  - GCC
- Java 8 or later
- Apache Ant

Verify your installation:

```bash
clang++ --version
java -version
ant -version
```

---

## Getting Started

Clone the repository:

```bash
git clone https://github.com/lkharel/test-project.git
cd test-project
```

Build the project:

```bash
./scripts/build-debug.sh
```

Run the example:

```bash
ant run
```

Or run the executable directly:

```bash
./build/graph
```

---

## Example Output

```text
Shortest distance: 249
Path: Huntsville -> Birmingham -> Atlanta
```

---

## Topics Covered

- Variables
- Data Types
- Input / Output
- Control Flow
- Functions
- Arrays
- Strings
- Object-Oriented Programming
- STL Containers
- STL Algorithms
- Iterators
- File I/O
- Graph Algorithms
- Multithreading
- Larger C++ Projects

More topics will be added as the repository grows.

---

## Build Commands

Clean:

```bash
ant clean
```

Debug Build:

```bash
ant debug
```

CppUnit Build:

```bash
ant cppUnitBuild
```

Run:

```bash
ant run
```

---

## Git Workflow

Check repository status:

```bash
git status
```

View commit history:

```bash
git log --oneline --graph --decorate
```

Commit changes:

```bash
git add .
git commit -m "Describe your changes"
git push
```

---

## Learning Goals

This repository documents my journey toward becoming a stronger C++ developer by practicing:

- Modern C++ (C++20)
- STL
- Object-Oriented Design
- Algorithms
- Data Structures
- Multithreading
- Build Automation with Apache Ant
- Unit Testing
- Debugging
- Writing clean and maintainable code

---

## Roadmap

Planned additions include:

- Smart Pointers
- Templates
- Exception Handling
- Move Semantics
- Lambda Expressions
- Design Patterns
- Binary Trees
- Hash Tables
- Graph Algorithms
- File Parsing
- GoogleTest
- CppUnit
- CMake
- Performance Optimization
- Networking
- Concurrency Utilities

---

## License

This repository is intended for educational and learning purposes.