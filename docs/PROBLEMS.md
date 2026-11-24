# ITI OOP in C++: Comprehensive Problems & Lab Documentation

This document provides a complete, structured catalog of all 12 lab assignments from the **ITI (Information Technology Institute) 9-Month Cloud Platform Track - Object-Oriented Programming in C++ Course**.

Each section details the daily lab objectives, the full set of required and optional problem statements (derived directly from the lab task specifications), technical implementation notes, key algorithms, edge cases, and links to the source files in this repository.

---

## Table of Contents

- [Day 1: Fundamentals of C/C++ & Console I/O](#day-1-fundamentals-of-cc--console-io)
- [Day 2: Control Flow, Loops, Console Positioning & Algorithms](#day-2-control-flow-loops-console-positioning--algorithms)
- [Day 3: Arrays, Matrices, Extended Keys & Highlight Menus](#day-3-arrays-matrices-extended-keys--highlight-menus)
- [Day 4: Modular Functions, Structs, CRUD Systems & Recursion](#day-4-modular-functions-structs-crud-systems--recursion)
- [Day 5: Pointers, Memory Addressing, References & Text Editors](#day-5-pointers-memory-addressing-references--text-editors)
- [Day 6: Dynamic Memory, Classes, Encapsulation & Jagged Arrays](#day-6-dynamic-memory-classes-encapsulation--jagged-arrays)
- [Day 7: Constructors, Destructors, Overloading, Stack & Queue](#day-7-constructors-destructors-overloading-stack--queue)
- [Day 8: Deep Copy, Copy Constructors & Return Value Optimization (RVO)](#day-8-deep-copy-copy-constructors--return-value-optimization-rvo)
- [Day 9: Operator Overloading, Static Members & Generic Templates](#day-9-operator-overloading-static-members--generic-templates)
- [Day 10: Inheritance, Access Modifiers & Class Hierarchies](#day-10-inheritance-access-modifiers--class-hierarchies)
- [Day 11: Object Composition, Abstract Classes & BGI Graphics](#day-11-object-composition-abstract-classes--bgi-graphics)
- [Day 12: Polymorphism, Aggregation & Heterogeneous Collections](#day-12-polymorphism-aggregation--heterogeneous-collections)

---

## Day 1: Fundamentals of C/C++ & Console I/O

### Overview
Introduces C++ syntax, standard input/output streams (`cin`, `cout`), standard format specifiers, ASCII character representation, and basic arithmetic operations.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Hello World | Required | [`lab1.cpp`](../lab1/lab1.cpp) / [`lab1.c`](../lab1/lab1.c) | Prints `"Hello world!"` to console output. |
| 2 | ASCII Representation | Required | [`2.cpp`](../lab1/2.cpp) | Reads a character from user and prints its integer ASCII value. |
| 3 | Float Printing | Required | [`3.cpp`](../lab1/3.cpp) | Reads a floating-point number from user and prints it. |
| 4 | Integer Addition | Required | [`4.cpp`](../lab1/4.cpp) | Reads two integers and prints their sum. |
| 5 | Hexadecimal Output | Optional | [`5.cpp`](../lab1/5.cpp) | Reads an integer and outputs its hexadecimal representation using stream manipulators (`hex`). |
| 6 | Simple Calculator | Optional | [`6.cpp`](../lab1/6.cpp) | Takes two integers and calculates sum, subtraction, product, and quotient. |
| 7 | Quotient & Remainder | Optional | [`7.cpp`](../lab1/7.cpp) / [`7.c`](../lab1/7.c) | Computes quotient (`/`) and remainder (`%`) between two integers. |

### Technical Highlights
- **ASCII Cast**: Character types are internally stored as integer byte values; casting `(int)ch` or assigning to an integer extracts the ASCII code.
- **Hexadecimal Formatting**: Outputting in hexadecimal is achieved via `std::hex` manipulator or `%x` in C stdio.

---

## Day 2: Control Flow, Loops, Console Positioning & Algorithms

### Overview
Focuses on conditional branches, iterative loops (`while`, `for`, `do-while`), Win32 console cursor positioning (`gotoxy`), and algorithmic problem solving (Magic Square).

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Sum Exceeding 100 | Required | [`problem1/main.cpp`](../lab2/problem1/main.cpp) | Continuously reads numbers until the cumulative sum strictly exceeds 100. |
| 2 | Simple 3-Choice Menu | Required | [`problem2/main.cpp`](../lab2/problem2/main.cpp) | Text-based menu with choices (e.g., Add, Edit, Exit) responding to user character/number input. |
| 3 | Magic Box (NxN) | Required | [`problem3/main.cpp`](../lab2/problem3/main.cpp) | Generates and visually prints an $N \times N$ magic square for odd $N$ using coordinate positioning. |
| 4 | Largest of Three Numbers | Optional | [`problem4/main.cpp`](../lab2/problem4/main.cpp) | Identifies the maximum among three numbers using conditional operators. |
| 5 | Multiplication Table | Optional | [`problem5/main.cpp`](../lab2/problem5/main.cpp) | Generates multiplication tables formatted as `1 * X = X`, `2 * X = 2X`, etc. |
| 6 | Alphabet Character Check | Optional | [`problem6/main.cpp`](../lab2/problem6/main.cpp) | Checks if an input character falls within `[a-z]` or `[A-Z]`. |
| 7 | Word & Alphabet Counter | Optional | [`problem7/main.cpp`](../lab2/problem7/main.cpp) | Counts alphabetic characters and words in an input sentence without string libraries. |

### Technical Highlights: The Magic Box Algorithm
For an odd integer $N$:
1. Place number `1` at row $1$, column $\lceil N / 2 \rceil$.
2. For each successive number $k$ from $2$ to $N^2$:
   - If $(k - 1) \pmod N == 0$: move down one row ($row + 1$, same column).
   - Otherwise: move up one row ($row - 1$) and right one column ($col + 1$).
   - Wrap around if row drops below $1$ (wrap to $N$) or column exceeds $N$ (wrap to $1$).
3. Coordinates are drawn directly using Win32 API cursor functions (`gotoxy`).

---

## Day 3: Arrays, Matrices, Extended Keys & Highlight Menus

### Overview
Covers 1D and 2D arrays, matrix arithmetic, keyboard scan codes (normal vs extended keys via `getch()`), ANSI/Windows console coloring, and jagged arrays without pointers.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Min & Max in Array | Required | [`problem1/main.cpp`](../lab3/problem1/main.cpp) | Iterates through a 1D array to find the minimum and maximum elements in a single pass. |
| 2 | 2D Array Statistics | Required | [`problem2/main.cpp`](../lab3/problem2/main.cpp) | 3 students $\times$ 4 subjects: calculates total score per student (row sum) and average score per subject (col average). |
| 3 | Matrix Addition | Required | [`problem3/main.cpp`](../lab3/problem3/main.cpp) | Computes matrix sum $C_{ij} = A_{ij} + B_{ij}$ and prints the resulting matrix. |
| 4 | Key Code Inspector | Required | [`problem4/main.cpp`](../lab3/problem4/main.cpp) | Distinguishes normal keys (single byte) from extended keys (two bytes: `0` or `224` prefix) using `getch()`. |
| 5 | Highlight Menu with Arrows | Required | [`problem5/main.cpp`](../lab3/problem5/main.cpp) | Interactive console menu navigable via Up/Down arrow keys, Home, End, Enter, and Esc. |
| 6 | Character Frequency | Optional | [`problem6/main.cpp`](../lab3/problem6/main.cpp) | Computes frequency histogram of all characters in an input string. |
| 7 | Alphabet Filter | Optional | [`problem7/main.cpp`](../lab3/problem7/main.cpp) | Strips non-alphabetic characters (digits, symbols, spaces) from a string in place. |
| 8 | Custom String Length | Optional | [`problem8/main.cpp`](../lab3/problem8/main.cpp) | Determines the length of a string without calling `strlen()` or `.size()`. |
| 9 | Jagged Array (No Pointers) | Optional | [`problem9/main.cpp`](../lab3/problem9/main.cpp) | Simulates a jagged array using fixed 2D storage and a companion array storing row lengths. |

### Technical Highlights: Extended Key Handling
- Normal ASCII keys emit a single byte through `getch()`.
- Extended keys (arrows, function keys, Delete, Insert, PageUp/Down) emit two bytes:
  - First read returns `0` or `224` (or `-32`).
  - Second immediate read returns the extended virtual key code (e.g., Up arrow is `72`, Down arrow is `80`, Home is `71`, End is `79`).

---

## Day 4: Modular Functions, Structs, CRUD Systems & Recursion

### Overview
Introduces procedural abstraction via functions, parameter passing, structured data (`struct`), nested data structures, full CRUD console menus, and recursion.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Largest Number Function | Required | [`problem1/main.cpp`](../lab4/problem1/main.cpp) | `int findLargest(int a, int b, int c)` tested via debugger step-into. |
| 2 | Single Employee Struct | Required | [`problem2/main.cpp`](../lab4/problem2/main.cpp) | `struct Employee { id, name, salary, bonus, deduction }` computing net salary. |
| 3 | Array of 5 Employees | Required | [`problem3/main.cpp`](../lab4/problem3/main.cpp) | Manages an array of 5 `Employee` records; reads data and prints all summaries. |
| 4 | Modular Employee Functions | Required | [`problem4/main.cpp`](../lab4/problem4/main.cpp) | Decomposes employee management into `Employee AddNewEmployee()` and `void DisplayEmployee(Employee)`. |
| 5 | Full CRUD Highlight Menu | Required | [`problem5/main.cpp`](../lab4/problem5/main.cpp) | Interactive arrow-driven menu: **New**, **Display**, **Display All**, **Delete**, **Delete All**, **Exit**. |
| 6 | Recursive Power | Required | [`problem6/main.cpp`](../lab4/problem6/main.cpp) | `int power(int base, int exp)` computed recursively ($base \times power(base, exp-1)$). |
| 7 | Indexed Insert & Active Flag | Optional | [`problem7/main.cpp`](../lab4/problem7/main.cpp) | Adds `bool isExisted = true` flag; allows inserting at specific indices and displays only active records. |
| 8 | Department with Nested Employees | Optional | [`problem8/main.cpp`](../lab4/problem8/main.cpp) | `struct Dept` containing ID, name, and an embedded array of `Employee` structs. |

---

## Day 5: Pointers, Memory Addressing, References & Text Editors

### Overview
Mastering memory concepts: stack memory addresses, pointer dereferencing, pass-by-value vs pass-by-address vs pass-by-reference, array-pointer equivalence, and building a console line editor.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Triple Swap Implementations | Required | [`problem1/main.cpp`](../lab5/problem1/main.cpp) | Swaps two integers using 3 distinct paradigms: Pass-by-Value, Pass-by-Address (`int*`), and Pass-by-Reference (`int&`). |
| 2 | Array Traversal via Pointers | Required | [`problem2/main.cpp`](../lab5/problem2/main.cpp) | Reads array with array notation `arr[i]`, computes sum and displays with pointer notation `*(ptr + i)`. |
| 3 | Multi-Value Return Function | Required | [`problem3/main.cpp`](../lab5/problem3/main.cpp) | `void Calculate(int X, int Y, int* SumPtr, int* SubPtr, int* MultipPtr, int* DivPtr)` updating caller variables. |
| 4 | Single-Line Text Editor | Required | [`problem4/main.cpp`](../lab5/problem4/main.cpp) | Console line editor with navigation (`<-`, `->`, Home, End), text insertion, Enter to submit, and Esc to cancel. |

### Technical Highlights: The 3 Swap Paradigms
```cpp
// 1. Pass by Value (no effect on caller's variables)
void swapByVal(int a, int b) { int temp = a; a = b; b = temp; }

// 2. Pass by Address / Pointer (modifies memory directly)
void swapByPtr(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }

// 3. Pass by Reference (C++ alias semantics, cleaner syntax)
void swapByRef(int& a, int& b) { int temp = a; a = b; b = temp; }
```

---

## Day 6: Dynamic Memory, Classes, Encapsulation & Jagged Arrays

### Overview
Transitions from procedural C into Object-Oriented Programming (OOP) in C++. Covers heap allocation (`new` / `delete`), avoiding dangling stack pointers, dynamic 2D arrays, and designing the foundational `Complex` number class.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Returning Dynamically Allocated Array | Required | [`problem1/main.cpp`](../lab6/problem1/main.cpp) | Contrasts returning a local fixed stack array (dangling pointer bug) with returning a heap-allocated array (`new int[size]`). |
| 2 | Dynamic Employee Menu System | Required | [`problem2/main.cpp`](../lab6/problem2/main.cpp) | Employee CRUD menu with dynamic array sizing (`new Employee[size]`) chosen by the user at runtime. |
| 3 | Dynamic 2D Array (Pointer-to-Pointer) | Required | [`problem3/main.cpp`](../lab6/problem3/main.cpp) | Allocates $N \times M$ matrix dynamically using `int** arr = new int*[students];` for degrees and averages. |
| 4 | Foundational `Complex` Class | Required | [`problem4/main.cpp`](../lab6/problem4/main.cpp) | Encapsulates `real` and `img` with getters, setters, standalone/member arithmetic, and formatted output. |
| 5 | Dynamic Line Editor with Delete/Backspace | Optional | [`problem5/main.cpp`](../lab6/problem5/main.cpp) | Extends line editor with dynamic character buffer (`new char[size]`), Backspace (left delete), and Delete (in-place delete). |
| 6 | Dynamic Jagged Array | Optional | [`problem6/main.cpp`](../lab6/problem6/main.cpp) | Dynamic pointer-to-pointer array where each student row has a custom, independent subject count. |

### Technical Highlights: Complex Number Print Rules
Formatting must handle mathematical sign cases cleanly:
- $real = 5, img = 3 \implies 5 + 3i$
- $real = 5, img = -3 \implies 5 - 3i$ (avoids `5+-3i`)
- $real = 5, img = 0 \implies 5$ (omits imaginary term)
- $real = 0, img = 3 \implies 3i$ (omits real term)
- $real = 0, img = 0 \implies 0$

---

## Day 7: Constructors, Destructors, Overloading, Stack & Queue

### Overview
Core class lifecycle mechanics: Default constructors, parameterized constructors, destructors, the `this` pointer, scope resolution `::`, function overloading, and building dynamic LIFO/FIFO data structures.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | `Complex` Lifecycle & Member Functions | Required | [`problem1/main.cpp`](../lab7/problem1/main.cpp) | Constructors, destructor, setters, getters, `Addcomplex`, `SubComplex` using `::`, tracing constructor/destructor counts. |
| 2 | Function Overloading Suite | Required | [`problem2/main.cpp`](../lab7/problem2/main.cpp) | Overloads `Add` for: 2 integers, 3 integers, 3 characters (concatenation), and 2 strings (`char*`). |
| 3 | Dynamic `Stack` Class (LIFO) | Required | [`problem3/main.cpp`](../lab7/problem3/main.cpp) | Encapsulated integer stack: `int* Stk`, `Tos`, `Size`, `Push()`, `Pop()`, `Peak()`, `Reverse()`, `PrintStack()`. |
| 4 | Dynamic `Queue` Class (FIFO) | Required | [`problem4/main.cpp`](../lab7/problem4/main.cpp) | Encapsulated integer queue: circular queue and shifting queue variants with `EnQueue()`, `DeQueue()`, `IsFull()`, `IsEmpty()`. |

### Technical Highlights: Constructor / Destructor Tracing
When evaluating expressions like:
```cpp
Complex C1(3, 4), C2(5), C3;
C3 = C1.Addcomplex(C2);
```
Students observe:
- Parameterized constructors called for `C1` and `C2`.
- Default constructor called for `C3`.
- Pass-by-value triggers copy creation; returning by value creates temporary objects.
- Destructors fire in reverse order of construction when objects exit scope.

---

## Day 8: Deep Copy, Copy Constructors & Return Value Optimization (RVO)

### Overview
Investigates the danger of default shallow copying with pointer members (aliasing, double-free runtime crash) and implements the **Deep Copy Constructor**. Explores compiler Return Value Optimization (RVO).

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | `Complex` with Copy Constructor | Required | [`problem1/main.cpp`](../lab8/problem1/main.cpp) | Explicit copy constructor: traces execution and object count during member calls with/without copy constructor. |
| 2 | `Stack` with Deep Copy Constructor | Required | [`problem2/main.cpp`](../lab8/problem2/main.cpp) | Dynamically allocates fresh heap buffer inside `Stack(const Stack& S)` to prevent shared pointer aliasing and memory corruption. |

### Technical Highlights: The 3 Canonical Copy Constructor Triggers
1. **Pass-by-value to a function**:
   ```cpp
   void viewContent(Stack S); // S is created via Copy Constructor
   ```
2. **Return-by-value from a function**:
   ```cpp
   Stack Reverse(); // Returned Stack creates temporary copy unless elided
   ```
3. **Explicit object initialization from another**:
   ```cpp
   Stack S3(S1); // S3 initializes its state from existing S1
   ```

### Return Value Optimization (RVO)
Modern C++ compilers eliminate unnecessary copying via RVO / copy elision. To observe the exact sequence of copy constructor invocations as taught in the lab:
- In Code::Blocks: `Settings` $\to$ `Compiler` $\to$ `Other Compiler Options`: add `-fno-elide-constructors`.

---

## Day 9: Operator Overloading, Static Members & Generic Templates

### Overview
Transforms C++ classes into expressive, user-defined types using comprehensive operator overloading, static class-level tracking, and generic programming via C++ Templates.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Default Arguments | Required | [`problem1/main.cpp`](../lab9/problem1/main.cpp) | `int SUM(int x = 10, int y = 20, int z = 30)` tested with 0, 1, 2, and 3 arguments. |
| 2 | Comprehensive `Complex` Operators | Required | [`problem2/main.cpp`](../lab9/problem2/main.cpp) | Overloads `-` (binary), `7 - C`, `C - 7`, `-=`, prefix/postfix `--`, comparisons (`==`, `!=`, `<`, `<=`, `>`, `>=`), cast `(int)`, subscript `['R']`/`['I']`. |
| 3 | `Stack` Operators & Static Counter | Required | [`problem3/main.cpp`](../lab9/problem3/main.cpp) | Deep copy assignment `operator=`, stack concatenation `operator+`, subscript `operator[]`, and `static int counter` with `getCounter()`. |
| 4 | `Date` Class with Operators | Required | [`problem4/main.cpp`](../lab9/problem4/main.cpp) | Date difference `-`, offset addition `+ days`, prefix/postfix `++`, equality `==`, cast to int, subscript `['d']`, `['m']`, `['y']`. |
| 5 | Function & Class Templates | Required | [`problem5/main.cpp`](../lab9/problem5/main.cpp) | Generic `Swap<T>(T&, T&)` and generic `Stack<T>` tested across `int`, `char`, and `Complex`. |
| Bonus | Stream I/O Overloading | Bonus | [`bonus/main.cpp`](../lab9/bonus/main.cpp) | Stream insertion `operator<<` (`cout << C1`) and stream extraction `operator>>` (`cin >> C1`). |

### Key Overloading Signatures
```cpp
// Member binary arithmetic
Complex operator-(const Complex& c) const;

// Non-member friend arithmetic (for symmetric scalar operations: 7 - C)
friend Complex operator-(float scalar, const Complex& c);
friend Complex operator-(const Complex& c, float scalar);

// Prefix vs Postfix
Complex& operator--();    // Prefix: --c (returns by reference)
Complex operator--(int);   // Postfix: c-- (dummy int parameter, returns old value by copy)

// Stream I/O operators
friend ostream& operator<<(ostream& out, const Complex& c);
friend istream& operator>>(istream& in, Complex& c);
```

---

## Day 10: Inheritance, Access Modifiers & Class Hierarchies

### Overview
Object-oriented inheritance: Base and Derived classes, access specifiers (`private`, `protected`, `public`), constructor/destructor execution chains in hierarchies, method overriding, and solving dimension coupling using Protected Inheritance.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Multi-Level Inheritance Chain | Required | [`problem1/main.cpp`](../lab10/problem1/main.cpp) | `Base` $\to$ `Derived` $\to$ `Derived_Junior`. Traces `x`, `y`, `z`, `m` members, constructor/destructor order, and progressive `sum()` overriding. |
| 2 | `GeoShape` Hierarchy | Required | [`problem2/main.cpp`](../lab10/problem2/main.cpp) | Base `GeoShape` (`dim1`, `dim2`), derived `Rectangle`, `Square`, `Circle`, `Triangle`, overriding `CalcArea()`. |
| 3 | Protected Inheritance for Shape Invariants | Required | [`problem3/main.cpp`](../lab10/problem3/main.cpp) | Uses protected inheritance on `Square` and `Circle` to prevent external distortion of equal dimensions (`setDim1 != setDim2`). |

### Technical Highlights: Protected Inheritance for Geometric Invariants
In standard public inheritance, a `Square` inherits `setDim1(float)` and `setDim2(float)` publicly, allowing callers to create an invalid square where width $\neq$ height. By inheriting `protected`:
```cpp
class Square : protected GeoShape {
public:
    Square(float side) : GeoShape(side, side) {}
    void setSide(float s) { setDim1(s); setDim2(s); }
    float getSide() { return getDim1(); }
    float CalcArea() { return GeoShape::CalcArea(); }
};
```
The caller can only use `setSide()`, preserving the geometric invariant.

---

## Day 11: Object Composition, Abstract Classes & BGI Graphics

### Overview
Object Composition ("has-a" relationship), Borland BGI Graphics rendering, Pure Virtual Functions, Abstract Base Classes, and polymorphic base pointer assignments.

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Composition with Graphics | Required | [`problem1/main.cpp`](../lab11/problem1/main.cpp) | `Point` composition inside `Rect`, `Circle`, and `Line` rendered via Borland BGI (`graphics.h`). |
| 2 | Pure Virtual Functions & Abstract Classes | Required | [`problem2/main.cpp`](../lab11/problem2/main.cpp) | Converts `GeoShape` into an abstract class via `virtual float CalcArea() = 0;`, preventing direct instantiation. |
| 3 | Base Pointer to Child Instances | Required | [`problem3/main.cpp`](../lab11/problem3/main.cpp) | Assigns derived instances (`Derived`, `Derived_Junior`) to `Base*` pointers; contrasts static early binding with virtual late binding. |
| Bonus | Interactive Graphic Lamp | Bonus | [`bonus/main.cpp`](../lab11/bonus/main.cpp) | Graphical lamp visualization composed of geometric primitives (`Point`, `Rect`, `Circle`, `Line`) with toggleable lighting states. |

### Technical Highlights: Composition vs Inheritance
- Composition represents a **"has-a"** relationship (a `Rect` has two `Point` instances defining top-left and bottom-right corners).
- Constructors of embedded member objects execute **before** the container class constructor body.

---

## Day 12: Polymorphism, Aggregation & Heterogeneous Collections

### Overview
The pinnacle of C++ OOP: dynamic runtime polymorphism, dynamic dispatch via virtual method tables (VTables), Aggregation vs Composition, abstract `Shape` hierarchies, and managing heterogeneous collections of shapes through arrays of base pointers (including jagged arrays).

### Problem Catalog

| # | Task | Category | Source File | Description |
|---|------|----------|-------------|-------------|
| 1 | Polymorphic Shape Area Summation | Required | [`problem1/main.cpp`](../lab12/problem1/main.cpp) | Function `sumOfAllShapesArea(GeoShape* p1, GeoShape* p2, GeoShape* p3, GeoShape* p4)` computing combined area via polymorphic calls. |
| 2 | Composition vs Aggregation in Graphics | Required | [`problem2/main.cpp`](../lab12/problem2/main.cpp) | `Picture` class managing shapes and colors, illustrating differences in ownership lifecycle between Composition and Aggregation. |
| 3 | Heterogeneous Shape Array with Pure Virtual `Draw()` | Required | [`problem3/main.cpp`](../lab12/problem3/main.cpp) | `Shape` base class with `virtual void Draw() = 0`; `Picture` simplified to store an array of base pointers (`Shape* arr[]`) calling `Draw()` polymorphically. |
| 4 | Jagged Array of Polymorphic Shapes | Required | [`problem4/main.cpp`](../lab12/problem4/main.cpp) | Dynamically allocates a jagged collection of shape pointers rendered through polymorphic base dispatch. |

### Technical Highlights: Dynamic Polymorphism & VTables
```cpp
class Shape {
protected:
    int color;
public:
    Shape(int c = 15) : color(c) {}
    virtual void Draw() = 0; // Pure virtual function -> Abstract Base Class
    virtual ~Shape() {}       // Virtual destructor ensures proper cleanup
};

class Picture {
private:
    Shape** shapes;
    int count;
public:
    Picture(Shape** s, int c) : shapes(s), count(c) {}
    void Paint() {
        for (int i = 0; i < count; i++) {
            shapes[i]->Draw(); // Resolved at runtime via VTable
        }
    }
};
```
Through dynamic binding, `Picture` remains fully decoupled from concrete shapes (`Circle`, `Rect`, `Line`), adhering to the **Open-Closed Principle (OCP)**.
