# Chapter 13: Functional Language Features: Iterators and Closures

This chapter focused on two main concepts: (1) closures and (2) iterators. A closure is similar to functions with the exception that a closure can capture surrounding variables (i.e., within scope) with three semantics: ownership with `move`, mutable reference, and immutable reference. Iterators are divided into adapters and consumers. Adapters produce an iterator and consumers convert an iterator into a collection of values. In addition, it should be heavily noted that iterators pose no significant performance cost over traditional loops.

## Notes

- "Programming in a functional style often includes using functions as values by passing them in arguments, returning them from other functions, assigning them to variables for later execution, and so forth."
- Closures are anonymous functions associated with a variable.
- A closure is called syntactically exact as function calls (i.e., the identifier followed by parentheses).
- A closure's types are inferred based off its first usage.
- For generic types, the traits required for the type to implement are known as "trait bounds".
- Closures can capture the values of variables in their surrounding environment (i.e., scope).
- Use the `move` keyword before the parameter list to force the closure to take ownership of the variables it used from the surrounding environment.
- When implementing your own iterator, you must have a variable to retain the current state of the variable (e.g., a counter variable).
