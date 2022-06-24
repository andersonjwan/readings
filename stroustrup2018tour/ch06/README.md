# Chapter 6: Templates

## Questions

- What are template arguments?
  - Template arguments are the types provided to a template at instantiation time. E.g., if the template `Vector<typename T>` exists, then an instantiation of this template is `Vector<int> v`, and the `int` is considered the template argument. 
- When does the instantiation step occur in the compilation process?
  - Instantiation occurs late in the compilation process.
- Section 6.4, p91: What is meant by, "`if constexpr` is not a text-manipulation mechanism and cannot be used to break the usual rules of grammar, type, and scope"?
- Section 6.4, p92: What is "duck typing"?

## Notes

- For a good template definition, we need: (1) dependently typed values, (2) aliases for types and templates, (3) compile-time selection mechanism, and (4) compile-time type and expression properties resolution.
- `constexpr` and `static_asserts` are often used in template design
- There is no separate compilation of templates (i.e., you MUST include the template declaration and definition in the translation units that use it)... (i.e.i.e., definition of a template must occur in header files). 
## Definitions

- Template instantiation
- Template specialization
- Function object or functor
- Policy objects

## Resources

- 