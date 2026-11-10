# CSL411 Exam Exp Portal & GitHub Deployment Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Create a clean, responsive home page (`index.html`), optimize mobile/desktop layouts, configure `.gitignore` and `README.md`, and deploy to a new public GitHub repository named "CSL411 exam exp" with GitHub Pages configured.

**Architecture:** A static, zero-dependency editorial web portal designed with Tufte aesthetics, semantic HTML5, shared CSS with animated theme toggle, deployed directly to GitHub Pages from the repository root.

**Tech Stack:** HTML5, CSS3 (CSS Custom Properties & Media Queries), Vanilla JavaScript, Git, GitHub CLI (`gh`).

## Global Constraints
- Clean, minimal editorial design matching existing `assets/style.css` and `assets/theme.js`.
- Responsive layout supporting viewports from 320px mobile to 1440px desktop.
- Exclude unwanted markdown files (`calculator_lex_yacc.md`, `constant_propagation.md`, `first_of_grammar.md`, `intermediate_code_generator.md`, `shift_reduce_parser.md`, `explanations/`) via `.gitignore`.
- Repository name must be exactly `CSL411 exam exp`.
- GitHub Pages must be activated on `main` branch root, with the live URL saved in the repository's About section metadata.

---

### Task 1: Clean Home Portal (`index.html`) & Cross-Device Optimization

**Files:**
- Create: `index.html`
- Modify: `assets/style.css`
- Modify: `lessons/0001-calculator-lex-yacc-from-scratch.html`
- Modify: `lessons/0002-constant-propagation-from-scratch.html`
- Modify: `lessons/0003-first-set-of-grammar-from-scratch.html`
- Modify: `lessons/0004-intermediate-code-generator-from-scratch.html`
- Modify: `lessons/0005-shift-reduce-parser-from-scratch.html`

**Interfaces:**
- Consumes: `assets/style.css`, `assets/theme.js`
- Produces: `index.html` with navigation to all 5 lessons (`lessons/0001-...` to `lessons/0005-...`) and references (`reference/*`).

- [x] **Step 1: Build `index.html`**
  Create an elegant, minimal landing page with:
  - Header: Course code `CSL411`, Title `Compiler Design Lab Exam Portal`, subtitle describing the 5 core programs.
  - Quick action buttons/links to jump straight to lessons.
  - Clean directory table or cards listing all 5 programs, their core invariant, direct link to lesson, and link to reference cheat sheet.
  - Section linking to `MISSION.md` principles and quick compilation cheat sheet.
  - Theme toggle integration (`assets/theme.js`).

- [x] **Step 2: Optimize `assets/style.css` for Mobile and PC**
  - Verify touch targets for quiz options and buttons ($\ge 44\text{px}$).
  - Implement fluid type scaling and responsive padding for tables and code blocks.
  - Ensure pre blocks allow smooth horizontal scrolling on mobile without breaking page viewport width (`overflow-x: auto`).
  - Add top navigation link "Home" to lesson and reference navigation bars.

- [x] **Step 3: Test and verify layout across resolutions**
  - Verify `index.html` renders cleanly without horizontal overflow.

---

### Task 2: Project Readme, Gitignore, and Clean Documentation

**Files:**
- Create: `README.md`
- Create: `.gitignore`

**Interfaces:**
- Produces: Clean git status free of unneeded raw files, and an informative repository landing readme for visitors.

- [ ] **Step 1: Author `.gitignore`**
  - Ignore compilation artifacts: `*.out`, `*.o`, `*.exe`, `y.tab.c`, `y.tab.h`, `lex.yy.c`.
  - Ignore unwanted raw source markdown files:
    `calculator_lex_yacc.md`
    `constant_propagation.md`
    `first_of_grammar.md`
    `intermediate_code_generator.md`
    `shift_reduce_parser.md`
    `explanations/`
  - Ignore local system artifacts: `.antigravity/`, `.gemini/`, `.vscode/`, `.DS_Store`.

- [ ] **Step 2: Author `README.md`**
  - Concise, clean overview of the CSL411 Compiler Design Lab interactive study portal.
  - Link to the live GitHub Pages website.
  - Table of the 5 experiments with direct links to lessons.
  - Quick compilation commands for LEX, YACC, and GCC.

- [ ] **Step 3: Verify git status**
  - Run `git status` to verify unwanted markdown files are properly suppressed and only web assets/documentation remain.

---

### Task 3: Git Initialization, GitHub Push & Pages Deployment

**Files:**
- Git repository tracking in workspace.

**Interfaces:**
- Consumes: GitHub CLI (`gh`), Git CLI (`git`).
- Produces: Remote repo `https://github.com/acedreamer/CSL411-exam-exp`, GitHub Pages deployment, About section URL configured.

- [ ] **Step 1: Initialize Git and Commit**
  - Initialize repository: `git init -b main`.
  - Stage tracked files: `git add .`.
  - Commit: `git commit -m "feat: complete CSL411 compiler lab interactive learning portal"`.

- [ ] **Step 2: Create Remote GitHub Repository**
  - Execute `gh repo create "CSL411 exam exp" --public --source=. --remote=origin --push`.

- [ ] **Step 3: Enable GitHub Pages & Set About Section**
  - Enable Pages on `main` branch root via `gh api -X POST repos/acedreamer/CSL411-exam-exp/pages -F "source[branch]=main" -F "source[path]=/"` or `gh repo edit`.
  - Set repository homepage and description:
    Description: `Interactive KTU CSL411 Compiler Design Lab zero-memorization study portal and exam guide`
    Homepage URL: `https://acedreamer.github.io/CSL411-exam-exp/`
  - Verify repository details using `gh repo view "CSL411 exam exp"`.
