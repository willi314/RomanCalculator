/*
 * main.c
 *
 *  Created on: Apr 2, 2017
 *      Author: boris
 */

#include "RomanConverter.h"
#include <string.h>
#include <stdio.h>

int main(){
	char *num = "i";
	int i = romanToInt(num);
	printf("%s == %d", num, i);
	return 0;
}
