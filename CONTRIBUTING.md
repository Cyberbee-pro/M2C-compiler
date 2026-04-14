# Contributing to M2C Compiler

Thank you for your interest in contributing to the M2C Compiler project! This guide will help you understand how to get started.

## How to Contribute

### 1. **Understand the Compiler Phases**

Before contributing, familiarize yourself with the standard compiler architecture. Each phase has specific responsibilities:

- **Lexer** (Lexical Analysis): Token generation
- **Syntaxer** (Syntax Analysis): Structure validation and AST building
- **Semanter** (Semantic Analysis): Logical error detection
- **Optimizers** (Optimization): Performance improvement
- **Generators** (Code Generation): C code output

See [readme.md](readme.md) for the overall architecture.

### 2. **Choose Your Phase**

Select one of the compiler phases to contribute to:

| Phase | File | Best For |
|-------|------|----------|
| Lexical Analysis | `lexer/` | Token pattern matching, morse-to-token conversion |
| Syntax Analysis | `syntaxer/` | Grammar rules, AST node design |
| Semantic Analysis | `semanter/` | Type checking, scope management |
| Optimization | `optimizers/` | Algorithm design, performance improvement |
| Code Generation | `generations/` | C code emission, backend engineering |

Visit the README in your chosen phase directory for specific guidelines.

### 3. **Development Workflow**

```
1. Fork or clone the repository
2. Create a branch for your feature/fix
3. Read the phase-specific README
4. Implement your changes
5. Test thoroughly with various morse code inputs
6. Submit a pull request with clear description
```

### 4. **Code Guidelines**

- **Language**: C/C++
- **Style**: Follow existing code conventions in your chosen phase
- **Comments**: Add comments for complex logic
- **Testing**: Include test cases for your changes
- **Documentation**: Update relevant README files if adding features

### 5. **Testing**

Each phase should have test cases. When submitting changes:
- Ensure all existing tests pass
- Add new tests for added functionality
- Test edge cases and error conditions

### 6. **Issue Reporting**

If you find bugs or have feature requests:
- Check existing issues first
- Provide clear description and reproduction steps
- Include sample morse code that demonstrates the issue

## Phase-Specific Guidelines

For detailed guidelines on contributing to a specific phase, see:
- [Lexer Guidelines](lexer/readme.md)
- [Syntaxer Guidelines](syntaxer/readme.md)
- [Semanter Guidelines](semanter/readme.md)
- [Optimizers Guidelines](optimizers/readme.md)
- [Generators Guidelines](generations/readme.md)

## Getting Help

- Review the phase-specific README files
- Check existing code for patterns
- Look at test cases for usage examples
- Ask questions in issues or pull request discussions

## License

By contributing to M2C Compiler, you agree that your contributions will be licensed under the same license as the project.

---

Happy contributing! 🚀
