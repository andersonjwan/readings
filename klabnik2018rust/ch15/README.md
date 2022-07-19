# Chapter 15: Smart Pointers

This chapter covered the concept of smart pointers in Rust. This includes three different types of pointer interfaces: (1) `Box<T>`, `Rc<T>`, and `RefCell<T>`. A box is used for heap-allocated data. An `Rc<T>` is used for multiple owners (i.e., multiple variables pointing to the same value). Lastly, the `RefCell<T>` is used for both immutable and mutable pointers checked during runtime.

## Notes

- A smart pointer is a struct that implements the `Deref` and `Drop` traits.
- When your type is recursive, use *indirection* (i.e., don't use the type but a pointer to the type).
- A `RefCell<T>` is useful when you need immutable or mutable borrows checked during runtime and not compile-time.
- Reference cycles occur from instances where you use `RefCell<T>` values that contain `Rc<T>` values (i.e., if you use some sort of interior mutability with reference counting semantics).
