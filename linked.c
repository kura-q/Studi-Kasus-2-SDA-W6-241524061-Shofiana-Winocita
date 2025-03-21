#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void CreateList(address *p) {
    *p = NULL;
}

void DestroyList(address *p) {
    address temp;
    while (*p != NULL) {
        temp = *p;
        *p = (*p)->next;
        free(temp);
    }
}

int IsEmpty(address p) {
    return (p == NULL);
}

address Allocate(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void Insert_AtFirst(address *p, infotype X) {
    address P = Allocate(X);
    if (P != NULL) {
        P->next = *p;
        *p = P;
    }
}

void Insert_BetweenBefore(address *p, infotype X, infotype Y) {
    if (*p == NULL) return;
    address P = Allocate(X);
    address Q = *p, Prev = NULL;
    while (Q != NULL && Q->info != Y) {
        Prev = Q;
        Q = Q->next;
    }
    if (Q != NULL && Prev != NULL) {
        Prev->next = P;
        P->next = Q;
    }
}

void Insert_BetweenAfter(address *p, infotype X, infotype Y) {
    address P = Allocate(X);
    address Q = *p;
    while (Q != NULL && Q->info != Y) {
        Q = Q->next;
    }
    if (Q != NULL) {
        P->next = Q->next;
        Q->next = P;
    }
}

void Insert_AtLast(address *p, infotype X) {
    address P = Allocate(X);
    if (*p == NULL) {
        *p = P;
    } else {
        address Q = *p;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void Delete_AtFirst(address *p) {
    if (*p != NULL) {
        address P = *p;
        *p = P->next;
        free(P);
    }
}

void Delete_BetweenBefore(address *p, infotype Y) {
    if (*p == NULL || (*p)->info == Y) return;
    address Q = *p, Prev = NULL;
    while (Q->next != NULL && Q->next->info != Y) {
        Prev = Q;
        Q = Q->next;
    }
    if (Q->next != NULL) {
        address P = Q;
        Prev->next = Q->next;
        free(P);
    }
}

void Delete_BetweenAfter(address *p, infotype Y) {
    address Q = *p;
    while (Q != NULL && Q->info != Y) {
        Q = Q->next;
    }
    if (Q != NULL && Q->next != NULL) {
        address P = Q->next;
        Q->next = P->next;
        free(P);
    }
}

void Delete_AtLast(address *p) {
    if (*p == NULL) return;
    address Q = *p, Prev = NULL;
    while (Q->next != NULL) {
        Prev = Q;
        Q = Q->next;
    }
    if (Prev == NULL) {
        *p = NULL;
    } else {
        Prev->next = NULL;
    }
    free(Q);
}

void Delete_Value(address *p, infotype X) {
    if (*p == NULL) return;
    address Q = *p, Prev = NULL;
    while (Q != NULL && Q->info != X) {
        Prev = Q;
        Q = Q->next;
    }
    if (Q != NULL) {
        if (Prev == NULL) {
            *p = Q->next;
        } else {
            Prev->next = Q->next;
        }
        free(Q);
    }
}

void Tampil_List (address p) {
    address P = p;
    while (P != NULL) {
        printf("%d ", P->info);
        P = P->next;
    }
    printf("\n");
}

int NbElmt (address p){
    if (p == NULL) {
        return 0;
    } else {
        return 1 + NbElmt(p->next);
    }
}

