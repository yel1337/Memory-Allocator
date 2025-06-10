#include <stdio.h> 
#include <stdlib.h> 
#include "mem.h"

header_t *head, *tail; 
void *malloc(size_t size) 
{ 
	void *block
	header_t *header; 
	
	/*
	 * Take a chunk of memory to heap with the given size
	 * 
	 * sbrk() allocates in the heap
	 */
	block = sbrk(size);

	/* On failure, sbrk() returns (void*) -1 */ 
	if (block == (void*) -1) {
		return NULL;
	}
	header->s.size = size;
	header->s.is_free = 0; /* 0 as the memory is now in use, 1 as free */	
	header->s.next = NULL;

	/* If there's no head in linked list then point it to the current header*/
	if (!head) {
		head = header; 
	}

	/* If there is an existing tail then point tail to the next header */
	if (tail) {
		tail->s.next = header; 
	}

	/* Point tail to the current header */
	tail = header; 
	
	/* Return a pointer to header and append by 1 to return usable memory*/ 
	return (void*)(header + 1);
}
