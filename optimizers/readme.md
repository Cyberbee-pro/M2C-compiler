# Optimizers - Optimization Phase

## Overview

The **Optimizers** is the fourth (optional) phase of the M2C compiler. It performs **code optimization** by improving the efficiency and performance of the AST before code generation.

## What Do the Optimizers Do?

The optimizers analyze the AST and apply transformations to make the generated C code more efficient, without changing the program's behavior.

### Input
**Annotated AST** from the Semanter

### Output
**Optimized AST** - Same structure, but with improvements applied

```
Original:
    x = 0;
    while (x < 100) {
        x = x + 1;
    }
    print(x);

Optimized:
    x = 100;              // Loop unrolled/computed
    print(x);
```

## Key Responsibilities

1. **Dead Code Elimination**: Remove unreachable code
2. **Loop Optimization**: Unroll simple loops, optimize loop bounds
3. **Constant Folding**: Evaluate constant expressions at compile time
4. **Common Subexpression Elimination**: Remove duplicate calculations
5. **Algebraic Simplification**: Simplify expressions (e.g., `x * 1` → `x`)

## Optimization Techniques

### 1. **Dead Code Elimination**

Remove code that never executes:

```
// Before
if (false) {
    x = 10;          // Dead code
}
y = 20;

// After
y = 20;
```

### 2. **Constant Folding**

Evaluate constant expressions at compile time:

```
// Before
x = 5 + 3 * 2;
y = "hello" + " world";

// After
x = 11;
y = "hello world";
```

### 3. **Loop Optimization**

Simplify loops when possible:

```
// Before
for (i = 0; i < 5; i = i + 1) {
    print(i);
}

// Optimized (unrolled)
print(0);
print(1);
print(2);
print(3);
print(4);
```

### 4. **Algebraic Simplification**

Simplify algebraic expressions:

```
// Before
x = y * 1;
z = a + 0;
w = b * 0;

// After
x = y;
z = a;
w = 0;
```

### 5. **Common Subexpression Elimination**

Avoid recalculating the same expression:

```
// Before
x = a + b;
y = a + b;
z = a + b;

// After
temp = a + b;
x = temp;
y = temp;
z = temp;
```

## Data Structures

```cpp
class Optimizer {
    Optimizer();
    
    // Apply all optimizations
    void optimize(ASTNode*& node);
    
    // Individual optimization methods
    void eliminateDeadCode(ASTNode*& node);
    void foldConstants(ASTNode*& node);
    void optimizeLoops(ASTNode*& node);
    void simplifyAlgebraic(ASTNode*& node);
    void eliminateCommonExpressions(ASTNode*& node);
    
private:
    // Helper to determine if code is reachable
    bool isReachable(ASTNode* node);
    
    // Helper to evaluate constant expressions
    bool tryEvaluateConstant(Expression* expr, long long& result);
    
    // Expression comparison for CSE
    bool expressionsAreEquivalent(Expression* e1, Expression* e2);
};

class ExpressionEvaluator {
    // Used for constant folding
    bool evaluate(Expression* expr, long long& result);
};
```

## Implementation Guidelines

### 1. **Safe Optimization**

Ensure optimizations never change program behavior:

```cpp
bool Optimizer::canOptimize(ASTNode* node) {
    // Only optimize if semantically safe
    if (!hasNoSideEffects(node)) return false;
    if (node->isSemanticValid == false) return false;
    return true;
}
```

### 2. **Iterative Optimization**

Apply optimizations multiple times until no more changes:

```cpp
void Optimizer::optimize(ASTNode*& node) {
    bool changed = true;
    
    while (changed) {
        changed = false;
        
        changed |= applyDeadCodeElimination(node);
        changed |= applyConstantFolding(node);
        changed |= applyAlgebraicSimplification(node);
        changed |= applyCESE(node);
    }
}
```

### 3. **AST Node Modification**

When optimizing, may remove or replace nodes:

```cpp
ASTNode* Optimizer::foldConstants(Expression* expr) {
    if (BinaryOp* op = dynamic_cast<BinaryOp*>(expr)) {
        long long leftVal, rightVal;
        
        if (tryEvaluateConstant(op->left, leftVal) &&
            tryEvaluateConstant(op->right, rightVal)) {
            
            long long result;
            if (op->op == "+") result = leftVal + rightVal;
            else if (op->op == "*") result = leftVal * rightVal;
            // ... etc
            
            // Replace with constant
            return new Number(result);
        }
    }
    return expr;
}
```

### 4. **Optimization Levels**

Consider supporting different optimization levels:

```cpp
enum OptimizationLevel {
    LEVEL_NONE,        // No optimization
    LEVEL_O1,          // Basic optimizations
    LEVEL_O2,          // Aggressive optimizations
    LEVEL_O3           // Maximum optimization
};

class Optimizer {
    Optimizer(OptimizationLevel level);
    
    // Optimization applied based on level
    void optimize(ASTNode*& node);
};
```

## Interface / Main Entry Point

```cpp
class Optimizer {
    Optimizer(OptimizationLevel level = LEVEL_O2);
    
    // Apply optimizations to the AST
    void optimize(ASTNode*& node);
    
    // Get optimization statistics
    struct OptimizationStats {
        int nodesRemoved;
        int constantsEvaluated;
        int expressionsSimplified;
    };
    OptimizationStats getStats();
};
```

## Testing

Test cases should verify:
- Optimization doesn't change program behavior
- Dead code is removed
- Constants are properly folded
- Algebraic simplifications are correct
- Common subexpressions are identified
- Edge cases and corner cases

### Example Test Case

```cpp
// Test constant folding
ASTNode* ast = parseCode("x = 5 + 3 * 2;");
Optimizer opt;
opt.optimize(ast);

// Verify that x got value 11, not a BinaryOp
Assignment* assign = (Assignment*)ast;
Number* result = dynamic_cast<Number*>(assign->value);
assert(result != nullptr);
assert(result->value == 11);
```

## Performance Considerations

Optimizations can be expensive. Balance between:
- **Optimization time**: How long does optimization take?
- **Generated code quality**: How much better is the generated code?
- **Trade-off**: For simple morse code programs, aggressive optimization may not be worth it

## Next Phase

After optimization, the refined AST flows to the **Generators** which:
- Convert the AST to C code
- Emit valid, compilable C code

See `generations/readme.md` for more details.

---

**Key Concepts**: Dead Code Elimination, Constant Folding, Loop Optimization, Algebraic Simplification, Common Subexpression Elimination
