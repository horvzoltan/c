#include <stdio.h>

int n = 1;
int *pointer_to_n = &n;

int main()
{

    printf("n : %d\n", n);
    *pointer_to_n += 1;
    printf("n : %d\n", *pointer_to_n);
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of char: %lu bytes\n", sizeof(char));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of long: %lu bytes\n", sizeof(long));
    return 0;
}
