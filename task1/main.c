#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

void read_two_numbers(int* num1, int* num2) {
	printf("Input first number: ");
	scanf("%d", num1);    
 	printf("Input second number: ");
	scanf("%d", num2);
}

void read_one_number(int* num) {
	printf("Input number: ");
	scanf("%d", num);    
}

int main(void) {
	printf("Choose operation(+, -, *, /, f, r): ");
	char operation = getchar();
	getchar();

	int num1, num2, result;
	switch(operation) {
		case '+':
			read_two_numbers(&num1, &num2);	
			result = add(num1, num2);
			break;
		
		case '-':
			read_two_numbers(&num1, &num2);	
			result = subtract(num1, num2);
			break;

		
		case '*':
			read_two_numbers(&num1, &num2);	
			result = multiply(num1, num2);
			break;
		
		case '/':
			read_two_numbers(&num1, &num2);	
			result = divide(num1, num2);
			break;

		case 'f':
			read_one_number(&num1);
			result = factorial(num1);
			break;
	
		case 'r':
			read_one_number(&num1);
			result = sqrt(num1);
			break;

		default:
			printf("Invalid operation!\n");
			exit(1);
	}

	printf("Result: %d\n", result);
	
	return 0;
}
