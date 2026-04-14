# M2C Compiler - Morse Code to C Compiler

A compiler that translates morse code into executable C code. This is a simplified compiler supporting basic control structures and I/O operations.

## Supported Features

The M2C compiler currently supports:
- **Control Structures**: `if`, `for`, `while`
- **I/O Operations**: `printf`, `scanf`
- **Variables**: Basic variable declarations and assignments

## Project Architecture

The compilation process follows the standard compiler phases:

```
Morse Code Input
      ↓
   [LEXER] - Tokenization
      ↓
   [SYNTAXER] - Parsing & AST Generation
      ↓
   [SEMANTER] - Semantic Analysis & Type Checking
      ↓
   [OPTIMIZERS] - Code Optimization (Optional)
      ↓
   [GENERATORS] - C Code Generation
      ↓
   C Code Output
```

### Phase Breakdown

| Phase | Component | Purpose |
|-------|-----------|---------|
| **Lexical Analysis** | `lexer/` | Breaks morse code into tokens (keywords, identifiers, operators, punctuation) |
| **Syntax Analysis** | `syntaxer/` | Validates morse code structure and builds Abstract Syntax Tree (AST) |
| **Semantic Analysis** | `semanter/` | Checks for logical errors (type mismatches, undeclared variables, invalid operations) |
| **Optimization** | `optimizers/` | Improves generated code performance by removing dead code and reordering instructions |
| **Code Generation** | `generations/` | Converts AST into valid C code that compiles and executes |

## Getting Started for Contributors

1. Choose a phase based on your interest
2. Read the corresponding `readme.md` file in that directory
3. Follow the phase-specific guidelines and data structures
4. Test your changes against the project's test suite

## Project Structure

```
m2c compiler/
├── readme.md (this file)
├── contribution.md
├── lexer/
│   ├── main.cpp
│   └── readme.md
├── syntaxer/
│   └── readme.md
├── semanter/
│   └── readme.md
├── optimizers/
│   └── readme.md
└── generations/
    └── readme.md
```

## Contributing

Please refer to [contribution.md](contribution.md) for detailed contribution guidelines.

## Morse Code To C Examples

### Example 1: Simple Output
```
Morse: (define-function main → (print "Hello World"))
C Output:
#include <stdio.h>
int main() {
    printf("Hello World\n");
    return 0;
}
```

### Example 2: Conditional
```
Morse: (if (condition) (print "true") (print "false"))
```

### Example 3: Loop
```
Morse: (for (i 0 10 1) (print i))
```

---

For more information on each phase, see the respective component README files.
