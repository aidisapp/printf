# Custom Printf Project

A custom implementation of the printf function in C, providing a simplified version of the standard printf functionality.

## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project aims to create a custom printf function in C, allowing users to format and print output in a way similar to the standard printf function in the C Standard Library. The implementation is kept simple for educational purposes.

## Project Structure

The project is structured as follows:

- **src/:** Contains the source code for the custom printf function.
- **include/:** Contains the header file defining the function signature and any necessary macros or constants.
- **tests/:** Includes test cases to ensure the correct functionality of the custom printf function.
- **main.c:** A file for running example code or testing the custom printf function.
- **CMakeLists.txt:** Defines the build process using CMake (optional).

## Getting Started

To get started with the project, follow these steps:

1. Clone the repository:

   ```
   bash
   git clone https://github.com/your-username/custom-printf.git
   cd custom-printf
   ```

2. Build the project (if using CMake)
```
  mkdir build
  cd build
  cmake ..
  make
```

## Usage 
```
#include "custom_printf.h"

int main() {
    my_printf("This is a custom printf function: %d\n", 42);
    return 0;
}
```

## Testing 
```
gcc test_custom_printf.c -o test_custom_printf
```
