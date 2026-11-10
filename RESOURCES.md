# Compiler Design Lab Resources

## Knowledge

- [Book: _Compilers: Principles, Techniques, and Tools_ (Dragon Book) by Aho, Lam, Sethi, & Ullman](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools)
  The canonical reference for syntax-directed translation, lexical analysis, shift-reduce parsing, and three-address code generation (Chapter 6: Intermediate-Code Generation). Use for: formal grammar definitions, parsing stack mechanics, and quadruple/triple representations.
- [Book: _lex & yacc_ (2nd Edition) by John Levine, Tony Mason, & Doug Brown (O'Reilly)](https://www.oreilly.com/library/view/lex-yacc/9781565920002/)
  Practical industry guide on token propagation, `%left` operator precedence hierarchies, and YACC disambiguation rules. Use for: exact syntax and error recovery conventions.
- [Documentation: GNU Bison (YACC-compatible Parser Generator) Manual](https://www.gnu.org/software/bison/manual/)
  Definitive manual for semantic values, `YYABORT`, and token headers. Use for: modern GCC compatibility flags and header management.

## Wisdom (Communities)

- [r/Compilers](https://www.reddit.com/r/Compilers/)
  Active practitioner forum for compiler construction, parsing questions, and language tooling. Use for: real-world parser debugging and conceptual clarity.
- [Stack Overflow: [lex] and [yacc] tags](https://stackoverflow.com/questions/tagged/yacc)
  High-signal repository of compilation errors, shift-reduce conflict diagnostics, and prototype fixes. Use for: troubleshooting `-Wimplicit-function-declaration` and linker errors.
