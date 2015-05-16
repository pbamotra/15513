#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define PRINT_ADDR(p) (printf("Address is %p\n", p))
/* For all these problems, you may not use any 
 * string library functions; you may, however, 
 * define any helper functions that you may need */ 
unsigned int strlen_m(const char* src) {
	int len = 0;
	while(*src++) {
		len++;
	}
	return len;
}
/* Concatenates the src string to the end of the dest
 * string, returns the dest string
 *
 * You can assume that src/dest are '\0' terminated, 
 * that dest hold enough space to store src+dest and 
 * src/dest do not overlap in memory */
char* strcat_m(char* dest, char* src) { 
    const unsigned int dest_len = strlen_m(dest);
    char* save = dest;
    dest = dest + dest_len;
    while(*src) {
    	*dest++ = *src++;
    }
    *dest = '\0';
    dest = save;
    return dest;
}

/* Reverses a string and returns the a new string 
 * containing the reversed string 
 *
 * You can assume that str is '\0' terminated */
char* strrev(char *str) {
	unsigned last_index = strlen_m(str) - 1;
	char* end = str + last_index;

	while(str < end) {
		char rch = *str;
		*str++ = *end;
		*end-- = rch;
	}
    return str;
}

int main()
{
     /*TODO: Implement test cases to check your implemenation
     * You MAY use string library functions to test your code*/
	char* dest = (char*) malloc(42);
	strcpy(dest, "pbamotra");
	char* src  = (char*) malloc(42);
	strcpy(src, "@andrew.cmu.edu");

	PRINT_ADDR(dest);
	char* copy = (strcat_m(dest, src));
	PRINT_ADDR(dest);
	printf("%s\t%s\n", dest, copy);

	char* str = (char*) malloc(42);
	strcpy(str, "pankesh");
	strrev(str);
	printf("%s", str);
	free(dest);
    free(src);
	return 0;
}
