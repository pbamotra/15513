/* TODO: Implement these macros as specified.  In all cases, you may NOT 
 * assume anything about the ptr type passed to the macro (it may be a char*, an int*, 
 * a void**, etc) */
#include <stdio.h>
#include <math.h>
#include <malloc.h>
// given an address, get the value stored at that byte 
#define GET_BYTE(p) (*(char*)(p))

// given an address, get the value stored at word (4 bytes)
#define GET_WORD(p) (*(int*)(p))

// given an address and a value, write a 1-byte value at that address
#define PUT_BYTE(p, v) (*(char*)(p) = v)

// given an address and a value, write a 4-byte value at that address
#define PUT_WORD(p, v) (*(int*)(p) = v)

// given an address, get the address of the next byte
#define GET_NEXT_BYTE_ADDR(p) ((char*)(p) + 1)

// given an address, get the value stored in the next byte
#define GET_NEXT_BYTE_VAL(p) (*GET_NEXT_BYTE_ADDR(p))

// given an address, write a value to the next byte
#define PUT_NEXT_BYTE_VAL(p, v) (PUT_BYTE(GET_NEXT_BYTE_ADDR(p),v))

int main() {
    /* TODO: write test cases to ensure that your implementation works correctly
     * A good test may simply create an array of bytes, assign the elements some 
     * values and access the elemnets using the macros you've defined */

	char* pch = (char*) malloc(sizeof(char) * 2);
	PUT_BYTE(pch, 'P');

	char gch = GET_BYTE(pch);
	printf("Retrieved byte using Pointers: %c at %p\n", *pch, pch);
	printf("Retrieved byte using GET_BYTE: %c\n", gch);

	/*TODO:  Realloc will it allocate next byte immediately at pch + 1 //?
	 *Let char* pch = (char*) malloc(sizeof(char));

	 * pch = (char*) realloc(pch, sizeof(char) * 2);
	 * printf("Retrieved using Pointers: %c at %p\n", *pch, pch);
	 * printf("Retrieved using GET_BYTE: %c\n", gch);
	 */

	PUT_NEXT_BYTE_VAL(pch, 'B');
	char gchn = GET_NEXT_BYTE_VAL(pch);
	printf("Retrieved next byte using Pointers: %c at %p\n", gchn, GET_NEXT_BYTE_ADDR(pch));
	printf("Retrieved next byte using GET_NEXT_BYTE: %c\n", gchn);

	int* pword = (int*) malloc(sizeof(int));
	printf("pword is %#0x bytes away from pch\n", ((void*)pword) - ((void*)pch));
	PUT_WORD(pword, 42);

	int gword = GET_WORD(pword);
	printf("Retrieved word using Pointers: %d at %p\n", *pword, pword);
	printf("Retrieved word using GET_BYTE: %d\n", gword);


	free(pch);
	free(pword);
	return 0;
}
