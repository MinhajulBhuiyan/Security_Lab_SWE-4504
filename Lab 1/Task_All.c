#include <stdio.h>
#include <string.h>

// Original function
void clear_fn(int array_v[])
{
    for(int i=0;i < sizeof(array_v)/sizeof(array_v[0]);++i)
    {
        array_v[i] = 0;
    }
}

// Corrected function
void corrected_clear_fn(int array_v[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        array_v[i] = 0;
    }
}

// Original function
void call_clear_fn()
{
    int sz = 12;
    int dis[12];

    for (int i = 0; i < sz; i++)
    {
        dis[i] = i + 1;
    }

    clear_fn(dis); // Calling the original (incorrect) function

    for (int i = 0; i < sz; i++)
    {
        printf("%d\n", dis[i]); // Incorrect behavior: array not properly cleared
    }
}

// Corrected version
void corrected_call_clear_fn()
{
    size_t sz = 12;
    int dis[12];

    for (size_t i = 0; i < sz; i++)
    {
        dis[i] = i + 1;
    }

    corrected_clear_fn(dis, sz); // Calling the corrected function

    for (size_t i = 0; i < sz; i++)
    {
        printf("%d\n", dis[i]); // Correct behavior: array is cleared
    }
}

// Original function
void take_st()
{
    int sz = 0;
    printf("Enter the size of the string : ");
    scanf("%d",&sz);

    char st[sz];
    gets(st);

    printf("%s",st);
}

// Corrected function
void corrected_take_st()
{
    size_t sz = 0;
    printf("Enter the size of the string: ");
    scanf("%zu", &sz);
    getchar();

    char st[sz + 1];
    printf("Enter the string: ");
    fgets(st, sizeof(st), stdin);

    printf("%s\n", st);
}

// Original function
void print_size_st()
{
    const char s[3] = "abc";
    printf("%d\n", strlen(s));
}

// Corrected function
void corrected_print_size_st()
{
    const char s[4] = "abc";
    printf("%zu\n", strlen(s));
}

// Original function
void null_problem()
{
    char a[16];
    char b[16];
    char c[16];

    strncpy(a, "1234567890abcdef", sizeof(a));
    strcpy(c, a);

    printf("%s\n", c);
}

// Corrected function
void corrected_null_problem()
{
    char a[17];
    char c[17];

    strncpy(a, "1234567890abcdef", sizeof(a) - 1);
    a[16] = '\0';

    strcpy(c, a);
    printf("%s\n", c);
}

int main()
{

    // Task 1
    // call_clear_fn();
    // corrected_call_clear_fn();

    // Task 2
    // take_st();
    // corrected_take_st();

    // Task 3
    // print_size_st();
    // corrected_print_size_st();

    // Task 4
    // null_problem();
    // corrected_null_problem();

    return 0;
}
