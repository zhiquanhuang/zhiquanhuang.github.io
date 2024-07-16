// dfasfsds.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void extractNumberWithTwoDecimalPlaces(const char *input, char *output) {
    const char *numberStart = NULL;
    const char *numberEnd = NULL;
    int hasDecimal = 0;


    for (const char *p = input; *p; p++) {
        if (isdigit(*p)) {
            if (numberStart == NULL) {
                numberStart = p;
            }
            numberEnd = p;
        } else if (*p == '.' && numberEnd != NULL) {
            hasDecimal = 1;
            numberEnd = p;
        } else if (numberEnd != NULL) {
            break;
        }
    }

    if (numberStart == NULL) {
        strcpy(output, "");
        return;
    }

    if (hasDecimal) {
        numberEnd++;
        while (isdigit(*numberEnd)) {
            numberEnd++;
        }
    }

    int len = numberEnd - numberStart;
    if (hasDecimal) {
        const char *decimalStart = strchr(numberStart, '.');
        int decimalLen = numberEnd - decimalStart - 1;
        if (decimalLen > 2) {
            len = decimalStart - numberStart + 3; 
        } else {
            len = numberEnd - numberStart;
        }
    }

    strncpy(output, numberStart, len);
    output[len] = '\0';

    if (hasDecimal) {
        char *decimalPoint = strchr(output, '.');
        int decimalLen = strlen(decimalPoint + 1);
        if (decimalLen < 2) {
            strcat(output, "0");
        }
    } else {
        strcat(output, ".00");
    }
}

int main() {
    char output[50];

    extractNumberWithTwoDecimalPlaces("abcd123.123", output);
    printf("%s\n", output);

	return 0; 
}

