#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int result = 0;
    float resultArray[100] = {0};
    for (size_t x = 0; x < 100; x++)
    {
        for (size_t i = 0; i < 10000; i++)
        {
            int tripple = 0;
            for (size_t y = 0; y < 3; y++)
            {
                int random_number = rand() % 2;
                tripple += random_number;
            }
            if (tripple == 0 || tripple == 3)
            {
                result++;
            }
            tripple = 0;
        }
        resultArray[x] = (float)result / 100;
        result = 0;
    }
    int isBigger = 0;
    int isSmaller = 0;
    int is25 = 0;
    for (size_t b = 0; b < 100; b++)
    {
        if (resultArray[b] < 25)
        {
            isSmaller++;
        }
        else if (resultArray[b] > 25)
        {
            isBigger++;
        }
        else if (resultArray[b] == 25)
        {
            is25++;
        }
    }

    printf("sizeofarrayinbytes: %zu\n", sizeof(resultArray));
    printf("is bigger: %d\n", isBigger);
    printf("is smaller: %d\n", isSmaller);
    printf("is equal: %d\n", is25);
    return 0;
}
