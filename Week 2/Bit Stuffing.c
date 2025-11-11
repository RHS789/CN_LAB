#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void main() {
    char in[MAXSIZE];
    char stuff[MAXSIZE];
    char unstuff[MAXSIZE];
    int count = 0, j = 0, i = 0;
    printf("Enter the input character string (0's & 1's only):\n");
    scanf("%s", in);

    while (in[i] != '\0') {
        if (in[i] == '0') {
            stuff[j] = in[i];
            i++;
            j++;
        } else {
            while (in[i] == '1' && count != 5) {
                count++;
                stuff[j] = in[i];
                i++;
                j++;
            }
            if (count == 5) {
                stuff[j] = '0';
                j++;
            }
            count = 0;
        }
    }

    stuff[j] = '\0';
    printf("\nThe stuffed character string is:\n");
    printf("%s", stuff);
    i = 0;
    j = 0;

    while (stuff[i] != '\0') {
        if (stuff[i] == '0') {
            unstuff[j] = stuff[i];
            i++;
            j++;
        } else {
            while (stuff[i] == '1' && count != 5) {
                count++;
                unstuff[j] = stuff[i];
                i++;
                j++;
            }
            if (count == 5) {
                i++;
            }
            count = 0;
        }
    }

    unstuff[j] = '\0';
    printf("\nThe unstuffed character string is:\n");
    printf("%s\n", unstuff);
}