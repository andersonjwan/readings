# Chapter 11: Writing Automated Tests

This chapter covers the mechanics of Rust testing. Tests are broken into two categories: (1) unit tests and (2) integration tests. Unit tests are defined in the same location as the code its testing, and integration tests are placed at the project's root directory under `tests/` where each file is a separate crate that gets tested. There are lots of options through the Command-Line Interface (CLI) of `cargo test` to modify the behavior of how and what tests are ran.

## Notes

- Tests are usually broken into three steps: (1) set up any necessary data or states, (2) run the code that needs testing, (3) assert the results of the tested code matches the expected.
- A test function is created by adding the `#[test]` attribute to it.
- A test will fail when it panics (i.e., when the thread terminates unexpectedly).
- For the `assert_eq!` macro, the order of arguments does not matter. However, by convention, it is expected followed by actual.
- The `assert_nq!` macro is useful for when we don't know what the value will be but know what the value shouldn't be.
- The `assert_eq!` and `assert_nq!` macros use `==` and `!=` operations under the hood. Therefore, the arguments to these must implement the `PartialEq` and `Debug` traits, accordingly (see derivable traits).
- `should_panic` can be used as a function attribute with an optional `expected` string to match an appropriate panic call.
- Options for `cargo test` are split between the resulting binary test and the command. To provide options to the command, list before `--`. Options listed after the `--` are supplied to the resulting binary.
- Integration tests are entirely external to your code and test the public API/interface of your code.
- Unit tests should be defined in a `test` module with the `#[cfg(test)]` annotation held within the file that the tests will be testing.
