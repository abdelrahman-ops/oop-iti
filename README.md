# Object-Oriented Programming (OOP) in C++ - ITI Labs

[![C++](https://img.shields.io/badge/Language-C%2B%2B11%20%2F%20C%2B%2B14-blue.svg)](https://isocpp.org/)
[![IDE](https://img.shields.io/badge/IDE-Code%3A%3ABlocks-2d548b.svg)](https://www.codeblocks.org/)
[![Compiler](https://img.shields.io/badge/Compiler-MinGW%20%2F%20GCC-green.svg)](https://www.mingw-w64.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20Console%20%26%20WinBGIm-lightgrey.svg)](https://en.wikipedia.org/wiki/Microsoft_Windows)
[![Track](https://img.shields.io/badge/Track-ITI%209--Month%20Cloud%20Platform-orange.svg)](https://iti.gov.eg/)

Comprehensive repository containing all **12 laboratory assignments**, source code, Code::Blocks projects, and technical documentation for the **Object-Oriented Programming (OOP) in C++** course within the **Information Technology Institute (ITI)** 9-Month Cloud Platform Development Program.

The curriculum traces the full pedagogical journey from foundational procedural C/C++ memory mechanics to advanced object-oriented paradigms, culminating in dynamic runtime polymorphism, abstract class hierarchies, and graphical rendering engines.

---

## Documentation Suite

| Document | Description |
|---|---|
| **[Master Problems Catalog](docs/PROBLEMS.md)** | Exhaustive breakdown of all daily tasks, required problems, optional exercises, bonus challenges, formulas, and code links. |
| **[Setup & Compilation Guide](docs/SETUP_GUIDE.md)** | Step-by-step instructions for Code::Blocks, GCC CLI builds, WinBGIm graphics setup, and RVO compiler flags. |
| **[OOP Concepts & Architectural Reference](docs/OOP_CONCEPTS_CHEATSHEET.md)** | Theoretical deep dives into Encapsulation, Rule of Three, Deep Copying, Inheritance modes, Composition vs Aggregation, and VTables. |

---

## 12-Day Curriculum Matrix

| Day | Focus Topics | Problems Count | Key Milestone Projects | Code Link | Docs Link |
|:---:|---|:---:|---|:---:|:---:|
| **01** | C++ Basics, Console I/O, ASCII & Arithmetic | 7 (4 Req + 3 Opt) | Simple calculator, Hex formatting, ASCII converter | [lab1/](lab1/) | [Day 1 Docs](docs/PROBLEMS.md#day-1-fundamentals-of-cc--console-io) |
| **02** | Control Flow, Loops, Console Cursor (`gotoxy`) | 7 (3 Req + 4 Opt) | **NxN Magic Box**, 3-choice menu, Word counter | [lab2/](lab2/) | [Day 2 Docs](docs/PROBLEMS.md#day-2-control-flow-loops-console-positioning--algorithms) |
| **03** | 1D/2D Arrays, Matrices, Extended Keys | 9 (5 Req + 4 Opt) | **Highlight Menu with Arrow Keys**, Key detector, 2D stats | [lab3/](lab3/) | [Day 3 Docs](docs/PROBLEMS.md#day-3-arrays-matrices-extended-keys--highlight-menus) |
| **04** | Functions, Structs, Modular Design & Recursion | 8 (6 Req + 2 Opt) | **Full CRUD Employee Menu**, Recursive power, Department struct | [lab4/](lab4/) | [Day 4 Docs](docs/PROBLEMS.md#day-4-modular-functions-structs-crud-systems--recursion) |
| **05** | Pointers, Memory Addresses, Reference Semantics | 4 (All Req) | **Single-Line Console Text Editor**, 3-way swap, Multiple returns | [lab5/](lab5/) | [Day 5 Docs](docs/PROBLEMS.md#day-5-pointers-memory-addressing-references--text-editors) |
| **06** | Dynamic Allocation (`new`/`delete`), Intro to OOP | 6 (4 Req + 2 Opt) | **Complex Number Class**, Dynamic Employee CRUD, Dynamic Jagged Array | [lab6/](lab6/) | [Day 6 Docs](docs/PROBLEMS.md#day-6-dynamic-memory-classes-encapsulation--jagged-arrays) |
| **07** | Constructors, Destructors, Overloading, LIFO/FIFO | 4 (All Req) | **Dynamic Stack & Queue Classes**, Scope operator `::`, Ctor tracing | [lab7/](lab7/) | [Day 7 Docs](docs/PROBLEMS.md#day-7-constructors-destructors-overloading-stack--queue) |
| **08** | Deep Copy, Copy Constructor & RVO | 2 (All Req) | **Deep Copy Stack**, Copy constructor tracing, RVO flag study | [lab8/](lab8/) | [Day 8 Docs](docs/PROBLEMS.md#day-8-deep-copy-copy-constructors--return-value-optimization-rvo) |
| **09** | Operator Overloading, Static Members, Templates | 6 (5 Req + 1 Bonus) | **Complex & Date Operators**, `Stack<T>`, `Swap<T>`, Stream `<<` / `>>` | [lab9/](lab9/) | [Day 9 Docs](docs/PROBLEMS.md#day-9-operator-overloading-static-members--generic-templates) |
| **10** | Inheritance, Access Modifiers, Method Overriding | 3 (All Req) | **GeoShape Hierarchy**, Protected inheritance for shape invariants | [lab10/](lab10/) | [Day 10 Docs](docs/PROBLEMS.md#day-10-inheritance-access-modifiers--class-hierarchies) |
| **11** | Composition, Abstract Classes, Borland Graphics | 4 (3 Req + 1 Bonus) | **Geometric Graphics Drawing**, Pure Virtual `CalcArea() = 0`, **Lamp Bonus** | [lab11/](lab11/) | [Day 11 Docs](docs/PROBLEMS.md#day-11-object-composition-abstract-classes--bgi-graphics) |
| **12** | Polymorphism, Aggregation & Heterogeneous Arrays | 4 (All Req) | **Polymorphic Picture System**, Dynamic dispatch, Jagged shapes array | [lab12/](lab12/) | [Day 12 Docs](docs/PROBLEMS.md#day-12-polymorphism-aggregation--heterogeneous-collections) |

---

## Architectural & Project Highlights

### 1. Interactive Console Engine (`MyLibrary.h`)
Leveraging the Windows Console API (`windows.h`), several labs implement terminal GUI utilities:
- **`gotoxy(x, y)`**: Direct console coordinate repositioning via `SetConsoleCursorPosition`.
- **`textattr(color)`**: Dynamic color styling via `SetConsoleTextAttribute`.
- **Arrow-Driven Menus**: Capturing normal vs extended two-byte keys (`0` / `224` prefix) using `_getch()`.
- **Single-Line Editor**: Interactive in-terminal editing buffer with Left, Right, Home, End, Delete, and Backspace keys.

### 2. The Rule of Three & Memory Safety (Days 7–8)
To avoid pointer aliasing and double-free crashes during object copying:
- Dynamic `Stack` and `Queue` data structures implement custom **Deep Copy Constructors** and **Copy Assignment Operators** (`operator=`).
- Tracing copy construction across pass-by-value, return-by-value, and explicit initialization with the compiler flag `-fno-elide-constructors`.

### 3. Comprehensive Operator Overloading & Templates (Day 9)
Extending natural C++ syntax to custom mathematical entities:
- **`Complex`**: Overloaded binary arithmetic (`+`, `-`), scalar commutativity (`7 - C` and `C - 7`), compound assignment (`-=`), pre/post decrement (`--`), type-casting `(int)`, subscript indexing `['R']` / `['I']`, and stream I/O (`cin >>`, `cout <<`).
- **`Date`**: Date subtraction, day addition, comparison, and component access via `['d']`, `['m']`, `['y']`.
- **Generic Templates**: Type-agnostic `Swap<T>` and generic container `Stack<T>`.

### 4. Dynamic Polymorphism & Shape Engine (Days 10–12)
- **Inheritance Hierarchy**: `GeoShape` base class extended by `Rectangle`, `Square`, `Circle`, and `Triangle`.
- **Invariance Protection**: Solved dimension anomalies (`dim1 != dim2`) in symmetric shapes via `protected` inheritance.
- **Abstract Base Classes**: Enforced implementation using pure virtual functions (`virtual void Draw() = 0;`).
- **Heterogeneous Collections**: `Picture` class aggregates heterogeneous shape pointers (`Shape* arr[]`), rendering diverse geometries at runtime via dynamic dispatch (VTables).

---

## Repository Structure

```text
OOP-labs/
├── docs/                                # Detailed technical documentation
│   ├── README.md                        # Documentation index
│   ├── PROBLEMS.md                      # Complete 12-day problem catalog & solutions
│   ├── SETUP_GUIDE.md                   # Code::Blocks & GCC compilation guide
│   └── OOP_CONCEPTS_CHEATSHEET.md       # C++ & OOP architectural reference
├── lab1/                                # Day 1: C++ I/O & basic operations
├── lab2/                                # Day 2: Loops, Magic Box, menus
├── lab3/                                # Day 3: Arrays, 2D arrays, highlight menu
├── lab4/                                # Day 4: Functions, structs, CRUD menu
├── lab5/                                # Day 5: Pointers, swap paradigms, line editor
├── lab6/                                # Day 6: Dynamic memory, Complex class, jagged arrays
├── lab7/                                # Day 7: Constructors/destructors, Stack & Queue
├── lab8/                                # Day 8: Copy constructor, deep copy, RVO
├── lab9/                                # Day 9: Operator overloading, templates, bonus
├── lab10/                               # Day 10: Multi-level inheritance, GeoShape
├── lab11/                               # Day 11: Composition, abstract classes, BGI graphics, lamp
├── lab12/                               # Day 12: Polymorphism, aggregation, heterogeneous shapes
├── .gitignore                           # Git ignore rules for build artifacts
└── README.md                            # Main project repository documentation
```

---

## Quickstart & Build Instructions

### Method 1: Using Code::Blocks (Recommended)
1. Double-click the `.cbp` file inside any lab problem folder (e.g., `lab2/problem3/problem3.cbp`).
2. Press `F9` (Build & Run) or click the green gear-and-play button.

### Method 2: Command Line (MinGW / GCC)
Compile any standalone problem directly with `g++`:

```powershell
# Compile Day 2 Magic Box
g++ -std=c++11 lab2/problem3/main.cpp -o magic_box.exe
./magic_box.exe

# Compile Day 8 Stack with RVO disabled
g++ -std=c++11 -fno-elide-constructors lab8/problem2/main.cpp -o stack_rvo.exe
./stack_rvo.exe

# Compile Day 11 Graphics (requires WinBGIm)
g++ -std=c++11 lab11/problem1/main.cpp -o graphics_app.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
./graphics_app.exe
```

For comprehensive instructions on setting up WinBGIm BGI graphics or configuring Code::Blocks search paths, please consult the **[Setup Guide](docs/SETUP_GUIDE.md)**.

---

## Acknowledgments & Reference Material

- **Institution**: [Information Technology Institute (ITI)](https://iti.gov.eg/), Egypt.
- **Track**: 9-Month Cloud Platform / Intake 47.
- **Reference Literature**: *Object-Oriented Programming in C++* (4th Edition) by Robert Lafore.
