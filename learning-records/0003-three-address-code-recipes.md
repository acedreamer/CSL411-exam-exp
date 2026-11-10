# Three-Address Code Recipes and Relational Address Alignment

The user established the mental model and modular implementation patterns for Three-Address Code (TAC) generation across assignment partitioning, operator precedence scanning, and relational jumping templates. They understand that relational boolean evaluation uses a four-quadruple template (`if exp goto addr+3`, `T=0`, `goto addr+4`, `T=1`) where the address counter increments by 4 to prevent label overlap across consecutive instructions.

## Evidence
The user analyzed the 3-category decomposition in `intermediate_code_generator.md`, verified the quadruple vs. triple memory and optimization trade-offs, and completed the interactive lesson with exact-length diagnostic mastery checks.

## Implications
Unlocks direct synthesis of intermediate representation code and prepares for bottom-up parsing actions where semantic actions emit quadruples or triples directly into an instruction array during shift-reduce operations.