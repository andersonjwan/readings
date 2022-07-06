# Chapter 3: Common Programming Concepts

This chapter cover the fundamentals of Rust centered around common programming concepts and the important distinctions of the language. This includes a coverage on topics of variables, mutability, data types, functions, concept of *expressions*, and control flow structures (e.g., loops and conditional statements).

## Notes

- All declared variables are immutable by default. To make a variable mutable, add the `mut` keyword before the variable name.
- Constants can be declared with the keyword `const` and require the type annotation.
- A variable is shadowed when a successor variable is defined with the `let` keyword with the same name as the preceding variable. For example, `let x = 1;` is shadowed by the statement `let x = "1";`.
- When a variable is shadowing, it can have a different type than the variable it is shadowing because it is essentially a new variable declaration with the same name.
- Rust, in many cases, can infer the type based on the value and how its used. However, if multiple types are possible, we must provide a type annotation.
- The four scalar types in Rust are: (1) integers, (2) floating-points, (3) booleans, and (4) characters.
- Use `isize` or `usize` when indexing a collection.
- Characters in Rust are not conventionally designed as intuition of a character is.
- There are two main compound data types in Rust: tuples and arrays.
- Tuples are accessed using an identify index or pattern matching, and arrays are accessed traditionally using array indexing methods (i.e., square brackets).
- For function definitions, you must provide type annotations to the parameters.
- Expressions include a value, function call, macro, and curly brackets.
- Expressions do not include ending semicolons.
- Blocks of code associated with a condition are colloquially known as arms.
