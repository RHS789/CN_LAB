#include <stdio.h>

void generateHammingCode(int data[4], int code[7]) {
    code[2] = data[0];
    code[4] = data[1];
    code[5] = data[2];
    code[6] = data[3];
    code[0] = code[2] ^ code[4] ^ code[6];
    code[1] = code[2] ^ code[5] ^ code[6];
    code[3] = code[4] ^ code[5] ^ code[6];
}

int detectAndCorrect(int code[7]) {
    int p1 = code[0] ^ code[2] ^ code[4] ^ code[6];
    int p2 = code[1] ^ code[2] ^ code[5] ^ code[6];
    int p4 = code[3] ^ code[4] ^ code[5] ^ code[6];
    int errorPos = p4 * 4 + p2 * 2 + p1 * 1;

    if (errorPos != 0) {
        printf("\nError detected at position: %d\n", errorPos);
        code[errorPos - 1] ^= 1;
        printf("Error corrected.\n");
    } else {
        printf("\nNo error detected.\n");
    }
    return errorPos;
}

int main() {
    int data[4];
    int code[7];
    int i;
    printf("Enter 4 data bits (space-separated): ");
    for (i = 0; i < 4; i++) {
        scanf("%d", &data[i]);
    }
    generateHammingCode(data, code);
    printf("Generated Hamming Code (7 bits): ");
    for (i = 0; i < 7; i++) {
        printf("%d", code[i]);
    }
    
    int errorPos;
    printf("\n\nEnter position to simulate error (1 to 7, 0 for no error): ");
    scanf("%d", &errorPos);

    if (errorPos >= 1 && errorPos <= 7) {
        code[errorPos - 1] ^= 1;
        printf("Code with error: ");
        for (i = 0; i < 7; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }

    detectAndCorrect(code);

    printf("Corrected Hamming Code: ");
    for (i = 0; i < 7; i++) {
        printf("%d", code[i]);
    }

    printf("\n");
    return 0;
}