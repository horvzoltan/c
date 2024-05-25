#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int result = 0;
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

    printf("percent: %.2f%%", (float)result / 100);
    return 0;
}
