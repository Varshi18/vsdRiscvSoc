# Combined RISC-V Instruction Decoding

This file contains the manual decoding of integer instructions from the disassembly outputs of the four C programs (`factorial`, `max_array`, `bitops`, and `bubble_sort`).

### 1. Factorial Program (`factorial_main_objdump.txt`)

| Instruction | Opcode | rd | rs1 | rs2 | funct3 | funct7 | Binary Representation | Description |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`addi sp,sp,-32`** | `0010011` | `x2` | `x2` | | `000` | | `111000000001 00010 000 00010 0010011` | `sp = sp - 32` |
| **`sd ra,24(sp)`** | `0100011` | | `x2` | `x1` | `011` | | `1111110 00001 00010 011 00111 0100011` | Store `ra` at address `sp+24` |
| **`li a5,12`** | `0010011` | `x15` | `x0` | | `000` | | `000000001100 00000 000 01111 0010011` | Load Immediate `12` into `a5` |
| **`sw a5,-20(s0)`** | `0100011` | | `x8` | `x15` | `010` | | `1111110 01111 01000 010 01100 0100011` | Store Word from `a5` at `s0-20` |
| **`jal ra,10328`** | `1101111` | `x1` | | | | | `111110011101 11111111 00001 1101111` | Jump and Link to `fact` |

### 2. Max Array Program (`max_array_main_objdump.txt`)

| Instruction | Opcode | rd | rs1 | rs2 | funct3 | funct7 | Binary Representation | Description |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`addi s0,sp,64`** | `0010011` | `x8` | `x2` | | `000` | | `000001000000 00010 000 01000 0010011` | `s0 = sp + 64` |
| **`ld a1,0(a5)`** | `0000011` | `x11` | `x15` | | `011` | | `000000000000 01111 011 01011 0000011` | Load Doubleword from `a5+0` into `a1` |
| **`add a5,a5,a4`** | `0110011` | `x15` | `x15` | `x14` | `000` | `0000000` | `0000000 01110 01111 000 01111 0110011` | `a5 = a5 + a4` |
| **`bge a5,a4,...`** | `1100011` | | `x15` | `x14` | `101` | | `0000000 01110 01111 101 00000 1100011` | Branch if `a5 >= a4` |
| **`blt a4,a5,...`** | `1100011` | | `x14` | `x15` | `100` | | `1111101 01111 01110 100 01111 1100011` | Branch if `a4 < a5` |

### 3. Bit Operations Program (`bitops_main_objdump.txt`)

| Instruction | Opcode | rd | rs1 | rs2 | funct3 | funct7 | Binary Representation | Description |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`lui a5,0xa5a5a`** | `0110111` | `x15` | | | | | `10100101101001011010 00000 01101 0110111` | Load `0xa5a5a000` into `a5` |
| **`and a5,a5,a4`** | `0110011` | `x15` | `x15` | `x14` | `111` | `0000000` | `0000000 01110 01111 111 01111 0110011` | `a5 = a5 & a4` |
| **`or a5,a5,a4`** | `0110011` | `x15` | `x15` | `x14` | `110` | `0000000` | `0000000 01110 01111 110 01111 0110011` | `a5 = a5 | a4` |
| **`xor a5,a5,a4`** | `0110011` | `x15` | `x15` | `x14` | `110` | `0000000` | `0000000 01110 01111 110 01111 0110011` | `a5 = a5 ^ a4` |
| **`slliw a5,a5,0x3`**| `0011011` | `x15` | `x15` | | `001` | `0000000` | `0000000 00011 01111 001 01111 0011011` | Shift `a5` left by 3 (32-bit) |

### 4. Bubble Sort Program (`bubble_sort_main_objdump.txt`)

| Instruction | Opcode | rd | rs1 | rs2 | funct3 | funct7 | Binary Representation | Description |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`addi a0,a5,-1888`**| `0010011` | `x10` | `x15` | | `000` | | `100010100000 01111 000 01010 0010011` | `a0 = a5 - 1888` |
| **`sd a1,-64(s0)`** | `0100011` | | `x8` | `x11` | `011` | | `1111110 01011 01000 011 00000 0100011` | Store `a1` at address `s0-64` |
| **`mv a1,a4`** | `0010011` | `x11` | `x14` | | `000` | | `000000000000 01110 000 01011 0010011` | `a1 = a4` (Move) |
| **`sw zero,-20(s0)`**| `0100011` | | `x8` | `x0` | `010` | | `1111110 00000 01000 010 01100 0100011` | Store `0` at address `s0-20` |
| **`sext.w a4,a4`** | `0011011` | `x14` | `x14` | | `000` | `0100000` | `0100000 00000 01110 000 01110 0011011` | Sign-extend 32-bit word in `a4` |
