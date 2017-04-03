/*
 * RomanConverter.c
 *
 *  Created on: Mar 28, 2017
 *      Author: Alex Williams
 */

#include "RomanConverter.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int romanToInt(char *number){
	int result = 0,i;
	//int length = (int)strlen(number);
	//printf("i length = %d", length);
	//printf("first char = %c", (char)toupper(number[0]));
	for(i = 0; i < (int)strlen(number); i++){
		switch((char)toupper(number[i])){
			case 'I' :
				printf("I hit");
				result += 1;
				break;
			default :
				return -1;
		}
	}
	//printf("result = %d", result);
	return result;
}

