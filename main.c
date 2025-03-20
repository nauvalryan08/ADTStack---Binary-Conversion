#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	int loop = 1;
	while (loop == 1 ) {
		infotype value; 
		address First;
		char input;
		printf("Masukan bilangan desimal yang ingin di konversi: ");
		scanf("%d", &value);
		decimalToBinary(value, &First);
		printf("\n\n\nHasil konversi Desimal->Biner : ");
		printBinary(&First);
		
		printf("\nApakah anda ingin mencoba lagi('Y'/'T'): ");
		scanf("%c", &input);
		if(input == 'T') {
			loop = 0;
		}
	}  	
	
	return 0;

}
