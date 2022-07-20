# Chapter 19: Advanced Features

This chapter covered advanced concepts of Rust that in most cases won't be used. However, having knowledge of them is beneficial to recognizing the source of problems if they so arise. The set of concepts included unsafe Rust, advanced traits, types, and functions and closures, and macros.

## Notes

- Accessing and modifying mutable static variables is considered unsafe.
- `str` is not a valid type because its size is not consistent.Therefore, Rust uses Dynamically Sized Types, or DSTs that hold a reference and the size.
- It is best practice to write functions using generic types and one of the closure traits, so your functions can accept either functions or closures.
- Macros are a way of writing code that writes other code (i.e., metaprogramming).
