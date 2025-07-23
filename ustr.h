#ifndef USTR_H
#define USTR_H

#include <stdint.h>

typedef struct UStr {
        int codepoints;         // Number of code points in string
        int bytes;              // Lengths don't count null terminator
        uint8_t is_ascii;       // 1 if all code points are ASCII, 0 otherwise
        char* contents;
} UStr;

UStr new_ustr(char* contents);
void print_ustr(UStr s);
void free_ustr(UStr s);

// All indices should be codepoint indices, not byte indices
int32_t len(UStr s);

// To implement
UStr substring(UStr s, int32_t start, int32_t end);
UStr concat(UStr s1, UStr s2);
UStr removeAt(UStr s, int32_t index);
UStr reverse(UStr s);

#endif
