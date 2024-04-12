#include <stdio.h>

// Simple function to execute the CPUID instruction
void cpuid(int code, unsigned int* a, unsigned int* d) {
    asm volatile("cpuid"
                 : "=a"(*a), "=d"(*d) /* outputs */
                 : "a"(code)          /* input: eax = code */
                 : "ebx", "ecx");     /* clobbers ebx and ecx */
}

int main() {
    unsigned int eax, edx;
    
    // Execute CPUID with 0x1 as the function code to retrieve processor info
    cpuid(0x1, &eax, &edx);
    
    printf("EAX: %08x\nEDX: %08x\n", eax, edx);

    return 0;
}

