#include <stdio.h>
#include "../include/chapter-1.h"

// Question 1: Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additonal data structures?
int isUnique(char* string) {
    for(int i = 0; string[i] != '\0'; ++i) {
        for(int j = i + 1; string[j] != '\0'; ++j) {
            if(string[i] == string[j]) return FALSE;
        }
    }

    return TRUE;
}
