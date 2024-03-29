# Logtard Logging Library

The Logtard Logging Library provides a flexible and easy-to-use logging system for C++ applications. It supports multiple log levels and can be extended to log messages to various outputs, with the default implementation focusing on console output with colored log levels for enhanced readability.

## Features

- **Multiple Log Levels:** Supports `DEBUG`, `INFO`, `WARNING`, `ERROR`, and `CRITICAL` log levels to suit different verbosity needs.
- **Colored Output:** Enhances log readability in the console with colored log levels.
- **Extensible Design:** Designed with extensibility in mind, allowing for the implementation of additional loggers (e.g., file logger, network logger) by extending the base `Logger` class.
- **Macro-based Logging:** Simplifies logging syntax with macros for different log levels.

## Getting Started

### Prerequisites

- C++11 compiler (GCC, Clang, MSVC, etc.)
- Make (optional for building examples)
- CMake (optional)

### Installation

1. Clone the repository:

```bash
git clone https://github.com/araujo88/logtard.git
cd logtard
```

2. Include the `logtard` library in your C++ project. There's no need to build `logtard` separately as it's header-only. Just include the relevant headers in your project.

### Usage

1. Include the `ConsoleLogger` in your C++ file:

```cpp
#include "console_logger.hpp"
```

2. Create an instance of `ConsoleLogger` and use the provided macros to log messages:

```cpp
logtard::ConsoleLogger logger;
LOG_INFO(logger, "This is an informational message.");
LOG_ERROR(logger, "This is an error message.");
```

## Building project with CMake

```cpp
cmake -S . -B build
cmake --build build
```

## Extending Logtard

To create a custom logger, extend the `Logger` class and implement the `log` method. Refer to `console_logger.hpp` and `console_logger.cpp` for implementation examples.

## Contributing

Contributions are welcome! Please feel free to submit pull requests, report bugs, and suggest features.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
