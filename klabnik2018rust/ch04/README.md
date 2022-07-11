# Chapter 4: Understanding Ownership

This chapter covered a particularly important topic in Rust: ownership. In short, ownership refers to the idea that a variable that is bound to a value owns that value. If that value is assigned to another, then the previous variable no longer owns the value. In addition, when a variable goes out-of-scope, then its value is automatically dropped. Lastly, slices are a useful data type to view a specific piece of a string/collection that guarantees safe use.

## Notes

- Rust differs from other programming languages in memory management as it automatically frees heap-based memory when a variable goes out-of-scope.
- "Rust will never automatically create "deep" copies of your data."
- If a type implements the `Drop` trait, then it cannot implement the `Copy` trait.
- Passing a variable to a function argument will move or copy just as with assignment semantics in Rust.
- There are two types of references: (1) mutable, and (2) immutable. In either case, you can only have one type (i.e., one mutable reference or multiple immutable references--not both).
- Slices hold a pointer and the length of the slice of the data.
- Slices work with many types of collections.
