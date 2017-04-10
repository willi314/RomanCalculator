/*
 * main.c
 *
 *  Created on: Apr 2, 2017
 *      Author: Alex Williams
 */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "RomanConverter.h"

int main(){
	char input1[10], input2[10], result[10], operator = 0;
	int input1_int = -1, input2_int = -1;

	while(1){
		input1[0] = '\0';
		input2[0] = '\0';
		result[0] = '\0';
		operator = '\0';

		//Taking in input
		printf("Type \"q\" in any field to quit\nInput your first roman numeral\n");
		scanf("%s", input1);
		if(input1[0] == 'q') return 0;
		printf("Input your second roman numeral\n");
		scanf("%s", input2);
		if(input2[0] == 'q') return 0;
		printf("Input your operator\n");
		scanf(" %c", &operator);
		if(operator == 'q') return 0;

		//Converting input values to integers
		input1_int = romanToInt(input1);
		input2_int = romanToInt(input2);
		if(input1_int == -1){
			printf("%s is not a valid roman numeral\n", input1);
			continue;
		}
		if(input2_int == -1){
			printf("%s is not a valid roman numeral\n", input2);
			continue;
		}
		//running math on input values and converting back to roman numerals
		if(operator == '-'){
			if(input1_int - input2_int < 0){
				printf("Result is less than 0\n");
				continue;
			}
			intToRoman(input1_int - input2_int, result);
			printf("%s is the difference between %s and %s\n", result, input1, input2);
		}
		else if(operator == '+'){
			if(input1_int + input2_int > 3999){
				printf("Result is greater than 3999\n");
				continue;
			}
			intToRoman(input1_int + input2_int, result);
			printf("%s is the sum of %s and %s\n", result, input1, input2);
		}
		else{
			printf("%c is not a valid operator\n", operator);
			continue;
		}
	}
	return 0;
}
