#ifndef PSET1_H
#define PSET1_H

#include <stdint.h>

int32_t utf8_strlen(char str[]);
uint8_t is_ascii(char str[]);
uint8_t is_continuation_byte(unsigned char byte);
int8_t utf8_codepoint_size(char c);
int32_t cpi_of_bi(char str[], int32_t byte_index);
int32_t bi_of_cpi(char str[], int32_t codepoint_index);


#endif
