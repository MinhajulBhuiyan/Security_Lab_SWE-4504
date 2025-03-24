#include <stdio.h>
#include <string.h>

void take_st()
{
    int sz = 0;
    printf("Enter the size of the string: ");
    scanf("%d", &sz);  // Get the size from user

    char st[sz + 1];   // Allocate an array with the size entered +1 for null terminator

    printf("Enter the string: ");
    scanf("%s", st);   // Read the string

    printf("%s\n", st);  // Print the string
}

int main()
{
    take_st();  // Call the function
    return 0;
}
