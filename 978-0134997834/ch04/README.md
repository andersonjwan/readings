# Chapter 4: Classes

## Questions

- Is the representation of a class is the set of data members that it holds?
- When we return an object of a class, does that return a copy or a reference? And, what defines a return value type of copy or reference? Is it the caller or the callee?

## Notes

- The most common basic class-support includes: (1) concrete classes, (2) abstract classes, and (3) classes in hierarchies.
- For basic uses, direct representatin of classes are sufficient. However, using those representations to reference the free store is more flexible as well (i.e., think of dynamic data structures).
- Avoid naked **new** and **delete** operations!
- Try to avoid explict type conversions (i.e., casts)
- Use unchecked casts as needed at a lower level.
- A class is considered an abstract class _only_ when it declares one or more pure virtual functions.
- A class is considered _polymorphic_ if it provides a single interface used by multiple derived classes.


## Definitions

- handle-to-data model
- RAII
- unchecked casts

## Resources

- [Difference between *.cc and *.cpp](https://stackoverflow.com/questions/18590135/what-is-the-difference-between-cc-and-cpp-file-suffix)
- [Class member functions defined outside namespace](https://stackoverflow.com/questions/56888300/class-member-function-defined-outside-its-namespace)
- [Working Draft, Standard for Programming Language C++](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf#page=259)
- [Overloading class member functions](https://stackoverflow.com/questions/13544364/over-loading-operator-must-take-either-zero-or-one-arguments)
- [Operators in a namespace](https://stackoverflow.com/questions/171862/namespaces-and-operator-overloading-in-c)