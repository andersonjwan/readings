# Chapter 5: Using Structs to Structure Related Data

This chapter covered the concept of structs: data structures used to group similar items together. In addition, the concept of methods and associated functions for structs were defined as well as a general note on automatic dereferencing performed by Rust (i.e., the method syntax and dot syntax is used exclusively by the language and appropriately converted during compilation).


## Notes

- A structure should be used when we want to group together similar items. In addition, if a function takes multiple arguments where the arguments are seemingly related to each other, then it is best to consider a struct to be passed.
- A struct tuple is a tuple that is created with a name.
- When defining methods that a struct implements, the first argument must be `self`. This can be either a mutable reference (`&mut self`), immutable reference (`&self`), or an ownership argument (`self`).
- Multiple implementation blocks for the same structure can be used. However, it is not necessary when defining multiple functions in one place.
