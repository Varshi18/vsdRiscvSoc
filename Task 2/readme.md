
# RISC-V Local Setup Check and ISA Decoding

This folder contains the deliverables for the second task, proving the local RISC-V setup by running, disassembling, and decoding programs.

## Toolchain Versions

### Spike Version

The installed version is **Spike RISC-V ISA Simulator 1.1.1-dev**. The `--version` flag is not recognized by this build; this information was obtained from the `spike --help` command.

```
Spike RISC-V ISA Simulator 1.1.1-dev

usage: spike [host options] \<target program\> [target options]
Host Options:
\-p\<n\>                  Simulate \<n\> processors [default 1]
\-m\<n\>                  Provide \<n\> MiB of target memory [default 2048]
...

```

### GCC Version

```
Using built-in specs.
COLLECT\_GCC=riscv64-unknown-elf-gcc
COLLECT\_LTO\_WRAPPER=/home/VLSI/riscv\_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86\_64-linux-ubuntu14/bin/../libexec/gcc/riscv64-unknown-elf/8.3.0/lto-wrapper
Target: riscv64-unknown-elf
Configured with: /scratch/carsteng/freedom-tools-master/obj/x86\_64-linux-ubuntu14/build/riscv-gnu-toolchain/riscv-gcc/configure --target=riscv64-unknown-elf --host=x86\_64-linux-gnu --prefix=/scratch/carsteng/freedom-tools-master/obj/x86\_64-linux-ubuntu14/install/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86\_64-linux-ubuntu14 --with-pkgversion='SiFive GCC 8.3.0-2019.08.0' --with-bugurl=[https://github.com/sifive/freedom-tools/issues](https://github.com/sifive/freedom-tools/issues) --disable-shared --disable-threads --enable-languages=c,c++ --enable-tls --with-newlib --with-sysroot=/scratch/carsteng/freedom-tools-master/obj/x86\_64-linux-ubuntu14/install/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86\_64-linux-ubuntu14/riscv64-unknown-elf --with-native-system-header-dir=/include --disable-libmudflap --disable-libssp --disable-libquadmath --disable-libgomp --disable-nls --disable-tm-clone-registry --src=../riscv-gcc --without-system-zlib --enable-checking=yes --enable-multilib --with-abi=lp64d --with-arch=rv64imafdc CFLAGS=-O2 CXXFLAGS=-O2 'CFLAGS\_FOR\_TARGET=-Os  -mcmodel=medany' 'CXXFLAGS\_FOR\_TARGET=-Os  -mcmodel=medany'
Thread model: single
gcc version 8.3.0 (SiFive GCC 8.3.0-2019.08.0)

````
---

## Compile Commands

The following commands were used to compile the C source files. The environment variables (`$U`, `$H`, etc.) were set beforehand in the shell to ensure each build was unique.

### Factorial
```bash
riscv64-unknown-elf-gcc -O0 -g -march=rv64imac -mabi=lp64 \
-DUSERNAME="\"$U\"" -DHOSTNAME="\"$H\"" -DMACHINE_ID="\"$M\"" \
-DBUILD_UTC="\"$T\"" -DBUILD_EPOCH=$E \
factorial.c -o factorial
````

### Max Array

```bash
riscv64-unknown-elf-gcc -O0 -g -march=rv64imac -mabi=lp64 \
-DUSERNAME="\"$U\"" -DHOSTNAME="\"$H\"" -DMACHINE_ID="\"$M\"" \
-DBUILD_UTC="\"$T\"" -DBUILD_EPOCH=$E \
max_array.c -o max_array
```

### Bit Operations

```bash
riscv64-unknown-elf-gcc -O0 -g -march=rv64imac -mabi=lp64 \
-DUSERNAME="\"$U\"" -DHOSTNAME="\"$H\"" -DMACHINE_ID="\"$M\"" \
-DBUILD_UTC="\"$T\"" -DBUILD_EPOCH=$E \
bitops.c -o bitops
```

### Bubble Sort

```bash
riscv64-unknown-elf-gcc -O0 -g -march=rv64imac -mabi=lp64 \
-DUSERNAME="\"$U\"" -DHOSTNAME="\"$H\"" -DMACHINE_ID="\"$M\"" \
-DBUILD_UTC="\"$T\"" -DBUILD_EPOCH=$E \
bubble_sort.c -o bubble_sort
```

-----

## Proof of Uniqueness Note

The **ProofID** and **RunID** values, which are generated based on user, host, machine, and time variables, are visible in each program's output screenshot. This confirms that each build and run is unique.
