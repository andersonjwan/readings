# Chapter 16: Fearless Concurrency

This chapter covered the concurrency features of Rust. This is broken into different concepts in understanding threads, channels, and mutex locks. In general, most primitive data types are concurrent-safe. However, there are some instances of types that are not (e.g., `Rc<T>` or `RefCell<T>`). A type is concurrent safe if it supports Sync/Send traits.

## Notes

- Rust uses a 1:1 implementation of threading to ensure a small runtime.`
