#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include "mem.h"

header_t *head, *tail; 
void *malloc(size_t size) 
{ 
	void *block
	header_t *header; 
	
	/*
	 * Take a chunk of memory to heap with the given size
	 * 
	 * In this intance we allocate a space in heap for
	 * the header along with a usable memory and 
	 * metadata
	 *
	 * sbrk() allocates in the heap
	 */
	size_t header_block_size = sizeof(header_t) + size; 
	block = sbrk(header_block_size);

	/* On failure, sbrk() returns (void*) -1 */ 
	if (block == (void*) -1) {
		return NULL;
	}
	header->s.size = size;
	header->s.is_free = 0; /* Mark it as used using 0 1 */	
	header->s.next = NULL;

	/* If there's no head in linked list then point it to the current header*/
	if (!head) {
		head = header; 
	}

	/* If there is an existing tail then point tail to the next header */
	if (tail) {
		tail->s.next = header; 
	} else {
		return NULL; 
	}

	/* Point tail to the current header */
	tail = header; 
	
	/* Return a pointer to header and append by 1 to return usable memory*/ 
	return (void*)(header + 1);
}

header_t *get_block(size_t size)
{
	header_t *curr_block = head;
	
	/*
	 * If header is free and has the sufficient size to be 
	 * allocated then return the block address.
	 */
	while (curr_block)
	{
		if (curr_block->s.is_free && curr_block->s.next > size) {
			return curr_block; 
		}
		
		/* If none were found traverse through list */
		curr_block->next;
	}
}
