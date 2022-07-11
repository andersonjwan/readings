# Chapter 6: Enums and Pattern Matching

This chapter focused primarily on the introduction of enumerations (enums) and the various features/potential they hold. In addition, pattern matching against enumerations using the `match` and `if let` operations were discussed.

## Notes

- Enums are like structs with the exception that they work off of the concept of variants (i.e., for one instance of an enum, it can only be one type).
- Pattern matching works with the `match` and `if let` operations and are strong features to use when making decisions about the variant.
- You can use `_` to pattern match everything else that doesn't match an arm in the `match` statement.
- The `if let` statement is not exhaustive, so it should only be used if matching 1-2 items (generally speaking).
