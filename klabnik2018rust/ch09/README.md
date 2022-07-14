# Chapter 9: Error Handling

This chapter focused on error handling concepts and methods in Rust. Error handlings is grouped into two categories: (1) errors capable of being handled and (2) errors that terminate a program. For Rust, handling errors is implemented with `Result<T, E>` and terminating on error denoted as `panic`'king.

## Notes

- The confidence in a value can be reassured using custom types. For example, in the Guessing Game, the guess must be between 1-100. Therefore, do enforce this rule, a new type called `Guess` could be created that enforces this rule rather than manually checking the input every time.
