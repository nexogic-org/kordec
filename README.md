<center><h1>Nexogic Kordec</h1></center>

---

<p align="center">
  <b>⚠️ Work In Progress (WIP) ⚠️</b><br>
  <i>This project is currently in a very early stage of development. Any changes, features, or implementations made during this phase do not guarantee stability or usability. The authors assume no responsibility for any consequences arising from the use of the code in this repository.</i>
</p>

---

> Kordec is a programming language and its accompanying workflow, featuring elegant syntax and full support for Object-Oriented Programming (OOP).
>
> As a refactored successor to Korelin, it maintains most backward compatibility at the syntax level but transforms procedural code structures into a programming model based on classes and message passing by enforcing a pure object-oriented paradigm.

<p align="center">
  <img src="kordec.svg" alt="Kordec LOGO" width="80">
  <br>
  <b>Kordec LOGO</b>
  <br>
  <a href="https://github.com/nexogic-org/kordec/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-Apache_2.0-blue.svg" alt="License"></a>
  <a href="https://github.com/nexogic-org/kordec"><img src="https://img.shields.io/badge/GitHub-nexogic--org%2Fkordec-lightgrey?logo=github" alt="GitHub"></a>
  <img src="https://img.shields.io/github/stars/nexogic-org/kordec?style=social" alt="Stars">
  <img src="https://img.shields.io/badge/v0.1.0-lightgrey" alt="Version">
  <img src="https://img.shields.io/badge/Author-Nexogic-purple" alt="Author">
</p>


## Core Features

- **High-Performance Runtime**: Powered by the custom **Vector Engine** with integrated **Jitter JIT** compilation, ensuring exceptional execution efficiency for complex logic and large-scale data.
- **Pure Object-Oriented (Pure OOP)**: Enforces all code to be built on classes and objects, eliminating the clutter of global functions and procedural structures.
- **Message Passing Model**: Inspired by Smalltalk, objects interact by sending messages, enhancing decoupling and flexibility.
- **Modern Workflow**: Built-in CLI tools for project initialization, compilation, packaging, and dependency management.
- **C Extension Support**: Provides low-level API interfaces, allowing developers to write high-performance extension modules in C for Kordec.

## Project Structure

```text
src/
├── api/              # Foreign Function Interface (FFI)
├── cli/              # CLI interaction and toolchain implementation
├── codegen/          # Target code generator
├── ir/               # Vectorized Intermediate Representation (Vector IR)
├── lexer/            # High-efficiency lexer
├── optimizer/        # Code optimizer
├── parser/           # Parser and AST construction
├── preprocessing/    # Package management and preprocessor
├── runtime/          # Runtime support
│   ├── gc/           # Incremental Garbage Collector
│   └── stdlib/       # Standard Library (Console, IO, Net, JSON, Math, etc.)
├── semantic/         # Semantic analysis and type checking
├── vector/           # Core execution engine
│   └── jitter/       # Jitter JIT Compiler
├── const.h           # Global constant definitions
└── main.c            # Entry point
```

## Quick Start

```kordec
// main.kd
import console;

class test {
    public static void main() {
        console.println("Hello, World!");
    }
}
```

### Build Project

Ensure CMake and a C compiler (like GCC or MSVC) are installed in your environment:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Run Kordec

```bash
# Run script
./kordec run main.kd

# View help information
./kordec help

# Initialize a new project
./kordec init my_project
```

## Deep Optimization for Korelin's Core Defects

As a successor, Kordec has undergone low-level refactoring and optimization for the system-level defects exposed in Korelin's engineering practice:

- **Modular Package Management Addressing Failure**
  - **Defect**: Korelin often failed in symbol resolution for complex nested package references due to relative path calculation offsets.
  - **Optimization**: Introduced a deterministic package search path algorithm and absolute path caching mechanism, supporting recursive dependency resolution to ensure stability in multi-level project structures.
- **VM Memory Safety and GC Performance Bottleneck**
  - **Defect**: Korelin's VM was prone to stack overflow during deep recursion or large data processing, and its GC response was delayed for massive transient objects.
  - **Optimization**: Refactored the VM core scheduler, optimized call stack memory layout, and introduced an improved Incremental Mark-and-Sweep GC algorithm, significantly enhancing memory throughput in high-concurrency scenarios.
- **Instability of C Extension Interface (FFI)**
  - **Defect**: The original C extension mechanism lacked strict type constraints and boundary checks, leading to frequent crashes in native module calls.
  - **Optimization**: Standardized the semantic standards for native extensions, providing lower-level memory access safety barriers and automated type mapping mechanisms, reducing maintenance costs for the standard library and third-party extensions.
- **Architectural Chaos from Procedural Coding Patterns**
  - **Defect**: Procedural code is difficult to decouple in large-scale engineering, leading to fragmented logic and maintenance challenges.
  - **Optimization**: Enforced the "Everything is an Object" pure OOP paradigm, reshaping business logic through class abstraction and Message Passing mechanisms, fundamentally improving engineering maintainability.

## Roadmap

- [x] Core VM architecture refactoring
- [x] Pure OOP syntax parsing support
- [x] Basic CLI toolchain implementation
- [x] JIT (Just-In-Time) engine depth optimization
- [ ] Cross-platform graphical standard library support
- [ ] Automated package distribution platform (Kordec Registry)

<p align="center">
  <img src="https://nexogic.org/favicon.ico" alt="Nexogic Logo" width="16" style="vertical-align: middle;">
  <br>
  Copyright (c) 2026 Nexogic. Released under Apache 2.0 License.
</p>
