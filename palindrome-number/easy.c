#include <stdlib.h>
#include <string.h>

char* get_digits(int number) {
    // Handle negative numbers
    int is_negative = number < 0;
    if (is_negative) {
        number = -number;
    }

    // Calculate the length of the number
    int len = snprintf(NULL, 0, "%d", number) + is_negative;
    
    // Allocate memory for the string (including null terminator)
    char* result = (char*)malloc((len + 1) * sizeof(char));

    if (is_negative) {
        result[0] = '-';
    }
    
    // Convert number to string
    snprintf(result + is_negative, len + 1 - is_negative, "%d", number);

    return result;
}

char* reverse_string(const char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc((len + 1) * sizeof(char)); // Allocate memory for the reversed string

    // Reverse the string
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0'; // Null-terminate the reversed string

    return reversed;
}

bool isPalindrome(int x) {
    // Negative numbers are not palindorme
    if (x < 0) {
        return false;
    }

    // Get digits inside an array of chars
    char* digits = get_digits(x);

    // Reverse this chart
    char* reverse = reverse_string(digits);

    // Check bit by bit
    for (int i = 0; i < strlen(digits); i++) {
        if (digits[i] != reverse[i])
            return false;
    }

    return true;
}
