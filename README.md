# Weather Station Bit-Converter – ITP / UFRN

This repository contains a C program developed for an assignment in **Introduction to Programming Techniques** (*Introdução às Técnicas de Programação – ITP*), part of the Bachelor's degree in Information Technology (**BTI**) at the Federal University of Rio Grande do Norte (**UFRN**).

The program simulates a weather station data receiver that converts $B$-bit binary strings encoded in **Two's Complement** into signed decimal temperatures while tracking historical minimum and maximum values in real-time.

---

## Overview

* Reads $N$ (number of readings) and $B$ (bit width per reading).
* Parses each $B$-bit binary payload directly into its signed decimal equivalent:
  * Bit 0 (Most Significant Bit) represents a negative weight: $-2^{B-1}$.
  * Bits $1$ through $B-1$ contribute positive weights: $+2^{B-1-j}$.
* Uses 64-bit integer bitwise operations (`1LL << shift`) to ensure safe bit-shifting without overflow.
* Dynamically tracks minimum and maximum temperatures with $O(1)$ memory overhead.

---

## Input & Output Format

### Input
* The first line contains two integers: $N$ ($1 \le N \le 1000$) and $B$ ($2 \le B \le 16$).
* The following $N$ lines each contain a $B$-bit binary string composed of `0`s and `1`s with no spaces.

### Output
* $N$ lines displaying the signed decimal value of each temperature reading.
* A line formatted as `Minima: X` showing the lowest recorded temperature.
* A line formatted as `Maxima: Y` showing the highest recorded temperature.

---

## Compilation & Execution

To compile and run the program using `gcc`:

```bash
# Compile
gcc -O2 main.c -o weather_station

# Run
./weather_station
