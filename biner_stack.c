#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// gcc -o StudiKasus_2 biner_stack.c linked.c stack.c

int main () {
    int dec, r, bin;
    address Stack;
    CreateList(&Stack);

    printf("Masukkan bilangan desimal positif: ");
    scanf("%d", &dec);
    while (dec > 0) {
        r = dec % 2;
        Push (&Stack, r);
        dec = dec / 2;
    }
    printf("\nBiner: ");
    while (!IsEmpty(Stack)) {
        Pop(&Stack, &bin);
        printf("%d", bin);
    }
    printf("\n");
    system("pause");
}