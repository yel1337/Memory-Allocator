#include <stdio.h> 
#include <stdlib.h> 

void *malloc(size_t size) 
{
	void *block;

	/* Moves the heap by the number of size*/
	block = sbrk(size);

	/* On failure, sbrk() returns (void*) -1 */ 
	if (block == (void*) -1)
		return NULL; 
	return block;
}
