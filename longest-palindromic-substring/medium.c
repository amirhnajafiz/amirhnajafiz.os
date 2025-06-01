#include <string.h>
#include <stdlib.h>

char* expandAroundCenter(char* s, int left, int right) {
    int size = strlen(s);

    // Expand around the center while the characters match
    while (left >= 0 && right < size && s[left] == s[right]) {
        left--;
        right++;
    }

    // Allocate memory for the palindrome substring
    int palindromeLength = right - left - 1;
    char* palindrome = (char*) malloc((palindromeLength + 1) * sizeof(char));
    strncpy(palindrome, s + left + 1, palindromeLength);
    palindrome[palindromeLength] = '\0'; // Null-terminate the palindrome

    return palindrome;
}

char* longestPalindrome(char* s) {
    int size = strlen(s);
    if (size == 0) return "";

    char* longest = (char*) malloc(1);
    longest[0] = '\0';

    for (int i = 0; i < size; i++) {
        // Odd length palindrome (centered at one character)
        char* oddPalindrome = expandAroundCenter(s, i, i);
        if (strlen(oddPalindrome) > strlen(longest)) {
            free(longest);
            longest = oddPalindrome;
        } else {
            free(oddPalindrome);
        }

        // Even length palindrome (centered between two characters)
        char* evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (strlen(evenPalindrome) > strlen(longest)) {
            free(longest);
            longest = evenPalindrome;
        } else {
            free(evenPalindrome);
        }
    }

    return longest;
}
