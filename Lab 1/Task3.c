#include <stdio.h>
#include <string.h>

void print_size_st()
{
    const char s[4] = "abc";  // Allocate space for the null terminator

    printf("%lu\n", strlen(s));  // Print the length of the string
}

int main()
{
    print_size_st();  // Call the function
    return 0;
}
