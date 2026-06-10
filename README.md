# CS61C Solutions & Notes

> My complete **solutions + personal notes** for UC Berkeley's **CS61C: Great Ideas in Computer Architecture**.
> The course originally tracked the 2020 Fall (FA20) offering; assignments are completed against the latest **Spring 2026** starter.
> Course finished: **2026/06/10**.

If anything here helps you learn, a ⭐ is appreciated.Discussion are welcome 

---

## 🗂 Repository Layout

```text
CS61C_2020fall/
├── disc/                          # Discussion sections 1–13, plus handwritten .c / .s
│   ├── disc1.md  ...  disc13.md
│   ├── disc11_1.c / disc11_TP.c
│   ├── disc12_1.c
│   └── sum_square.s
│
├── sp26-lab-starter/              # Spring 2026 official labs (lab00–lab07)
│   ├── lab00/                     # Unix basics (grep, ps, kill, diff)
│   ├── lab01/                     # C, pointers, memory
│   ├── lab02/                     # RISC-V assembly I
│   ├── lab03/                     # RISC-V assembly II
│   ├── lab04/                     # Floating point / number systems
│   ├── lab05/                     # Data-level parallelism / SIMD
│   ├── lab06/                     # Logisim intro
│   ├── lab07/                     # CPU pipelining
│   └── tools/                     # Grading scripts
│
├── sp26-proj1-starter/            # Project 1: Snek 🐍 (C snake game)
│   ├── src/                       # Implementation
│   ├── interactive-snake/         # Terminal version
│   ├── tests/                     # Unit tests
│   └── tools/
│
├── sp26-proj2-starter/            # Project 2: SIMD Matrix 🚀
│   └── src/
│       ├── abs.s / argmax.s / classify.s / dot.s
│       ├── matmul.s / relu.s / read_matrix.s / write_matrix.s
│       ├── main.s / utils.s
│       └── tests/
│
├── sp26-proj3-starter/            # Project 3: RISC-V CPU in Logisim 🛠
│   └── cpu/
│       ├── regfile.circ           # Register file
│       ├── alu.circ               # ALU
│       ├── branch-comp.circ       # Branch comparator
│       ├── imm-gen.circ           # Immediate generator
│       ├── control-logic.circ     # Control logic
│       ├── partial-load.circ      # Misaligned load
│       ├── partial-store.circ     # Misaligned store
│       ├── mem.circ               # Memory
│       └── cpu.circ               # Single-cycle CPU → then pipelined
│
├── CS61C_basics/                  # Original course basics (lecture + lab)
│   └── lab00–lab11
│
├── c_book/                        # Exercises from *The C Programming Language*
│   ├── hello.c / file_copy.c / detab.c
│   ├── oneword.c / line_counter.c / word_length_histogram.c
│   ├── datarace_ex.c              # Data-race example
│   └── mt_*.c                     # Multithreaded practice
│
├── KR/                            # K&R classic exercises (my_*.c)
│   ├── my_dayofyear.c / my_grep.c / my_tail.c
│   ├── dcl.c / my_dcl.c           # Declarator parser (Ch. 5)
│   └── my_expr.c                  # Expression evaluator
│
├── example/                       # Ad-hoc in-class / self-study snippets
│
└── Untitled                       # Scratchpad
```

---

## ✅ Progress

| Track | Count | Status |
| :--- | :---: | :---: |
| Discussion | 13 / 13 | ✅ |
| Lab | 8 (lab00–lab07) | ✅ |
| Project 1 (Snek) | 1 / 1 | ✅ |
| Project 2 (SIMD) | 1 / 1 | ✅ |
| Project 3 (CPU) | single-cycle + pipelined | ✅ |
| FA20 Steganography | 1 / 1 | ✅ |
| K&R / C-book exercises | many | ✅ |

---

## 🚀 Running the Assignments

Each starter ships with its own `README.md`. The shortest path for each project:

### Lab (`sp26-lab-starter/`)
```bash
cd sp26-lab-starter/lab0X
bash tools/test.sh          # or: python3 tools/run.py
```

### Project 1 — Snek
```bash
cd sp26-proj1-starter
make
python3 tests/...           # unit tests
./interactive-snake/snek    # play a round 🐍
```

### Project 2 — SIMD
```bash
cd sp26-proj2-starter
bash test.sh
python3 unittests.py        # public tests
python3 studenttests.py     # your own tests
```

### Project 3 — Logisim CPU
1. Install [Logisim Evolution](https://github.com/logisim-evolution/logisim-evolution)
2. Open `sp26-proj3-starter/cpu/cpu.circ`

---

## 📖 References

- [CS61C course site (Sp26)](https://inst.eecs.berkeley.edu/~cs61c/)
- *Computer Organization and Design, 5th Edition* — Patterson & Hennessy
- *The C Programming Language, 2nd Edition* — Kernighan & Ritchie
- [RISC-V specifications](https://riscv.org/technical/specifications/)
- [Logisim Evolution](https://github.com/logisim-evolution/logisim-evolution)

Thanks to CS61C teams.