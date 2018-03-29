/**
 * @author Marce Coll <marce@dziban.net>
 * @file
 */

#ifndef _DECK_MEMORY_H_
#define _DECK_MEMORY_H_

#include <inttypes.h>

uint8_t *mem_area;

// Initialize a memory arena with an initial allocation of `initial_alloc` and
// that will increment by `increment` everytime it is needed.
void deck_memory_init(size_t initial_alloc, size_t increment);

// General purpose malloc for the memory arena.
void* deck_malloc(size_t size);

// Specific string allocation for the memory arena.
char* deck_string_alloc(size_t length);

#endif
