# Chapter 2: Modularity

## Questions

- Section 3.3, p34: It states that a module is compile a single time whereas a header is compiled in each translation unit (i.e., a source file that includes that header). However, from what I understand, if we use header guards for a header, then it only gets defined once, no?

## Notes

- Using modules over headers provides a nice boost in compile-time performance.
- Modules are compiled once rather than each translation unit.
- Module imports are not transitive (i.e., if a module imports another module, and you import that module that imports another, you do not again access to the module imported by the module you imported).
- To access a name in another namespace, we **qualify** that name with namespace it lives is under.
- Two types of `using` qualifiers: (1) *using-declaration* is used to qualify a specific name in a namespace and (2) *using-directive* is used to qualify all the names in a given namespace. The latter should be used _very_ carefully.
- Do NOT overuse try-catch statements - prefer to write guaranteed and implicit code.
- In _well designed code_, try-catch blocks are rare.
- Exceptions are integrated into constructors and deconstructors.
- Values are considered small if they are the size of 2-3 pointers or less.
- Do NOT put a using-directive in a header files.
- "Prefer pass-by-const-reference over plain pass-by-reference"

## Definitions

- Structured binding

## Resources

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Coding style advice/rationale(s) for placing spaces in control statements with C++](https://stackoverflow.com/questions/4368055/coding-style-advice-rationales-for-placing-spaces-in-control-statements-with-c)
- [const member functions](https://docs.microsoft.com/en-us/cpp/cpp/const-cpp?view=msvc-160#const-member-functions)
- [Square Root of Complex Number](https://www.cuemath.com/algebra/square-root-of-complex-number/)
- [Complex Numbers Overview](https://engineering.purdue.edu/~mikedz/ee301/ComplexNumberOverview.pdf)
- [std::abs](https://www.cplusplus.com/reference/cmath/abs/)
- [Member function with static linkage](https://stackoverflow.com/questions/31305717/member-function-with-static-linkage)
- [Easiest way to convert int to string in C++](https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c)
- [std::to_string](https://en.cppreference.com/w/cpp/string/basic_string/to_string)