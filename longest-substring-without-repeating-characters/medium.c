#include <string.h>

#define MAX_CHARS 256

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;

    // Array to store the last index of every character
    int lastIndex[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        lastIndex[i] = -1;  // Initialize all as -1 (not visited)
    }

    int start = 0; // Start of the current window

    for (int end = 0; end < n; end++) {
        // If the character is repeated, move the start
        if (lastIndex[(int)s[end]] >= start) {
            start = lastIndex[(int)s[end]] + 1;
        }

        // Update the last index of the current character
        lastIndex[(int)s[end]] = end;

        // Update the maximum length of substring found
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}
