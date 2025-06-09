#include <stdio.h> 
#include <stdlib.h> 
#include "mem.h"

void *malloc(size_t size) 
{
	/*
	 * Allocating Memory without traversal
	 */
	void *block;
	header_t *header; 

	/* Moves the heap by the number of size*/
	block = sbrk(size);

	/* On failure, sbrk() returns (void*) -1 */ 
	if (block == (void*) -1) {
		return NULL;
	}
	header->s.size = size;
	header->s.is_free = 0; /* 0 as the memory was used, 1 as free */
}
