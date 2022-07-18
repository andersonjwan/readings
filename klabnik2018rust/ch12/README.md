# Chapter 12: An I/O Project: Building a Command Line Program

This project focused on developing a simplified version of `grep`. It touched upon concepts of command-line arguments, environment variables, code refactoring, and Test Driven Development (TDD).

## Notes

- "It's good practice to begin refactoring early on when developing a program because it's much easier to refactor smaller amounts of code"
- Functions should be easy to **reason about**,  **test**, and **modify** without breaking one of its parts.
- Every function should have exactly one task.
- It's best to group configuration variables into one structure to ensure the purpose is clear.
- When developing Rust binaries, it is best to extract the logic of the code to `lib.rs` and the core running functionality to `main.rs`. Therefore, we can test the indivisible units of the program effectively and worry about only a couple things in the `main` function.
- "Using primitive values when a complex type would be more appropriate is an anti-pattern known as primitive obsession"
- If the purpose is to create a new instance of a struct, then it is more idiomatic to add a `new` method to the struct than a separate function.
- When the success return value is `Ok(())`, then it means we are only looking for side effects of the function.
- CLI programs are expected to redirect error messages to stderr and success messages/printouts to stdout.
