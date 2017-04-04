/*
 * RomanConverter.h
 *
 *  Created on: Mar 28, 2017
 *      Author: Alex Williams
 */

#include <string.h>
#include <ctype.h>

#ifndef ROMANCONVERTER_H_
#define ROMANCONVERTER_H_

int romanToInt(char *number);

void intToRoman(int num, char* res);

#endif /* ROMANCONVERTER_H_ */
