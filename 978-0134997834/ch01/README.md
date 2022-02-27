# Chapter 1: The Basics

This chapter discusses the fundamentals of C++ with breadth. The main takeaways are generally the best practices when dealing with the primitive data types and what is considered valid to C++ and what is different in-comparison to other languages.

## Questions

- (Section 1.10, p19): What is meant by Advice [18], "... one name (only) per declaration"? Does this mean to declare a single variable per declaration (i.e., do `int x; int y` and not `int x, y;`)?

## Important Notes

- When using references, if you assign a reference a new rvalue, it does not change what that reference refers to, but changes the actual value of the object it references.
- Prefer immutability in function definitions over mutating references passed (e.g., return types, non-void, and const references to avoid copying---else, by copying)