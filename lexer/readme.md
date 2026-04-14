# Lexer - Lexical Analysis Phase

## Overview

The **Lexer** is the first phase of the M2C compiler. It performs **lexical analysis** by breaking down morse code input into meaningful tokens.

## What Does the Lexer Do?

The lexer scans the raw morse code and converts it into a stream of tokens:

### Input
Raw morse code string (sequences of dots, dashes, and spaces)

### Output
**Token Stream** - Each token represents:
- **Keywords**: `if`, `for`, `while`, `printf`, `scanf`
- **Identifiers**: Variable and function names
- **Operators**: `+`, `-`, `*`, `/`, `=`, etc.
- **Literals**: Numbers, strings
- **Punctuation**: `(`, `)`, `,`, `;`, etc.

### Example

```
Input (Morse Code):
·· ·- ·- ·· ·-·· ·- (represents tokens)

Output (Token Stream):
Token(KEYWORD, "while")
Token(IDENTIFIER, "x")
Token(OPERATOR, "<")
Token(NUMBER, "10")
```

## Key Responsibilities

1. **Morse Code Recognition**: Identify morse code patterns and map them to characters
2. **Tokenization**: Group characters into meaningful tokens
3. **Error Detection**: Identify invalid morse sequences or unknown patterns
4. **Position Tracking**: Keep track of line and column numbers for error reporting

## Data Structures

### Token Structure

```cpp
struct Token {
    TokenType type;      // KEYWORD, IDENTIFIER, OPERATOR, LITERAL, etc.
    std::string value;   // The actual text value of the token
    int line;            // Line number in the source
    int column;          // Column number in the source
};

enum TokenType {
    KEYWORD,             // if, for, while, printf, scanf
    IDENTIFIER,          // variable names, function names
    OPERATOR,            // +, -, *, /, =, <, >, ==, etc.
    NUMBER,              // integer and floating point literals
    STRING,              // string literals
    LPAREN,              // (
    RPAREN,              // )
    LBRACE,              // {
    RBRACE,              // }
    COMMA,               // ,
    SEMICOLON,           // ;
    NEWLINE,             // line terminator
    END_OF_FILE,         // EOF marker
    ERROR                // error token
};
```

## Implementation Guidelines

### 1. **Morse Code Mapping**

You need to define how morse sequences map to characters:

```
·· → a
· ·- → b
· · · → c
- · · → d
· → e
...etc
```

### 2. **Token Recognition Algorithm**

```
1. Read morse code input character by character
2. Group continuous morse sequences (·, -, space)
3. Match patterns to known tokens
4. Generate Token objects
5. Handle whitespace and newlines
```

### 3. **Error Handling**

The lexer should detect:
- Invalid morse sequences
- Unrecognized patterns
- Unexpected characters

Example error token:
```cpp
Token(ERROR, "invalid_pattern", 5, 12)
```

### 4. **Keywords**

Define and recognize these keywords:
- `if`
- `for`
- `while`
- `printf`
- `scanf`

## Interface / Main Entry Point

The lexer should expose:

```cpp
class Lexer {
    Lexer(std::string source);
    
    // Get next token from input
    Token nextToken();
    
    // Get all tokens at once
    std::vector<Token> tokenize();
    
    // For error reporting
    std::string getErrorMessage();
};
```

## Testing

Test cases should cover:
- Valid morse code → correct tokens
- Invalid morse code → error tokens
- All keywords recognized
- Identifiers and numbers parsed correctly
- Proper error messages for invalid input

## Example Test Case

```cpp
// Input: morse code for "while x < 10"
Lexer lexer("· · · · | ··· | ··· ·· | ·---- ----- ");
auto tokens = lexer.tokenize();

// Expected output:
// Token(KEYWORD, "while", 1, 0)
// Token(IDENTIFIER, "x", 1, 7)
// Token(OPERATOR, "<", 1, 9)
// Token(NUMBER, "10", 1, 11)
// Token(END_OF_FILE, "", 1, 14)
```

## Next Phase

After the lexer produces tokens, they flow into the **Syntaxer** which:
- Validates the sequence of tokens
- Builds an Abstract Syntax Tree (AST)
- Detects syntax errors

See `syntaxer/readme.md` for more details.

---

**Main Implementation**: [main.cpp](main.cpp)
