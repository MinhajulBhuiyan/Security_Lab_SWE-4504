#include <stdio.h>
#include <string.h>

void null_problem()
{
    char a[17];  // Allocate enough space for 16 characters + 1 for null terminator
    char c[17];

    strncpy(a, "1234567890abcdef", sizeof(a) - 1);  // Copy only 16 characters
    a[16] = '\0';  // Manually add null terminator

    strcpy(c, a);  // Copy a to c

    printf("%s\n", c);  // Print the content of c
}

int main()
{
    null_problem();  // Call the function
    return 0;
}
