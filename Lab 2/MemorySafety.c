#include <stdio.h>
#include <stdlib.h>  

int main() 
{
    char *ptrName = NULL;
    char fullName[] = "Md. Ishmam Uddin";
    ptrName = fullName;  // Assign fullName to ptrName
    printf("My name is %s\n", ptrName);

    int *ptrSalary = (int*)malloc(sizeof(int));

    if (ptrSalary == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptrSalary = 1000;
    printf("My salary is %d\n", *ptrSalary);

    free(ptrSalary);
    ptrSalary = NULL;

    // Re-allocate memory
    ptrSalary = (int*)malloc(sizeof(int));  
    if (ptrSalary == NULL) {
        printf("Memory allocation failed for promotion!\n");
        return 1;
    }
    *ptrSalary = 2000;
    printf("After promotion my salary will be %d\n", *ptrSalary);

    free(ptrSalary);
    ptrSalary = NULL;

    // (26 letters + null terminator)
    char* alphabet = (char*)malloc(27 * sizeof(char)); 
    if (alphabet == NULL) {
        printf("Memory allocation failed for alphabet!\n");
        return 1;
    }

    // A-Z and null terminate
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'A' + i;
    }
    alphabet[26] = '\0';  // Null-terminate

    printf("%s\n", alphabet);

    free(alphabet);

    return 0;
}
