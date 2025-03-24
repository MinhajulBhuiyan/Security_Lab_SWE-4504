#include <stdio.h>
#include <stdlib.h> 

int main() 
{
    // Fix: 1
    char fullName[] = "Md. Ishmam Uddin";
    char *ptrName = fullName;
    printf("My name is %s\n", ptrName);

    int *ptrSalary = (int *)malloc(sizeof(int));
    if (ptrSalary == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fix: 2
    *ptrSalary = 1000;
    printf("My salary is %d\n", *ptrSalary);

    free(ptrSalary);
    ptrSalary = NULL;  


    // Fix: 3
    ptrSalary = (int *)malloc(sizeof(int));
    if (ptrSalary == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *ptrSalary = 2000;
    printf("After promotion my salary will be %d\n", *ptrSalary);
    free(ptrSalary);  
    ptrSalary = NULL;


    // Fix: 4
    char *alphabet = (char *)malloc(27 * sizeof(char));  
    if (alphabet == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        alphabet[i] = i + 'A';
    }
    alphabet[26] = '\0'; 


    // Fix: 5
    char *revAlphabet = (char *)malloc(27 * sizeof(char));  
    if (revAlphabet == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(alphabet);  
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        revAlphabet[i] = 'Z' - i;
    }
    revAlphabet[26] = '\0'; 

    printf("%s\n", revAlphabet);

    free(alphabet);
    free(revAlphabet);

    return 0;
}