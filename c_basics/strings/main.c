#include <stdio.h>
#include <string.h>

int main()
{
    char *firstName = "John";
    char lastName[4] = "Doe";
    char name[100];

    lastName[0] = 'B';
    sprintf(name, "%s %s", firstName, lastName);
    if (strncmp(name, "John Boe", 100) == 0)
    {
        printf("Done!\n");
    }
    name[0] = '\0';
    strncat(name, firstName, 4);
    strncat(name, lastName, 20);
    printf("%s\n", name);
    return 0;
}
