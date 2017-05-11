#include <stdio.h>
#include "operators.h"
enum OperatorType {ADD, MINUS, MULTIPLY, DIVISION};

int main(){
	FILE *fp = NULL;
	int operand1, operand2, line = 0;
	char operator = ' ';
	float result ;
	float (*function[])(int, int) = {add, minus, mul, div};
	
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = (*function[ADD])(operand1, operand2);
				break;
				case '-':
				result = (*function[MINUS])(operand1, operand2);
				break;
				case '*':
				result = (*function[MULTIPLY])(operand1, operand2);
				break;
				case '/':
				result = (*function[DIVISION])(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

