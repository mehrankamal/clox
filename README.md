## CLox

`CLox` is a compiler frontend and virtual machine implementation for running the [Lox](https://craftinginterpreters.com/the-lox-language.html) language, as described in the [*Crafting Interpreters*](https://craftinginterpreters.com/) book. It is written in C and follows the structure laid out in the book.

> **Warning**: This implementation of Lox is intended for educational purposes only and should not be used as a production language. It lacks many features and optimizations necessary for production environments, such as comprehensive error handling, security measures, and performance optimizations.

## How to Run?

### Software Requirements

The following instructions have been tested on macOS. If you encounter issues on other operating systems or machines, please let me know.

#### For macOS

- A C compiler (such as `clang` or `gcc`)
- CMake
- Make

### Compilation

Once you have the necessary dependencies installed, you can compile `CLox` using the following command:

```bash
make clean cmake
```

After a successful compilation, the `CLox` binary will be located in the `./build/` folder of the cloned repository.

### Running the Compiler

You can run the compiler in two modes: **REPL mode** and **File Compilation mode**.

#### REPL Mode

To start an interactive REPL session, run:

```bash
./build/CLox
```

#### File Compilation Mode

The Lox compiler can also take a file path as input. Currently, it only supports single-file execution and does not yet support modules.

```bash
./build/CLox <path-to-file>
```