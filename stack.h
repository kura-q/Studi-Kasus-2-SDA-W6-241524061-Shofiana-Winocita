#ifndef stack_H
#define stack_H
#include "linked.h"

typedef address Stack;

void CreateStack (Stack *S);
int IsEmpty(Stack S);
void Push (Stack *S, infotype X);
void Pop (Stack *S, infotype *X);

#endif