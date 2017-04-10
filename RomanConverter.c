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

int romanSingleDigitValue(char digit){
	switch (digit) {
	        case 'I': return 0;
	        case 'V': return 1;
	        case 'X': return 2;
	        case 'L': return 3;
	        case 'C': return 4;
	        case 'D': return 5;
	        case 'M': return 6;
	        default : return -1;
	        }
}

int romanCompoundDigitValue(char *digit){
		if(strcmp(digit,"IV") == 0) return 0;
		else if(strcmp(digit,"IX") == 0) return 1;
		else if(strcmp(digit,"XL") == 0) return 2;
		else if(strcmp(digit,"XC") == 0) return 3;
		else if(strcmp(digit,"CD") == 0) return 4;
		else if(strcmp(digit,"CM") == 0) return 5;
		else return -1;
}

int romanToInt(char *num){
	char number[10] = "";
	strcpy(number, num);
	int singleSymbolValues[] = {1, 5, 10, 50, 100, 500, 1000};
	int compoundSymbolValues[] = {4, 9, 40, 90, 400, 900};
	char compoundSymbol[3] = "";
	int result = 0,currentDigit = 0, nextDigit = 0,previousCompound = 10, previousDigit = 10, consecutiveDigits = 0, i;

	for(i = 0; i < strlen(number); i++){
		number[i] = toupper(number[i]);
	}

	for(i = 0; i < strlen(number); i++){
		currentDigit = romanSingleDigitValue(number[i]);
		if(currentDigit == -1) return -1;
		if(i + 1 == strlen(number)){
			if(previousCompound / 2 == currentDigit / 2) return -1;
			result += singleSymbolValues[currentDigit];
		}
		else{
			nextDigit = romanSingleDigitValue(number[i+1]);
			//Check for invalid number of consecutive digits (IIII,VV,etc.)
			if(nextDigit == currentDigit) consecutiveDigits++;
			else consecutiveDigits = 0;
			if(consecutiveDigits == 3 || (currentDigit % 2 == 1 && consecutiveDigits == 1)) return -1;

			if(nextDigit > currentDigit){
				strncpy(compoundSymbol, number + i, 2);
				currentDigit = romanCompoundDigitValue(compoundSymbol);
				//Check for invalid consecutive compound roman digits and single digits followed by compound(VIV, IXIV)
				if(currentDigit / 2 == previousCompound / 2 || previousCompound < currentDigit
						|| currentDigit == -1 || previousDigit / 2 == currentDigit / 2) return -1;

				previousCompound = currentDigit;
				result += compoundSymbolValues[previousCompound];
				i++;
			}
			else{
				//Checks for invalid compund digits followed by single digits (IVI, IXI)
				if(previousCompound / 2 == currentDigit / 2) return -1;
				previousDigit = currentDigit;
				result += singleSymbolValues[currentDigit];
			}
		}
	}
	return result;
}



void intToRoman(int num, char *res){
	if(num == 0){
		strcat(res, "Nulla");
		return;
	}
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char * symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int i = 0;
    while (num){
        while (num/values[i]){
            strcat(res, symbols[i]);
            num -= values[i];
        }
        i++;
    }
    return;
}



