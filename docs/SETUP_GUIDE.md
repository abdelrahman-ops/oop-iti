# Setup & Compilation Guide

This guide explains how to configure, compile, and run the C++ projects in this repository across all 12 labs.

---

## 1. Development Environment

The projects were originally authored using:
- **IDE**: [Code::Blocks](https://www.codeblocks.org/) (v20.03 or later)
- **Compiler**: MinGW-w64 (GCC 8.1.0 or higher with C++11/14/17 support)
- **OS**: Windows (utilizes Windows Console API via `windows.h` and Borland BGI Graphics via `graphics.h`)

---

## 2. Project Organization

Every lab day contains either standalone `.cpp` files (e.g., `lab1/`) or dedicated problem directories (e.g., `lab2/problem1/`, `lab10/problem2/`).
Each problem directory contains:
- `main.cpp`: C++ source file implementing the problem requirements.
- `<problem>.cbp`: Code::Blocks project configuration file.
- `<problem>.layout`: Editor layout metadata.
- `<problem>.depend`: Compiler dependency tree.

---

## 3. Opening & Running in Code::Blocks

1. **Launch Code::Blocks**.
2. Go to **File** $\to$ **Open...** and select the `.cbp` file of the desired problem (e.g., `lab2/problem3/problem3.cbp`).
3. Press **F9** (or click **Build and Run**).
4. The console window will open to display the interactive output.

---

## 4. Compiling via Command Line (GCC / G++)

You can also compile any problem directly using the `g++` compiler from MinGW.

### Basic Compilation:
```powershell
# Example: Day 1 problem 4
g++ -std=c++11 lab1/4.cpp -o lab1_problem4.exe
./lab1_problem4.exe

# Example: Day 7 problem 1 (Complex Class)
g++ -std=c++11 lab7/problem1/main.cpp -o lab7_complex.exe
./lab7_complex.exe
```

### Day 8: Disabling Return Value Optimization (RVO)
In Day 8, students trace the execution of the Copy Constructor. By default, modern compilers perform copy elision / RVO.
To see all copy constructor and destructor calls exactly as demonstrated in class:

#### In Code::Blocks:
1. Open `lab8/problem1/problem1.cbp` or `lab8/problem2/problem2.cbp`.
2. Go to **Project** $\to$ **Build Options...**
3. Select your target (or root project name) on the left.
4. Under the **Compiler settings** tab $\to$ **Other compiler options** sub-tab, add:
   ```text
   -fno-elide-constructors
   ```
5. Click **OK**, then **Rebuild** (Ctrl + F11).

#### In GCC / Command Line:
```powershell
g++ -std=c++11 -fno-elide-constructors lab8/problem2/main.cpp -o lab8_stack.exe
./lab8_stack.exe
```

---

## 5. Console Utility Header: `MyLibrary.h`

Several interactive console programs (menus, text editors, magic box) utilize custom console coordinates and text coloring:
- `lab2/problem2/MyLibrary.h`
- `lab2/problem3/MyLibrary.h`

### Functions Provided:
- `gotoxy(int x, int y)`: Moves the console cursor to specific column ($X$) and row ($Y$) via `SetConsoleCursorPosition`.
- `clrscr()`: Clears the console window via `system("cls")`.
- `textattr(int ForgC)`: Sets console text color attribute via `SetConsoleTextAttribute`.
- `SetColor(int ForgC)`: Preserves current background attribute while changing foreground color.

> [!TIP]
> If building a problem that includes `#include "MyLibrary.h"` outside of Code::Blocks, ensure `MyLibrary.h` is present in the working directory or add `-I lab2/problem2` to your compiler flags.

---

## 6. Graphics Library Configuration (`graphics.h` / WinBGIm)

Labs 11 and 12 (and Lab 11 Bonus: Lamp) utilize the WinBGIm BGI graphics library (`#include <graphics.h>`).

### Required Files:
1. `graphics.h` and `winbgim.h` in the compiler's `include/` directory.
2. `libbgi.a` in the compiler's `lib/` directory.

### Linker Settings in Code::Blocks:
1. Go to **Project** $\to$ **Build Options** $\to$ **Linker settings**.
2. In **Other linker options**, paste:
   ```text
   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
   ```

### Command Line Linker Flag:
```powershell
g++ -std=c++11 lab11/problem1/main.cpp -o lab11_graphics.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```
