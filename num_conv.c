#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Case 1:Function to convert Decimal to Binary
void decimalToBinary(double num) {
    int intPart = (int)num;
    double fracPart = num - intPart;
    
    char binaryInt[32] = "";
    int i = 0;
    while (intPart > 0) {
        binaryInt[i++] = (intPart % 2) + '0';
        intPart /= 2;
    }
    binaryInt[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = binaryInt[j];
        binaryInt[j] = binaryInt[i - j - 1];
        binaryInt[i - j - 1] = temp;
    }
    printf("Binary: %s", (i > 0) ? binaryInt : "0");
    if (fracPart > 0) {
        printf(".");
        for (int j = 0; j < 10; j++) {
            fracPart *= 2;
            int fracBit = (int)fracPart;
            printf("%d", fracBit);
            fracPart -= fracBit;
            if (fracPart == 0) break;
        }
    }
    printf("\n");
}

// Case 2:Function to convert Binary to Decimal
double binaryToDecimal(char binary[]) {
    double decimal = 0;
    int i = 0;
    while (binary[i] != '\0' && binary[i] != '.') {
        decimal = decimal * 2 + (binary[i] - '0');
        i++;
    }
    if (binary[i] == '.') {
        double fracPart = 0, power = 0.5;
        i++;
        while (binary[i] != '\0') {
            fracPart += (binary[i] - '0') * power;
            power /= 2;
            i++;
        }
        decimal += fracPart;
    }
    return decimal;
}

// Case 3: Function to convert Decimal to Octal
void decimalToOctal(double num) {
    int intPart = (int)num;
    double fracPart = num - intPart;
    char octalInt[32] = "";
    int i = 0;
    while (intPart > 0) {
        octalInt[i++] = (intPart % 8) + '0';
        intPart /= 8;
    }
    octalInt[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = octalInt[j];
        octalInt[j] = octalInt[i - j - 1];
        octalInt[i - j - 1] = temp;
    }
    printf("Octal: %s", (i > 0) ? octalInt : "0");
    if (fracPart > 0) {
        printf(".");
        for (int j = 0; j < 10; j++) {
            fracPart *= 8;
            int fracDigit = (int)fracPart;
            printf("%d", fracDigit);
            fracPart -= fracDigit;
            if (fracPart == 0) break;
        }
    }
    printf("\n");
}

// Case 4: Function to convert Octal to Decimal
double octalToDecimal(char octal[]) {
    double decimal = 0;
    int i = 0;
    while (octal[i] != '\0' && octal[i] != '.') {
        decimal = decimal * 8 + (octal[i] - '0');
        i++;
    }
    if (octal[i] == '.') {
        double fracPart = 0, power = 1.0 / 8;
        i++;
        while (octal[i] != '\0') {
            fracPart += (octal[i] - '0') * power;
            power /= 8;
            i++;
        }
        decimal += fracPart;
    }
    return decimal;
}
// Case 5: Function to convert Hexadecimal to Binary
void hexToBinary(char hex[]) {
    printf("Binary: ");
    for (int i = 0; hex[i] != '\0'; i++) {
        switch (hex[i]) {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A': case 'a': printf("1010"); break;
            case 'B': case 'b': printf("1011"); break;
            case 'C': case 'c': printf("1100"); break;
            case 'D': case 'd': printf("1101"); break;
            case 'E': case 'e': printf("1110"); break;
            case 'F': case 'f': printf("1111"); break;
            case '.': printf("."); break;
        }
    }
    printf("\n");
}

// Case 6: Function to convert Binary to Hexadecimal
void binaryToHex(char binary[]) {
    double decimal = binaryToDecimal(binary);
    char hex[32] = "";
    int intPart = (int)decimal;
    double fracPart = decimal - intPart;
    int i = 0;
    while (intPart > 0) {
        int remainder = intPart % 16;
        hex[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        intPart /= 16;
    }
    hex[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
    printf("Hexadecimal: %s", (i > 0) ? hex : "0");
    if (fracPart > 0) {
        printf(".");
        for (int j = 0; j < 10; j++) {
            fracPart *= 16;
            int fracDigit = (int)fracPart;
            printf("%X", fracDigit);
            fracPart -= fracDigit;
            if (fracPart == 0) break;
        }
    }
    printf("\n");
}

int main() {
    int choice;
    char binary[32], octal[32],hex[32];
    double decimal;
    
    while (1) {
        printf("\nNumber System Conversion Menu:");
        printf("\n1. Decimal to Binary");
        printf("\n2. Binary to Decimal");
        printf("\n3. Decimal to Octal");
        printf("\n4. Octal to Decimal");
        printf("\n5. Hexadecimal to Binary");
        printf("\n6. Binary to Hexadecimal");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Decimal Number: ");
                scanf("%lf", &decimal);
                decimalToBinary(decimal);
                break;
            case 2:
                printf("Enter Binary Number: ");
                scanf("%s", binary);
                printf("Decimal: %lf\n", binaryToDecimal(binary));
                break;
            case 3:
                printf("Enter Decimal Number: ");
                scanf("%lf", &decimal);
                decimalToOctal(decimal);
                break;
            case 4:
                printf("Enter Octal Number: ");
                scanf("%s", octal);
                printf("Decimal: %lf\n", octalToDecimal(octal));
                break;
            case 5:
                printf("Enter Hexadecimal Number: ");
                scanf("%s", hex);
                hexToBinary(hex);
                break;
            case 6:
                printf("Enter Binary Number: ");
                scanf("%s", binary);
                binaryToHex(binary);
                break;
            case 7:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
