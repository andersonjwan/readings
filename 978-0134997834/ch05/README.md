# Chapter 5: Essential Operations

## Questions

-

## Notes

- Within class definitions, there are member functions for construct, copy, move, and deconstruct. The rule of thumb is the "rule of zero" (i.e., either define all of th essential operations of none of them) to ensure logically stable and reliable code.
- Setting a function to delete does not allow any calls to it at. Therefore, an error is thrown at compilation time. Furthermore, the delete assignment is not strict to the essential member functions; it can also be applied to inherited functions, for example.
- Never use member-wise copy for abstract classes
- If a class serves as a _resource handle_ (i.e., it handles allocated data - a pointer), then member-wise copy will NOT work.

## Definitions

- 

## Resources

- [Object reference or pointer to STL container](https://www.sololearn.com/Discuss/2347789/which-one-is-good-option-object-or-reference-or-pointer-into-stl)
- [Declaring an ENUM in a class](https://stackoverflow.com/questions/2503807/declaring-an-enum-within-a-class)
- [Modern C++ class members and initializations the right way](https://medium.com/pranayaggarwal25/using-modern-class-members-and-initializations-c11e931c3ba)
