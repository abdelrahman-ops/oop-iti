# OOP Concepts & Architectural Reference

This reference synthesizes the key Object-Oriented Programming (OOP) concepts, design patterns, and C++ architectural principles demonstrated across all 12 labs in this repository.

---

## 1. Procedural Programming to Object-Oriented Programming

| Aspect | Procedural (Days 1–5) | Object-Oriented (Days 6–12) |
|---|---|---|
| **Focus** | Functions, procedures, sequence of steps | Objects, state, behavior, invariants |
| **Data & Logic** | Separated: data held in variables/structs, manipulated by standalone functions | Combined: data and member functions encapsulated in `class` |
| **Access Control** | None (`struct` members are public by default) | Information hiding via `private`, `protected`, and `public` |
| **Memory Management** | Manual stack/heap pointers, pass-by-address | RAII (Resource Acquisition Is Initialization), Constructors, Destructors |
| **Extensibility** | Switch-case, if-else ladders, function overloading | Inheritance, Polymorphism, Abstract classes |

---

## 2. Encapsulation & Data Invariants (Days 6–7)

Encapsulation ensures that an object's internal representation cannot be directly altered from outside, preventing invalid states:

```cpp
class Complex {
private:
    float real;
    float img;

public:
    Complex() : real(0), img(0) {}
    Complex(float r, float i) : real(r), img(i) {}

    void setReal(float r) { real = r; }
    float getReal() const { return real; }

    void setImg(float i) { img = i; }
    float getImg() const { return img; }

    Complex add(const Complex& other) const;
    void print() const;
};
```

---

## 3. Dynamic Memory & The Rule of Three (Days 7–9)

When a class manages dynamic resources via raw pointers (such as `int* Stk` in `Stack` or dynamic arrays in `Queue`), adhering to the **Rule of Three** is essential:

```
                ┌─────────────────────────────────┐
                │          Rule of Three          │
                └─────────────────────────────────┘
                   /             │             \
                  /              │              \
                 ▼               ▼               ▼
           Destructor     Copy Constructor   Copy Assignment
           ~Stack()       Stack(const Stack&)  operator=
         (Free Heap)        (Deep Copy)      (Self-assign Guard
                                              & Deep Copy)
```

### The Problem: Shallow Copy Crash
Default memberwise copy duplicates the pointer value, not the heap buffer:
```
Object A: [ Stk: 0x1000 ] ──────┐
                                 ▼
                           [ Heap Buffer ]
                                 ▲
Object B: [ Stk: 0x1000 ] ──────┘
```
When Object B is destroyed, it calls `delete[] Stk`. When Object A is destroyed later, it attempts to delete `0x1000` again, causing a **double-free runtime crash**.

### The Solution: Deep Copy
```cpp
// Deep Copy Constructor
Stack::Stack(const Stack& other) {
    size = other.size;
    tos = other.tos;
    stk = new int[size];
    for (int i = 0; i < tos; i++) {
        stk[i] = other.stk[i];
    }
}

// Deep Copy Assignment Operator
Stack& Stack::operator=(const Stack& other) {
    if (this == &other) return *this; // Self-assignment guard

    delete[] stk; // Free existing resource

    size = other.size;
    tos = other.tos;
    stk = new int[size];
    for (int i = 0; i < tos; i++) {
        stk[i] = other.stk[i];
    }
    return *this;
}
```

---

## 4. Operator Overloading Idioms (Day 9)

Operator overloading allows user-defined classes to integrate seamlessly with native C++ operators:

### Member vs Friend Operators:
- **Member Operator**: Left-hand operand is implicitly `*this`.
  ```cpp
  Complex Complex::operator-(const Complex& c) const; // C1 - C2
  ```
- **Friend Operator**: Used when the left-hand operand is a primitive or foreign type:
  ```cpp
  friend Complex operator-(float scalar, const Complex& c); // 7 - C2
  ```

### Increment / Decrement Semantics:
```cpp
// Prefix: --c (returns reference to modified object)
Complex& Complex::operator--() {
    real--;
    return *this;
}

// Postfix: c-- (dummy int, returns copy of old value)
Complex Complex::operator--(int) {
    Complex temp = *this;
    real--;
    return temp;
}
```

---

## 5. Inheritance & Access Modes (Day 10)

Inheritance models an **"is-a"** relationship. C++ provides three types of inheritance:

| Base Member Visibility | `public` Inheritance | `protected` Inheritance | `private` Inheritance |
|---|---|---|---|
| `public` | `public` in derived | `protected` in derived | `private` in derived |
| `protected` | `protected` in derived | `protected` in derived | `private` in derived |
| `private` | Inaccessible | Inaccessible | Inaccessible |

### Constructor & Destructor Execution Order in Inheritance:
1. **Construction**: Base constructor $\to$ Derived constructor $\to$ Junior derived constructor.
2. **Destruction**: Junior derived destructor $\to$ Derived destructor $\to$ Base destructor (exact reverse order).

---

## 6. Object Relationships: Composition vs Aggregation (Days 11–12)

```
Composition ("has-a", Strong Ownership)
[ Rect ] ◆───────► [ Point (Top-Left) ]
         ◆───────► [ Point (Bottom-Right) ]
- Points are created and destroyed WITH the Rect.

Aggregation ("uses-a", Weak Ownership)
[ Picture ] ◇───────► [ Shape* ] (Externally created shapes)
- Picture receives pointers to shapes; shapes may outlive the Picture.
```

---

## 7. Dynamic Polymorphism & VTables (Days 11–12)

Polymorphism allows treating derived objects uniformly through base class pointers or references.

### Early Binding vs Late Binding:
- **Early Binding (Compile-time)**: Static resolution based on pointer type.
- **Late Binding (Runtime)**: Dynamic dispatch via Virtual Method Table (**VTable**) and Virtual Pointer (**VPTR**).

### Pure Virtual Functions & Abstract Classes:
```cpp
class Shape {
protected:
    int color;
public:
    Shape(int c = 15) : color(c) {}
    virtual void Draw() = 0;  // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor ensures proper cleanup
};
```
- A class containing at least one pure virtual function is an **Abstract Base Class** and cannot be instantiated.
- Concrete derived classes must provide an implementation for `Draw()`.

### Heterogeneous Collections via Polymorphism:
```cpp
Shape* shapes[3];
shapes[0] = new Rect(10, 10, 50, 50);
shapes[1] = new Circle(100, 100, 30);
shapes[2] = new Line(0, 0, 200, 200);

for (int i = 0; i < 3; i++) {
    shapes[i]->Draw(); // Dynamically invokes Rect::Draw(), Circle::Draw(), Line::Draw()
}
```
