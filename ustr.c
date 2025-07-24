#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ustr.h"
#include "pset1.h"

/*
Initializes a new UStr with contents
*/
UStr new_ustr(char* contents) {
	int32_t bytes = strlen(contents);
	int32_t codepoints = utf8_strlen(contents);
	uint8_t all_ascii = bytes == codepoints;
	char* contents_copy = malloc(bytes + 1);
	strcpy(contents_copy, contents);
	UStr s = {
		codepoints,
		bytes,
		all_ascii,
		contents_copy
	};
	return s;
}

/*
Returns length of string
*/
int32_t len(UStr s) {
	return s.codepoints;
}

/*
Returns a substring of str, starting at index start (inclusive) 
and ending at index end (exclusive).

Returns an empty string on invalid range.
*/
UStr substring(UStr s, int32_t start, int32_t end) {
	// TODO: implement this
	if(start < 0 || end > len(s)-1 || start > len(s)-1)
	{
		char *empty_str = "";
		UStr empty = new_ustr(empty_str);
		return empty;
	}

	int32_t start_byte_index = bi_of_cpi(s.contents, start);
	int32_t end_byte_index = bi_of_cpi(s.contents, end);

	uint8_t size = end_byte_index - start_byte_index + 1;

	char sub_str[size];

	strncpy(sub_str, s.contents + start_byte_index, size - 1);

	sub_str[size - 1] = 0;

	UStr sub = new_ustr(sub_str);

	return sub;
}

/*
Given 2 strings s1 and s2, returns a string that is the result of 
concatenating s1 and s2. 
*/
UStr concat(UStr s1, UStr s2) {
	char* new_contents[s1.bytes+s2.bytes+1];
	strcat(new_contents, s1.contents);
	strcat(new_contents, s2.contents);
	new_contents[s1.bytes +s2.bytes] = '\0'; 
	UStr str = new_ustr(new_contents);
	return str;
}

/*
Given a string s and an index, return a string with the character at index 
removed from the original string. 

Returns the original string if index is out of bounds.
*/
UStr removeAt(UStr s, int32_t index) {
	// implemented 
	UStr update = new_ustr(s.contents);
	int i;
	//find number of bytes to rewrite int eh beginning 
	if(s.is_ascii){ 
		for(i = index; i+1<s.codepoints; i++){
			update.contents[i] = update.contents[i+1];
		}
	} else{
		int8_t noof_bytes = utf8_codepoint_size(update.contents[index]);	
		for(i = index; i<s.bytes; i++){
			update.contents[i] = update.contents[i+noof_bytes];
		}
	}
	update.contents[i]= 0;	
	update.codepoints -= 1; 
	return update;
}

/*
Given a string s, return s reversed. 

Example: reverse("apples🍎 and bananas🍌") = "🍌sananab dna 🍎selppa")
*/
UStr reverse(UStr s) {
	// point to string to be reversed
	char* p = s.contents;
	int len = s.bytes;
	// new string to store reverse
	char outstr[len+1];

	outstr[len] = 0;

	int size = 0;
	for(int i = 0; i < len; i+=size){
		size = utf8_codepoint_size(p[i]);
		memcpy(outstr + (len-i-size), p+i, size);	
		
	}
	UStr str_return = new_ustr(outstr);
	return str_return;
}


void print_ustr(UStr s) {
	printf("%s [codepoints: %d | bytes: %d]", s.contents, s.codepoints, s.bytes);
}

void free_ustr(UStr s) {
	if (s.contents != NULL) {
		free(s.contents);
		s.contents = NULL;
	}
}


