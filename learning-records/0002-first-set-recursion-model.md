# FIRST Set Recursive Expansion and Left-Recursion Model

The user has established the core mental model and algorithmic invariants for calculating the FIRST set of a context-free grammar. They understand that non-terminals (identified via `<ctype.h>` `isupper()`) recursively unpack the leading symbol `p[i][2]` of matching productions, while terminals and the epsilon marker `$` serve as base-case leaf nodes that append directly into accumulator array `f` under the deduplication guard `add_to_result()`. This foundational understanding unlocks LL(1) predictive parsing and provides the prerequisite dependency for computing FOLLOW sets in subsequent compiler passes.

## Implications
- Establishes that grammars must be free of immediate left recursion ($A \to A\alpha$) to prevent infinite recursion and stack exhaustion during recursive descent.
- Provides the foundational prerequisite for Program 4 (Shift-Reduce Parser) and downstream parsing table generation.
