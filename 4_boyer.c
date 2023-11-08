#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

// Function to build the bad character heuristic table
void badCharHeuristic(char *pattern, int patternLength, int badCharTable[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badCharTable[i] = -1;
    }

    for (int i = 0; i < patternLength; i++) {
        badCharTable[(int)pattern[i]] = i;
    }
}

// Function to perform the Boyer-Moore search algorithm
void boyerMooreSearch(char *text, char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int badCharTable[NO_OF_CHARS];
    badCharHeuristic(pattern, patternLength, badCharTable);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            shift += (shift + patternLength < textLength) ? patternLength - badCharTable[text[shift + patternLength]] : 1;
        } else {
            shift += (badCharTable[text[shift + j]] > j) ? badCharTable[text[shift + j]] : j + 1;
        }
    }
}

int main() {
    char text[] = "This is an example text for string matching algorithm.";
    char pattern[] = "algorithm";

    boyerMooreSearch(text, pattern);

    return 0;
}

