#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "stack.h"

void CreateStack (Stack *S) {
    CreateList(S);
}

int IsStackEmpty(Stack S) {
    return IsEmpty(S);
}

int IsStackFull (Stack S) {
    return 0;
}

void Push (Stack *S, infotype X) {
    Insert_AtFirst(S, X);
}

void Pop (Stack *S, infotype *X) {
    if (!IsStackEmpty(*S)) {
        *X = (*S)->info;
        Delete_AtFirst(S);
    } else {
        printf("Stack underflow.\n");
    }
}
