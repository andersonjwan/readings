## Questions

- Section 2.1, p21: What is the list of declarator operators? Is it not just the `=` or `{}` operators?
- Section 2.3, p23: What are type members in relation to classes?
- Section 2.4, p26: What is meant by, "At the application level, abstractions relying on such tagged unions are common and useful. The use of ‘‘naked’’ unions is best minimized."?
  - A naked union is one without an identifying type to understand what data is being used within that uion (i.e., a tagged union has an additional field/data to indicate what type the union is holding).
- Section 2.5, p27: If we define an `enum class` and implement a function that performs some action based on a switch case of a reference to the `enum class`, do we have to have a default condition if we know in advance there's _no_ possibility for it to be anything else besides all the test enum values?
- Section 2.6, p28: What is meant by, "Represent the distinction between an interface and an implementation using a class"?

## Notes

- In particular, we often want to keep the representation inaccessible to users so as to ease use, guarantee consistent use of the data, and allow us to later improve the representation. To do that we have to distinguish between the interface to a type (to be used by all) and its implementation (which has access to the otherwise inaccessible data).
- The only main difference between a struct and a class is that the members are public by default in a struct and private in a class if no access modifiers are given.

## Definitions

- **Member initializer list**:
- **Subscript function**:

## Resources

- [Classes and structures (C++ only)](https://www.ibm.com/docs/en/zos/2.3.0?topic=only-classes-structures-c)