#ifndef UNIQUE_H
#define UNIQUE_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#ifndef USERNAME
#define USERNAME "unknown_user"
#endif
#ifndef HOSTNAME
#define HOSTNAME "unknown_host"
#endif
#ifndef MACHINE_ID
#define MACHINE_ID "unknown_machine"
#endif
#ifndef BUILD_UTC
#define BUILD_UTC "unknown_time"
#endif
#ifndef BUILD_EPOCH
#define BUILD_EPOCH 0
#endif

// 64-bit FNV-1a hash function
static uint64_t fnv1a64(const char *s) {
    const uint64_t FNV_OFFSET = 1469598103934665603ULL;
    const uint64_t FNV_PRIME = 1099511628211ULL;
    uint64_t h = FNV_OFFSET;
    for (const unsigned char *p = (const unsigned char*)s; *p; ++p) {
        h ^= *p;
        h *= FNV_PRIME;
    }
    return h;
}

// Prints the unique header for each program run
static void uniq_print_header(const char *program_name) {
    time_t now = time(NULL);
    char buf[512];
    int n = snprintf(buf, sizeof(buf), "%s%s%s%s%ld%s%s",
                 USERNAME, HOSTNAME, MACHINE_ID, BUILD_UTC,
                 (long)BUILD_EPOCH, __VERSION__, program_name);
    (void)n;

    uint64_t proof = fnv1a64(buf);

    char rbuf[600];
    snprintf(rbuf, sizeof(rbuf), "%srun_epoch=%ld", buf, (long)now);
    uint64_t runid = fnv1a64(rbuf);

    printf("=== RISC-V Proof Header ===\n");
    printf("User          : %s\n", USERNAME);
    printf("Host          : %s\n", HOSTNAME);
    printf("MachineID     : %s\n", MACHINE_ID);
    printf("BuildUTC      : %s\n", BUILD_UTC);
    printf("BuildEpoch    : %ld\n", (long)BUILD_EPOCH);
    printf("GCC           : %s\n", __VERSION__);
    printf("PointerBits   : %d\n", (int)(8 * sizeof(void*)));
    printf("Program       : %s\n", program_name);
    printf("Proof ID      : 0x%016llx\n", (unsigned long long)proof);
    printf("Run ID        : 0x%016llx\n", (unsigned long long)runid);
    printf("============================\n");
}

#endif
