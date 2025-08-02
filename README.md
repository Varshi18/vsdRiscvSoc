# RISC-V Uniqueness Test Submission

This repository contains the unique_test.c source file for the RISC-V toolchain evaluation.

## ✅ Compile Command Used

bash
riscv64-unknown-elf-gcc -O2 -Wall -march=rv64imac -mabi=lp64 \
-DUSERNAME="\"$(id -un)\"" -DHOSTNAME="\"$(hostname -s)\"" \
unique_test.c -o unique_test


## 📤 Output from spike pk ./unique_test
bbl loader
RISC-V Uniqueness Check
User: VLSI
Host: Varshith
UniqueID: 0x88d85ad89f8d9226
