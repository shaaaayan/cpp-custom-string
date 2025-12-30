# cpp-custom-string

Custom C++ string class implementing dynamic memory management and operator overloading.

## Overview
This project implements a custom `MyString` class in C++ to demonstrate:
- Dynamic memory management (Rule of Three)
- Operator overloading
- Exception safety
- Deep copying and resource cleanup

## Key Features
- Copy constructor and copy assignment operator
- Safe bounds checking with exceptions
- Overloaded operators (`+=`, `<<`, `==`, `+`)
- Memory safety validated using Valgrind (Linux environment)

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra -Werror RoverTest.cpp Rover.cpp MyString.cpp -o rover
./rover
