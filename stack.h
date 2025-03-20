#ifndef STACK_H
#define STACK_H

#include "linked.h"


void initStack(address* p);
void isiStackNode(address* p, infotype value);
int isEmptyStack(address p);
void push(address* p, address SNew);
int pop(address* p, infotype* X);
void printNode(address* p, infotype* X);
void decimalToBinary(infotype num, address* p);
void printBinary(address* p);

#endif
