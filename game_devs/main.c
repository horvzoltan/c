#include <stdio.h>

// Define the CTRL_KEY macro
#define CTRL_KEY(k) ((k) & 0x1f)

int main()
{
    char input_char = 'A';                    // Example input character 'A'
    char control_char = CTRL_KEY(input_char); // Apply CTRL_KEY macro

    // Print the original and control characters
    printf("Original character: %c (ASCII: %d)\n", input_char, input_char);
    printf("Control character: %c (ASCII: %d)\n", control_char, control_char);

    return 0;
}
