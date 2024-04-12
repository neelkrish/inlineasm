#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
// Function containing inline assembly to add two numbers
int inline_asm_add(int num1, int num2) {
    int sum;

    __asm__("addl %%ebx, %%eax;"
            : "=a" (sum)
            : "a" (num1), "b" (num2)
            );

    return sum;
}

// Fuzzer function to test the inline assembly with random numbers
void fuzzer() {
    int test_cases = 100; // Number of test cases
    int num1, num2, result;
    
    // Seed the random number generator
    srand(time(NULL));

    for(int i = 0; i < test_cases; i++) {
        // Generate random numbers
        num1 = rand();
        num2 = rand();

        // Call the inline assembly function
        result = inline_asm_add(num1, num2);

        // Print results - You can add more sophisticated checks here
        printf("Test case %d: %d + %d = %d\n", i+1, num1, num2, result);

        // Simple overflow check
        if ((num2 > 0 && num1 > INT_MAX - num2) || 
            (num2 < 0 && num1 < INT_MIN - num2)) {
            printf("Warning: Potential overflow detected in test case %d\n", i+1);
        }
    }
}

int main() {
    // Run the fuzzer
    fuzzer();
    return 0;
}

