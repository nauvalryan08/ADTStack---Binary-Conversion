#ifndef STACK_H
#define STACK_H
#include "stack.h"
#include "linked.h"
#include <stdio.h>
#include <malloc.h>

void initStack(address* p) {
	Create_Node(p);
}

void isiNodeStack(address* p, infotype value) {
	Isi_Node(p, value);
}

int isEmptyStack(address p) {
	isEmpty(p);
}

void push(address *p, address SNew) {
	Ins_Awal(p, SNew);
}

int pop(address* p, infotype* X) {
	Del_Awal(p, X);
}

void printNode(address* p, infotype* X) {
	pop(p, X);
	printf("%d", X);
}

void decimalToBinary(infotype num, address* p) {
    address s;
	infotype Sisa = 0;
	while(num > 0){
		if(num != 1){
			Sisa = num % 2;
			initStack(&s);
			isiNodeStack(&s, Sisa);
			push(p, s);
			num = num/2;
		} else {
			Sisa = num % 2;
			initStack(&s);
			isiNodeStack(&s, Sisa);
			push(p, s);
			num--;
		}
	}
}

void printBinary(address* p) {
	if(*p == NULL){
		printf ("P sudah NULL\n");
		return;
	}

	infotype X;
	
	while(*p != NULL){
		pop(p, &X);
		printf("%d", X);
	}
}

#endif
