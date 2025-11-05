# CPP Modules 💻

A collection of **C++98 exercises** designed to explore **Object-Oriented Programming**, **memory management**, and **software design principles** through incremental learning.

## 📋 Table of Contents

* [About](#-about)
* [Modules Overview](#-modules-overview)
* [Features](#-features)
* [Prerequisites](#-prerequisites)
* [Installation](#-installation)
* [Compilation](#-compilation)
* [Usage](#-usage)

---

## 🎯 About

The **C++ Modules** are a progressive series of projects aimed at mastering **C++98 fundamentals**.
Each module focuses on a specific concept(class syntax, polymorphism, templates, and memory handling).

**Goals:**

* Understand **object-oriented design** (encapsulation, inheritance, polymorphism)
* Practice **clean, modular, and reusable** code design
* Follow the **42 Norm and C++98 standards**

---

## 🧩 Modules Overview

| Module    | Focus                | Concepts                                             |
| :-------- | :------------------- | :--------------------------------------------------- |
| **CPP00** | Basics               | Namespaces, classes, member functions, stdio streams |
| **CPP01** | Memory & References  | Allocation, pointers, references, switch statements  |
| **CPP02** | Ad-hoc polymorphism  | Operator overloading, Orthodox Canonical form        |
| **CPP03** | Inheritance          | Base/derived classes, constructors chaining          |
| **CPP04** | Subtype Polymorphism | Abstract classes, virtual functions, interfaces      |
| **CPP05** | Exceptions           | Error handling, exceptions hierarchy                 |
| **CPP06** | Casting              | Static, dynamic, reinterpret, const cast             |
| **CPP07** | Templates            | Templates containers                                 |
| **CPP08** | STL concepts         | Iterators, algorithms                                |

---

## ✨ Features

### Core Features

* **C++98 compliant**: strict adherence to the early C++ standard
* **Fully modular**: each module is standalone
* **Incremental complexity**: new topics build on previous ones
* **Clean Makefiles** for easy compilation
* **Test mains** to visualize object behavior

---

## 🔧 Prerequisites

* **C++98 compiler** (`c++`)
* **Make**
* **Linux** environment

---

## 🚀 Installation

Clone the repository:

```bash
git clone git@github.com:chrstnhu/cpp-modules.git && cd cpp-modules
```

---

## 🧱 Compilation

Compile any module individually:

```bash
cd CPP03
make
```

To clean object files:

```bash
make clean
```

To remove binaries:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

---

## 💻 Usage

Each module contains multiple exercises with their own `main.cpp`.
To run a test:

```bash
./ex00
```

Example output:

```
Constructor called
Copy constructor called
Assignment operator called
Destructor called
```

