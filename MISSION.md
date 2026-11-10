# Mission: Master Compiler Design Lab (CSL411) From Scratch

## Why
The user needs to master the core logic of all five KTU Compiler Design lab programs so deeply that they can sit in an exam room, lab evaluation, or technical interview and reconstruct the complete, bug-free C, LEX, and YACC code on a blank sheet or terminal without relying on internet access or notes.

## Success looks like
- Reconstruct `calc.l` and `calc.y` completely from scratch without reference.
- Explain the role of `yylval`, `y.tab.h`, `%left`, and the parsing stack in under 60 seconds.
- Accurately execute the four-command compilation pipeline (`yacc -d`, `lex`, `gcc`, `./a.out`) on the first attempt without compilation errors.
- Defend against examiner viva traps regarding operator precedence, division by zero, and shift-reduce ambiguity.

## Constraints
- Zero rote memorization: each program must be learned via structural mental models and algorithmic invariants.
- High recall durability: lessons must produce storage strength, not just temporary fluency.
- Linux/POSIX toolchain conventions (lex/flex, yacc/bison, gcc).

## Out of scope
- Full LR(1)/LALR(1) parsing table generation theory (only the operational mechanics needed for lab implementation and viva).
- Arbitrary floating-point arithmetic or complex multi-character identifiers for the calculator (strictly integer expressions as scoped in the lab).
