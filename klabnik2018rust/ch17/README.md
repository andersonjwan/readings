# Chapter 17: Object-Oriented Programming in Rust

This chapter focused on Rust's capabilities in relation to Object-Oriented Programming (OOP) design approach. There are features that Rust provides to enable common concepts of OOP such as encapsulation, methods, polymorphism, and state. However, it should be noted that this is not the forefront argument of Rust's capabilities, and in many cases, there are better ways to approach the problem then force Rust to use OOP concepts.

## Notes

- Rust uses bounded parametric polymorphism (i.e., use of generics to abstract over different possible types).
- Trait objects allow multiple different concrete types that all implement the specific traits of the Trait object.
- Trait objects functions are resolved at runtime using a concept known as **dynamic dispatch**.
- Take advantage of Rust's type system when thinking about design patterns and states of an object (i.e., transform types to different types represent state rather than holding internal state values).
