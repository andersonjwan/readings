# Chapter 7: Managing Growing Projects with Packages, Crates, and Modules

This chapter covered concepts of packages, crates, and modules. To summarize, a package is made up of crates (at least a library(1) or binary(N)), a crate is made up of modules, and a module is made up of functions, structs, enums, etc. A crate can be broken into several different files as well to help with project structure and organization.

## Notes

- It is best to use absolute paths over relative because, in most cases, code definitions move independently of each other.
- When bringing paths into scope, there are three rules: (1) if the path is a function, bring up to its parent into the path; (2) if the path is to a struct, enum, or others, then bring in its full content (e.g., `use std::collections::HashMap`); (3) if the full path to the item is supposed to be brought it but a name conflict arises, bring only up to its parent path.
- If module A brings in a name B from module C, then B is private by default to any other modules that use A.
