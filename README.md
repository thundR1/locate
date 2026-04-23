# ⚡ Locate is an Aho–Corasick Pattern Matching Engine (ICU Powered)

A high-performance **multi-pattern string matching engine** implemented in C++ using the **Aho–Corasick automaton**, with full **Unicode grapheme support via ICU**.

It supports reading patterns and text from files and efficiently finds all occurrences of multiple patterns in a single pass.

---

## 🚀 Features

- 🔍 Multi-pattern string matching (Aho–Corasick algorithm)
- 🌍 Full Unicode support (grapheme-level matching)
- 🧠 ICU-powered text segmentation
- 📂 File-based input (patterns + text from `.txt` files)
- ⚡ Efficient failure-link automaton
- 🧵 Handles overlapping pattern matches
- 💻 CLI-based execution

---

## 📦 Dependencies

- C++23
- ICU Library

This project requires ICU (International Components for Unicode).

Install ICU (Linux):
```bash
sudo apt install libicu-dev
```

## Usage
Clone my repo using:
```bash
git clone https://github.com/thundR1/locate.git
```
make sure you are inside the `locate` folder.
### Then Build Using:
```bash
cmake -S . -B build
```
```bash
cmake --build build
```
### Then Run Using:
```bash
./build/locate <patterns_file_path> <text_file_path>
```
