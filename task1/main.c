#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

void read_two_numbers(int* num1, int* num2) {
	int result;

	printf("Input first number: ");
	result = scanf("%d", num1);
	if (result != 1) {
		printf("Error! Input is not a number!");
		exit(1);
	}

    
 	printf("Input second number: ");
	result = scanf("%d", num2);
	if (result != 1) {
		printf("Error! Input is not a number!");
		exit(1);
	}
}

void read_one_number(int* num) {
	printf("Input number: ");
	int result = scanf("%d", num);
	if (result != 1) {
		printf("Error! Input is not a number!");
		exit(1);
	}
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
			result = sqroot(num1);
			break;

		default:
			printf("Error! Invalid operation!\n");
			exit(1);
	}

	printf("Result: %d\n", result);
	
	return 0;
}
