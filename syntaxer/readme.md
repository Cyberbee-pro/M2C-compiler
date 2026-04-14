# Syntaxer - Syntax Analysis Phase

## Overview

The **Syntaxer** is the second phase of the M2C compiler. It performs **syntax analysis** by parsing the token stream from the lexer and building an Abstract Syntax Tree (AST).

## What Does the Syntaxer Do?

The syntaxer takes tokens and validates they follow the grammar rules of the morse-to-C language, then builds a tree structure representing the program.

### Input
**Token Stream** from the Lexer

```
Token(KEYWORD, "while")
Token(IDENTIFIER, "x")
Token(OPERATOR, "<")
Token(NUMBER, "10")
Token(..., ...)
```

### Output
**Abstract Syntax Tree (AST)** - A tree representation of the program structure

```
        Program
         |
      WhileLoop
       /     \
   Condition  Body
    /    \      |
  x    <  10   Block
              [statements...]
```

## Key Responsibilities

1. **Grammar Validation**: Ensure tokens follow language grammar rules
2. **AST Construction**: Build a tree representing program structure
3. **Error Detection**: Identify syntax errors with helpful messages
4. **Position Tracking**: Map AST nodes back to source locations for error reporting

## Grammar Rules

The M2C compiler supports these structures:

```
Program ::= Statement*

Statement ::= IfStatement
           | ForLoop
           | WhileLoop
           | Assignment
           | FunctionCall
           | Block

IfStatement ::= "if" "(" Condition ")" Statement ["else" Statement]

ForLoop ::= "for" "(" Assignment ";" Condition ";" Update ")" Statement

WhileLoop ::= "while" "(" Condition ")" Statement

Condition ::= Expression ComparisonOp Expression
           | Expression

Expression ::= Term (("+"|"-") Term)*

Term ::= Factor (("*"|"/") Factor)*

FunctionCall ::= Identifier "(" ArgumentList ")"

Block ::= "{" Statement* "}"

Assignment ::= Identifier "=" Expression ";"
```

## Data Structures - AST Nodes

```cpp
// Base class for all AST nodes
class ASTNode {
    virtual ~ASTNode() {}
    virtual void accept(ASTVisitor* visitor) = 0;
};

// Expression nodes
class Expression : public ASTNode {
    // abstract
};

class BinaryOp : public Expression {
    Expression* left;
    std::string op;      // +, -, *, /, <, >, ==, etc.
    Expression* right;
};

class Identifier : public Expression {
    std::string name;
};

class Number : public Expression {
    double value;
};

class String : public Expression {
    std::string value;
};

// Statement nodes
class Statement : public ASTNode {
    // abstract
};

class IfStatement : public Statement {
    Expression* condition;
    Statement* thenBranch;
    Statement* elseBranch;  // can be nullptr
};

class WhileLoop : public Statement {
    Expression* condition;
    Statement* body;
};

class ForLoop : public Statement {
    Statement* init;
    Expression* condition;
    Statement* update;
    Statement* body;
};

class Block : public Statement {
    std::vector<Statement*> statements;
};

class FunctionCall : public Statement {
    std::string functionName;
    std::vector<Expression*> arguments;
};

class Assignment : public Statement {
    std::string variableName;
    Expression* value;
};

class Program : public ASTNode {
    std::vector<Statement*> statements;
};
```

## Implementation Guidelines

### 1. **Recursive Descent Parser**

Use recursive descent parsing - each grammar rule becomes a function:

```cpp
class Parser {
    Parser(std::vector<Token> tokens);
    
    Program* parse();
    
private:
    std::vector<Token> tokens;
    int current;
    
    // Grammar rule functions
    Statement* parseStatement();
    IfStatement* parseIfStatement();
    WhileLoop* parseWhileLoop();
    ForLoop* parseForLoop();
    Expression* parseExpression();
    Expression* parseTerm();
    Expression* parseFactor();
    
    // Utility functions
    Token peek();
    Token advance();
    bool check(TokenType type);
    bool match(TokenType type);
    void error(std::string message);
};
```

### 2. **Error Recovery**

When encountering syntax errors:
- Report the error with location information
- Attempt to recover to continue parsing
- Collect multiple errors if possible

```cpp
void Parser::error(std::string message) {
    Token current = peek();
    std::cerr << "Syntax Error at line " << current.line 
              << ", column " << current.column 
              << ": " << message << std::endl;
}
```

### 3. **Operator Precedence**

Handle operator precedence correctly:
```
Highest:  * /
          + -
Lowest:   < > == !=
```

## Interface / Main Entry Point

```cpp
class Parser {
    Parser(std::vector<Token> tokens);
    
    // Parse tokens into AST
    Program* parse();
    
    // Get error messages
    std::vector<std::string> getErrors();
    
    // Check if parsing was successful
    bool hasErrors();
};
```

## Testing

Test cases should cover:
- Valid morse/token sequences produce correct AST
- Nested structures (loops within if, etc.)
- All statement types and expressions
- Error messages for invalid syntax
- Operator precedence
- Edge cases (empty blocks, missing semicolons, etc.)

### Example Test Case

```cpp
// Input tokens for: "if (x < 10) printf(x);"
std::vector<Token> tokens = {
    Token(KEYWORD, "if", 1, 0),
    Token(LPAREN, "(", 1, 2),
    Token(IDENTIFIER, "x", 1, 3),
    Token(OPERATOR, "<", 1, 4),
    Token(NUMBER, "10", 1, 6),
    Token(RPAREN, ")", 1, 8),
    Token(KEYWORD, "printf", 1, 10),
    Token(LPAREN, "(", 1, 16),
    Token(IDENTIFIER, "x", 1, 17),
    Token(RPAREN, ")", 1, 18),
    Token(SEMICOLON, ";", 1, 19),
    Token(END_OF_FILE, "", 1, 20)
};

Parser parser(tokens);
Program* ast = parser.parse();

// Verify AST structure
assert(ast->statements.size() == 1);
assert(dynamic_cast<IfStatement*>(ast->statements[0]) != nullptr);
IfStatement* ifStmt = (IfStatement*)ast->statements[0];
assert(dynamic_cast<BinaryOp*>(ifStmt->condition) != nullptr);
```

## Next Phase

After parsing, the AST flows to the **Semanter** which:
- Checks semantic correctness (types, scope, etc.)
- Detects logical errors
- Annotates AST with type information

See `semanter/readme.md` for more details.

---

**Key Concepts**: Recursive Descent Parsing, Abstract Syntax Tree, Operator Precedence, Error Recovery
