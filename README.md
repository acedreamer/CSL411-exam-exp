# CSL411 Compiler Design Lab Exam Portal

[![Live Demo](https://img.shields.io/badge/Live_Portal-GitHub_Pages-2ea44f?style=for-the-badge&logo=github)](https://acedreamer.github.io/CSL411-exam-exp/)
[![KTU B.Tech](https://img.shields.io/badge/KTU_B.Tech-CSL411_S7%2FS8-blue?style=for-the-badge)](https://acedreamer.github.io/CSL411-exam-exp/)
[![Zero External Dependencies](https://img.shields.io/badge/Zero_Dependencies-Pure_HTML5%2FCSS3%2FJS-orange?style=for-the-badge)](https://acedreamer.github.io/CSL411-exam-exp/)

> **Live Deployment:** [https://acedreamer.github.io/CSL411-exam-exp/](https://acedreamer.github.io/CSL411-exam-exp/)

An interactive, zero-memorization laboratory study portal and exam-readiness guide engineered for the **APJ Abdul Kalam Technological University (KTU) B.Tech Computer Science & Engineering Compiler Design Lab (CSL411)**.

---

## 🎯 The Zero-Memorization Philosophy

Traditional lab prep forces students to memorize hundreds of lines of cryptic C, LEX, and YACC code. In an exam or viva room, memorized code easily collapses under stress.

This portal re-engineers every lab program into **mental models**, **algorithmic invariants**, and **data structures**. By internalizing *why* tokens flow through `yylval` or *how* a stack automaton prunes handles, you can sit before a blank terminal or sheet of paper and reconstruct complete, bug-free implementations from scratch.

---

## 📚 Laboratory Programs Matrix

| # | Program Name | Implementation | Core Invariant & Theoretical Model | Interactive Lesson | Quick Cheat Sheet |
|---|--------------|----------------|------------------------------------|:------------------:|:-----------------:|
| **01** | **Calculator Using LEX & YACC** | LEX (Flex) & YACC (Bison) | Three-way handshake: `yylval` token mailbox, `y.tab.h` header synchronization, and `%left` bottom-up operator precedence disambiguation | [Lesson 01](lessons/0001-calculator-lex-yacc-from-scratch.html) | [Cheat Sheet 01](reference/calc-lex-yacc-reference.html) |
| **02** | **Constant Propagation & Folding** | ANSI C | Quadruple spreadsheet data model (`op`, `op1`, `op2`, `res`, `flag`), compile-time `isdigit()` folding guard, and forward substitution domino cascade ($j > i$) | [Lesson 02](lessons/0002-constant-propagation-from-scratch.html) | [Cheat Sheet 02](reference/constant-propagation-reference.html) |
| **03** | **FIRST Set of Grammar** | ANSI C | Direct production indexing `p[i][2]`, `<ctype.h>` `isupper()` non-terminal recursion, epsilon (`$`) bubbling, and duplicate suppression via `addToResultSet()` | [Lesson 03](lessons/0003-first-set-of-grammar-from-scratch.html) | [Cheat Sheet 03](reference/first-of-grammar-reference.html) |
| **04** | **Intermediate Code Generator (TAC)** | ANSI C | Two-pass precedence scanning (`*`, `/` prioritized before `+`, `-`), temporary variable synthesis (`t1`, `t2`), and 4-quadruple relational branching templates | [Lesson 04](lessons/0004-intermediate-code-generator-from-scratch.html) | [Cheat Sheet 04](reference/intermediate-code-reference.html) |
| **05** | **Shift-Reduce Parser** | ANSI C | Dual-pointer bottom-up stack automaton, greedy handle pruning, `while(check())` cascading reduction guard, and `k >= 3` memory underflow protection | [Lesson 05](lessons/0005-shift-reduce-parser-from-scratch.html) | [Cheat Sheet 05](reference/shift-reduce-reference.html) |

---

## ⚡ Terminal Compilation Pipelines

Ready-to-use compilation commands for POSIX environments (Linux, macOS, WSL, Ubuntu):

```bash
# ========================================================
# 1. LEX & YACC Arithmetic Calculator
# ========================================================
yacc -d calc.y                   # Step 1: Generates y.tab.c and header y.tab.h
lex calc.l                       # Step 2: Generates lex.yy.c tokenizer
gcc lex.yy.c y.tab.c -w -o calc  # Step 3: Compiles and links both passes
./calc                           # Step 4: Run interactive calculator

# ========================================================
# 2. Constant Propagation & Optimization
# ========================================================
gcc constant_propagation.c -o const_prop && ./const_prop

# ========================================================
# 3. FIRST Set of Context-Free Grammar
# ========================================================
gcc first_of_grammar.c -o first_set && ./first_set

# ========================================================
# 4. Intermediate Code Generator (Three-Address Code)
# ========================================================
gcc intermediate_code.c -o icg && ./icg

# ========================================================
# 5. Shift-Reduce Parser Simulation
# ========================================================
gcc shift_reduce_parser.c -o srp && ./srp
```

---

## ✨ Features & Architecture

- **Tufte-Style Editorial Typography**: Clean, high-legibility interface using system font stacks (`Charter`, `Georgia`, `-apple-system`) and warm, muted color palettes.
- **Theme Toggle Engine**: Integrated light and dark modes with persistent `localStorage` support and smooth animated transitions.
- **Interactive In-Browser Quizzes**: Diagnostic checkpoints embedded throughout lessons that test memory guards, edge cases, and algorithmic decisions with instant score feedback.
- **Fully Responsive Layout**: Adaptive layouts tailored for both mobile devices ($\ge 320\text{px}$) with horizontal code scroll and desktop displays ($\le 1440\text{px}$).
- **Zero Build Tools or External Dependencies**: Built with pure HTML5, CSS3 Custom Properties, and Vanilla JavaScript. Fast, secure, and ready for static hosting.

---

## 📂 Repository Structure

```text
├── index.html                # Main interactive study portal landing page
├── assets/
│   ├── style.css             # Unified Tufte design tokens, components & responsive queries
│   └── theme.js              # Theme switcher with local storage persistence
├── lessons/                  # Interactive zero-memorization master lessons
│   ├── 0001-calculator-lex-yacc-from-scratch.html
│   ├── 0002-constant-propagation-from-scratch.html
│   ├── 0003-first-set-of-grammar-from-scratch.html
│   ├── 0004-intermediate-code-generator-from-scratch.html
│   └── 0005-shift-reduce-parser-from-scratch.html
├── reference/                # High-density exam cheat sheets & viva checklists
│   ├── calc-lex-yacc-reference.html
│   ├── constant-propagation-reference.html
│   ├── first-of-grammar-reference.html
│   ├── intermediate-code-reference.html
│   └── shift-reduce-reference.html
├── learning-records/         # Deep dive architecture notes & theoretical invariants
│   ├── 0001-calculator-and-constant-propagation-models.md
│   ├── 0002-first-set-recursion-model.md
│   ├── 0003-three-address-code-recipes.md
│   └── 0004-shift-reduce-stack-automaton.md
├── MISSION.md                # Pedagogical objectives & viva defense strategies
├── RESOURCES.md              # Dragon Book, Levine O'Reilly & Bison citations
├── NOTES.md                  # Quick exam-day revision pointers
├── .gitignore                # Exclusion of build artifacts & raw markdown drafts
└── README.md                 # Project documentation and hub
```

---

## 🚀 Running Locally

No installation, Node.js, or bundlers required:

1. Clone or download the repository:
   ```bash
   git clone https://github.com/acedreamer/CSL411-exam-exp.git
   cd CSL411-exam-exp
   ```
2. Open `index.html` in your favorite web browser:
   - Double click `index.html`, or
   - Start any local static server:
     ```bash
     python -m http.server 8000
     # Navigate to http://localhost:8000 in your browser
     ```

---

## 📖 Curated Primary References

- **Dragon Book** (*Compilers: Principles, Techniques, and Tools* by Aho, Lam, Sethi, Ullman) – Chapter 4 (Syntax Analysis) and Chapter 6 (Intermediate-Code Generation).
- **lex & yacc (2nd Ed.)** by John Levine, Tony Mason, Doug Brown (O'Reilly) – Token propagation, precedence declarations, and shift-reduce ambiguity resolution.
- **GNU Bison Manual** – Semantic value union mechanisms and `y.tab.h` header contracts.

---

## 🛡️ License

Educational open-source material developed for academic preparation in KTU B.Tech Computer Science and Engineering curriculum.
