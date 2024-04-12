// Program to add two numbers. 

#include <stdio.h>

int main() {
    int num1 = 10, num2 = 20, sum;

    // Inline assembly syntax
    __asm__("addl %%ebx, %%eax;" // Assembly instruction
            : "=a" (sum)        // Output operands
            : "a" (num1), "b" (num2) // Input operands
            );

    printf("Sum is: %d\n", sum);
    return 0;
}

