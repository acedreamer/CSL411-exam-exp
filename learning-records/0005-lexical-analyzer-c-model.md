# Stream Scanning Invariants and Hierarchical Lexical Classification

The user has mastered the front-end lexical analysis phase implemented in ANSI C from scratch. They understand that a compiler scanner operates as a continuous character stream reader (`fgetc(ptr)`) coupled to an accumulator buffer (`buffer[50]`), where whitespaces and self-delimiting operators (`+`, `-`, `=`, `;`, etc.) trigger atomic buffer flush events (`idx > 0`) to handle unspaced source code (e.g., `a=b+10;`). They have deconstructed the critical 5-tier classification hierarchy inside `detect()`, internalizing why keyword matching must strictly precede identifier regex matching to prevent language keywords from being misclassified as user-defined variables.

## Evidence
- Complete deconstruction of the character stream scanner invariants: whitespace skipping, self-delimiting symbol detection with pre-flush checks (`if (idx > 0)`), and two-byte operator packaging (`temp[0] = ch, temp[1] = '\0'`).
- Rigorous mathematical defense of the Keyword-Before-Identifier precedence theorem based on regular language superset inclusion ($[a-zA-Z\_][a-zA-Z0-9\_]* \supset \text{Keywords}$).
- Precise tracing and classification across the five core token categories: Keywords, Operators, Special Symbols, Numeric Constants, and Identifiers, with error fallback.
- Comparative understanding of procedural C scanning vs. automated LEX/Flex DFA state machine generation via Thompson's and subset constructions.

## Implications
- Unlocks the ability to implement, compile, trace, and defend Program 6 (Lexical Analyzer in C) on a blank sheet or exam terminal in under 15 minutes without notes.
- Enables extension of lexical scanners to recognize floating-point literals, multi-character relational operators (`==`, `<=`, `!=`), and single/multi-line comments (`//`, `/* ... */`) using stream lookahead and `ungetc()`.
- Solidifies the bridge between Phase 1 (Lexical Analysis / Tokenization) and Phase 2 (Syntax Analysis / Parsing) in the compiler front-end pipeline.
