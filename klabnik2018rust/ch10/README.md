# Chapter 10: Generic Types, Traits, and Lifetimes

This chapter covered important topics related to generic programming in Rust and a unique feature of the programming language: lifetimes. In addition, Rust uses Traits to help constrain generic type parameters. Generic types can be declared on structs, enums, methods, and functions.

## Notes

- If duplicate code exists, extract the code into the body of a function definition to be resused with a single location to update if necessary.
- If duplicate functions exist that perform the same operation on different parameter types, then generics can be used.
- If duplicate structs or enums exist with the same fields but different types, then generic typing is suggested to avoid the duplication.
- When implementing methods/functions for a struct or enum, the `impl` keyword must have the types declared by the struct definition.
- You can define parameters in accordance to their traits. For example, the function `fn sum(item: impl Summable)` will accept *any* type that implements the `Summable` trait.
