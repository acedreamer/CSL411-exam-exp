# Core Models Established for Calculator and Constant Propagation

The user has reviewed and established the structural contracts for both the LEX & YACC Calculator and the Constant Propagation engine. They understand that `calc.l` and `calc.y` communicate via `y.tab.h`, `yylval`, and semantic pseudo-variables, while Constant Propagation functions as a straight-line quadruple spreadsheet where evaluation is guarded by `isdigit()` and propagated downstream strictly for `j > i`.
