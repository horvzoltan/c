#include <stdio.h>

int main()
{
    int firstNumber = 420;
    int secondNumber = 504;

    for (size_t i = 1; i <= firstNumber / 2; i++)
    {
        if (firstNumber % i == 0 && secondNumber % i == 0)
        {
            printf("number: %zu\n", i);
        }
    }

    return 0;
}
