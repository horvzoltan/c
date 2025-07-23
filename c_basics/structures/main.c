#include <stdio.h>

struct person
{
    char *name;
    int age;
};

int main()
{
    // Now you can use the person struct
    struct person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.", john.name, john.age);

    return 0;
}