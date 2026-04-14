# Contributing to M2C Compiler

Thank you for contributing to the M2C Compiler! This guide will help you understand how to get started and make meaningful contributions.

## 🎯 Overview: What is M2C?

M2C is a **5-phase compiler** that translates morse-encoded source code into executable C code. Each phase has a specific role:

1. **Lexer** - Reads morse, outputs tokens  
2. **Syntaxer** - Validates structure, builds AST
3. **Semanter** - Checks types and scope
4. **Optimizers** - Improves performance (optional)
5. **Generators** - Converts AST to C

See [README.md](readme.md) for the full architecture overview.

## 🔧 How to Get Started

### Step 1: Choose Your Phase

Select the compiler phase you'd like to work on:

| Phase | Folder | Great For | Difficulty |
|-------|--------|-----------|------------|
| Lexer | `lexer/` | Parsing morse patterns, tokenization | Medium |
| Syntaxer | `syntaxer/` | Grammar rules, tree structures | Hard |
| Semanter | `semanter/` | Type checking, scope management | Hard |
| Optimizers | `optimizers/` | Algorithm design, code improvement | Medium |
| Generators | `generations/` | C code output, string formatting | Medium |

**New to compilers?** Start with **Lexer** or **Generators** - they're more intuitive.

### Step 2: Read the Phase Documentation

Each phase directory has a `readme.md` file:
- Data structures (Token, AST nodes, etc.)
- Algorithm guidelines  
- Implementation patterns
- Test examples

```bash
cd <phase-directory>
cat readme.md
```

### Step 3: Implement Your Component

- Follow the guidelines in the phase README
- Use the provided code structures
- Implement core functions
- Add comments for complex logic

### Step 4: Test Your Code

Write test cases for:
- Valid input cases (morse code that should work)
- Invalid input cases (error handling)
- Edge cases (empty input, single character, etc.)

**Example test:**
```cpp
Lexer lexer("(% (i;0;10) (<\"hi\">))");
auto tokens = lexer.tokenize();
assert(tokens.size() > 0);
assert(tokens[0].type == SYMBOL);
```

### Step 5: Submit Changes

- Create clear commit messages
- Reference issue numbers if applicable  
- Explain what your code does
- Include test cases

## 📋 Code Guidelines

### Language & Style
- **Language**: C/C++
- **Formatting**: Consistent with existing code in the phase
- **Comments**: Add explanatory comments for non-obvious logic
- **Naming**: Use clear, descriptive variable and function names

### Best Practices
- Don't repeat code (use helper functions)
- Keep functions focused on one task
- Return errors clearly (don't silently fail)
- Handle edge cases explicitly

### Documentation
- Update the phase README if adding features
- Comment complex algorithms
- Provide usage examples

## 🐛 Reporting Issues

Found a bug or have an idea?

1. **Search first** - Check existing issues
2. **Be specific** - Include morse code example that shows the problem
3. **Show the error** - Paste error messages or unexpected behavior
4. **Suggest a fix** - If you have ideas, mention them

**Example issue:**
```
Title: Lexer crashes on empty parentheses

Description:
The lexer crashes when given input: "()"

Error: Segmentation fault at line 45

Expected: Should tokenize as LPAREN, RPAREN
```

## 📚 Learning Resources

- **Compiler Theory**: Read about [3-address code](https://en.wikipedia.org/wiki/Three-address_code) and ASTs
- **Morse Code**: Learn morse syntax in main [README.md](readme.md)
- **Examples**: Check `phase/readme.md` for code examples
- **Questions**: Ask in issues or discussions

## 🚀 Contribution Checklist

Before submitting:

- [ ] Code follows the style of the phase
- [ ] All existing tests still pass
- [ ] New tests added for your changes
- [ ] Comments explain complex logic
- [ ] README updated if adding features
- [ ] Commit message is clear and descriptive

## 🎓 Understanding the Pipeline

As you work on your phase, remember:
- **Lexer output** → feeds into Syntaxer
- **Syntaxer output** → feeds into Semanter  
- **Semanter output** → optionally fed to Optimizers
- **Optimizer/Semanter output** → fed to Generators
- **Generators output** → valid C code

So if you change something in Lexer, test how it affects downstream phases!

## 📞 Need Help?

- Read the phase `readme.md` thoroughly
- Look at existing implementations
- Check test files for usage patterns
- Ask in issues (we're here to help!)

---

**Thank you for contributing! Together we're building a unique compiler. 🚀**
