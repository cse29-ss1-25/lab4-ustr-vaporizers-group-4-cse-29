#include <stdio.h>
#include "ustr.h"
#include <string.h>

int main(){
	char input[256];
    	while(fgets(input, sizeof(input), stdin)) {
        	// Remove newline character if present
       		size_t l = strlen(input);
        	if (l > 0 && input[l - 1] == '\n') {
            		input[l - 1] = '\0';
        	}
        	UStr s = new_ustr(input);
		UStr up = reverse(s);
        	print_ustr(up);
        	free_ustr(s);
		free_ustr(up);
    	}
}
