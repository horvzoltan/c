#include <stdio.h>

void guessNumber(int guess)
{
    if (guess > 555)
    {
        printf("Guess is too high! \n");
    }
    else if (guess < 555)
    {
        printf("Guess is too low! \n");
    }
    else if (guess == 555)
    {
        printf("Guess is correct! \n");
    }
}

int main()
{
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}