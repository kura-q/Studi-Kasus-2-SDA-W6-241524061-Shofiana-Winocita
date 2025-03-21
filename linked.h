#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <stdlib.h>

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

void CreateList(address *p);
void DestroyList(address *p);
int IsEmpty(address p);
address Allocate(infotype X);

void Insert_AtFirst(address *p, infotype X);
void Insert_BetweenBefore(address *p, infotype X, infotype Y);
void Insert_BetweenAfter(address *p, infotype X, infotype Y);
void Insert_AtLast(address *p, infotype X);

void Delete_AtFirst(address *p);
void Delete_BetweenBefore(address *p, infotype Y);
void Delete_BetweenAfter(address *p, infotype Y);
void Delete_AtLast(address *p);
void Delete_Value(address *p, infotype X);

void Tampil_List (address p);
int NbElmt (address p);

#endif