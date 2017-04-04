/*
 * RomanConverter.c

 *
 *  Created on: Mar 28, 2017
 *      Author: Alex Williams
 */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "RomanConverter.h"

int romanToInt(char *number){
	int result = 0,i;
	//int length = (int)strlen(number);
	//printf("i length = %d", length);
	//printf("first char = %c", (char)toupper(number[0]));
	for(i = 0; i < (int)strlen(number); i++){
		switch((char)toupper(number[i])){
			case 'I' :
				//printf("I hit");
				result += 1;
				break;
			default :
				return -1;
		}
	}
	//printf("result = %d", result);
	return result;
}



void intToRoman(int num, char* res){
    int del[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char * sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int i = 0;
    while (num){
        while (num/del[i]){
            strcat(res, sym[i]);
            num -= del[i];
        }
        i++;
    }
    return;
}



