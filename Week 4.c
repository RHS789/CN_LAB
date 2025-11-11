#include <stdio.h>
#include <string.h>

void xor(char *temp, char *divisor, int len) {
    int i;
    for (i = 0; i < len; i++) {
        temp[i] = (temp[i] == divisor[i]) ? '0' : '1';
    }
}

void crc(char *input, char *divisor, char *remainder) {
    int inputLen = strlen(input);
    int divisorLen = strlen(divisor);
    char temp[120];
    int i, j;

    strncpy(temp, input, divisorLen);
    temp[divisorLen] = '\0';

    for (i = divisorLen; i <= inputLen; i++) {
        if (temp[0] == '1') {
            xor(temp, divisor, divisorLen);
        }
        for (j = 0; j < divisorLen - 1; j++) {
            temp[j] = temp[j + 1];
        }
        temp[divisorLen - 1] = input[i];
    }

    temp[divisorLen - 1] = '\0';
    strcpy(remainder, temp);
}

int main() {
    char data[100], divisor[20], crcBits[20], codeword[120], received[120];
    int i, error = 0;
    printf("Sender Side:\n");
    printf("Enter the data bits: ");
    scanf("%s", data);
    printf("Enter the divisor (generator polynomial): ");
    scanf("%s", divisor);

    char dividend[120];
    strcpy(dividend, data);
    int len = strlen(divisor);

    for (i = 0; i < len - 1; i++)
        dividend[strlen(data) + i] = '0';

    dividend[strlen(data) + len - 1] = '\0';

    crc(dividend, divisor, crcBits);
    printf("Generated CRC bits: %s\n", crcBits);
    strcpy(codeword, data);
    strcat(codeword, crcBits);
    printf("Codeword to be transmitted: %s\n", codeword);
    printf("\nReceiver Side:\n");
    printf("Enter the received message: ");
    scanf("%s", received);

    char remainder[20];
    crc(received, divisor, remainder);

    error = 0;
    for (i = 0; i < strlen(remainder); i++) {
        if (remainder[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error)
        printf("Error detected in the received data.\n");
    else
        printf("No error detected. Data received correctly.\n");
    return 0;
}