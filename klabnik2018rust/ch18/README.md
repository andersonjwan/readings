# Chapter 18: Patterns and Matching

This chapter covered the powerful feature of Rust known as pattern matching. Pattern matching can occurs in many areas of code in Rust---from simple match expressions to function parameters to let constructs. In addition, a pattern can be deeply nested and complex with additional features such as catchalls and ignores.

## Notes

- A pattern consists of literals, destructured arrays/enums/structs/tuples, variables, wildcards, and placeholders.
- A match pattern has a match followed by the value and one or more match arms consisting of a pattern and an expression to evaluate.
- The catchall (`_`) pattern is used to match anything that doesn't get matched beforehand.
- `if let` is not exhaustive.
- There are two forms of patterns: (1) refutable and (2) irrefutable. Irrefutable patterns match anything; refutable patterns don't.
- To let Rust know to ignore unused variables, place a `_` before the name.
- Pattern guards allow additional constraints to which a pattern cannot provide on that pattern.
- Using the `@` operator allows binding and testing of a value to a variable in a pattern whereas in complex patterns, one or the other is only allowed.
