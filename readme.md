# M2C Compiler - Morse Code to C Compiler

**Transform morse code into working C programs!** The M2C Compiler is a lightweight compiler designed to convert morse-encoded source code into executable C code. Perfect for learning compiler design or creating unique code in morse.

## 🎯 What Can You Build?

The M2C compiler supports creating C programs with:
- **Control Flow**: Conditionals (`~` for if), loops (`%` for, `%%` for while)
- **I/O Operations**: String output (`<"...">;||`) and variable display
- **Variables**: Integer variables with basic arithmetic operations
- **Full Compilation Pipeline**: From morse code → tokens → AST → C code

## 🔄 How It Works: 5-Phase Compilation

The M2C compiler processes morse code through a standard compiler pipeline:

```
┌─────────────────┐
│  Morse Input    │     f. example: (%(x;0;10)||(<"....">);||)
└────────┬────────┘
         ↓
    [LEXER]         ──→  Converts morse → tokens
         ↓
  [SYNTAXER]        ──→  Builds Abstract Syntax Tree (AST)
         ↓
   [SEMANTER]       ──→  Validates types & scope
         ↓
 [OPTIMIZERS]       ──→  (Optional) Improves code
         ↓
  [GENERATORS]      ──→  Emits C code
         ↓
  ┌──────────────┐
  │  C Output    │      #include <stdio.h> ...
  └──────────────┘
```

### Phase Guide

| # | Phase | Role | Directory |
|---|-------|------|-----------|
| 1️⃣ | **Lexer** (Tokenization) | Reads morse, produces token stream | `lexer/` |
| 2️⃣ | **Syntaxer** (Parsing) | Validates tokens, builds AST | `syntaxer/` |
| 3️⃣ | **Semanter** (Semantic Check) | Ensures types & scopes are correct | `semanter/` |
| 4️⃣ | **Optimizers** (Code Refinement) | Removes dead code, optimizes (optional) | `optimizers/` |
| 5️⃣ | **Generators** (Codegen) | Transforms AST to C code | `generations/` |

## 🚀 Quick Start for Contributors

**Want to contribute to a specific phase?**
1. Pick your phase from the table above
2. Navigate to that folder: `cd <phase-dir>`
3. Read `readme.md` for guidelines and data structures  
4. Implement or improve your component
5. Test thoroughly with morse code examples

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

## ⚠️ Important: Complete Morse Encoding

**ALL code elements in M2C must be morse-encoded**, not just operators and keywords:
- **Numbers**: `9` → `.---.`, `0` → `-----`
- **Characters**: `a` → `.-`, `b` → `-...`, etc.
- **Variable names**: Must be in morse (e.g., `....+.` for a var)
- **Strings**: Every character must be morse-encoded
- **Operators**: Control flow (`~`, `%`, `%%`), arithmetic (`\+`, `\-`, `\*`, `\/`), assignment (`=`, `==`)

## Morse Language Syntax Reference

### Control Flow Operators
| Element | Morse | Meaning |
|---------|-------|---------|
| If statement | `~()` | Conditional execution |
| For loop | `%()` | Counter-controlled loop |
| While loop | `%%()` | Condition-controlled loop |
| Block start/end | `|| ||` | Represents C braces `{}` |
| Main function | `/|| ||` | Main function wrapper |
| EXIT Keyword | ` ^() ` | exit function|


### Arithmetic & Conditional Operators
| Operator | Morse | Meaning | Notes |
|----------|-------|---------|-------|
| Addition | `\+` | Add two values | Backslash prefix |
| Subtraction | `\-` | Subtract two values | Backslash prefix |
| Multiplication | `\*` | Multiply two values | Backslash prefix |
| Division | `\/` | Divide two values | Backslash prefix |
| Less than | `\<` | Comparison | Backslash prefix |
| Greater than | `\>` | Comparison | Backslash prefix |
| Assignment | `=` | Assign value | NO backslash |
| Equality | `==` | Compare equality | NO backslash |

### Morse Number & Character Reference
| Digit | Morse | Digit | Morse |
|-------|-------|-------|-------|
| 0 | `-----` | 5 | `.....` |
| 1 | `.----` | 6 | `-....` |
| 2 | `..---` | 7 | `--...` |
| 3 | `...--` | 8 | `---..` |
| 4 | `....-` | 9 | `.---.` |

### Example Morse Characters (Letters)
| Letter | Morse | Letter | Morse |
|--------|-------|--------|-------|
| a | `.-` | h | `....` |
| b | `-...` | i | `..` |
| e | `.` | l | `.-..` |
| o | `---` | x | `-..-` |

## Contributing

Please refer to [contribution.md](contribution.md) for detailed contribution guidelines.

## Morse Code To C Examples

### Example 1: Simple Output (Print "Hello")
**Morse Input:**
```
/|| 
  <"......... . .. ... .. .. ... . --.--.">
||
```
*Note: Each character in the string is morse-encoded; spaces separate characters*

**C Output:**
```c
#include <stdio.h>
int main() {
    printf("hello");
    return 0;
}
```

### Example 2: Loop with Morse Numbers
**Morse Input:** (Loop from morse-encoded 0 to 9)
```
/||
  %(.---;....-;.---.) ||
    <"...-.--..-..---+-.-">;
  ||
||
```
*Translation: `for(i;5;9)` in morse, printing "loop" each iteration*

**C Output:**
```c
#include <stdio.h>
int main() {
    for(i; 5; 9) {
        printf("loop");
    }
    return 0;
}
```

### Example 3: Conditional with Morse Variables
**Morse Input:**
```
/||
  ~(x) ||
    <".-.-.-..-.">;
  ||
||
```
*Translation: if morse-variable `x` is true, print in morse*

**C Output:**
```c
#include <stdio.h>
int main() {
    if(x) {
        printf("yes");
    }
    return 0;
}
```

### Example 3.1: Conditional with Morse Variables
**Morse Input:**
```
/||
  ~(x) ||
    <".-.-.-..-.">;
  ||
  ~~(y) ||
    <"-.+---">
  ||
||
```
*Translation: if morse-variable `x` is true, print in morse*

**C Output:**
```c
#include <stdio.h>
int main() {
    if(x) {
        printf("yes");
    }
    else (x) {
        printf("no");
    }
    return 0;
}
```


### Example 4: Arithmetic Operations with Backslash Operators
**Morse Input:** (Using backslash-prefixed arithmetic operators)
```
/||
  ....= \+ ....-
  ||
||
```
*Translation: `a = b + 5` in morse (using `\+` for addition)*

**C Output:**
```c
#include <stdio.h>
int main() {
    a = b + 5;
    return 0;
}
```

---

For more information on each phase, see the respective component README files.
