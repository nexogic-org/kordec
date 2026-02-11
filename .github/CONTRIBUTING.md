# Contributing to Kordec

Thank you for your interest in contributing to Kordec! We welcome all contributions, including bug reports, feature requests, and code changes.

## How to Contribute

### 1. Reporting Bugs
- Use the **Bug report** issue template.
- Provide a clear description and steps to reproduce.

### 2. Suggesting Features
- Use the **Feature request** issue template.
- Explain the motivation and proposed solution.

### 3. Submitting Pull Requests
- Fork the repository.
- Create a new branch for your changes.
- Ensure your code follows the project's coding style (C99 standard, clear naming).
- Submit a Pull Request with a clear description of the changes.

## Coding Standards
- Use `4 spaces` for indentation.
- Follow the existing naming conventions (snake_case for functions and variables).
- Document new functions and complex logic.

## Build and Test
Always ensure the project builds successfully and tests pass before submitting a PR:
```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest
```
