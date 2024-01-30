#ifndef BASE_ARENA
#define BASE_ARENA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "defines.h"

// Change these at your own risk, you are probably smarter than me so you won't
// have a problem but like just be careful.
#ifndef ARENA_MIN_ALLOC
#define ARENA_MIN_ALLOC 512
#endif

#ifndef ARENA_MAX_SIZE
#define ARENA_MAX_SIZE (8*1024)
#endif

#ifndef ARENA_ASSERT
#include <assert.h>
#define arena_assert assert
#endif

// this is so horrendously ugly that i don't want to ever look at it again
#define debug_arena(a) \
    printf("--- ARENA DEBUG (%s) ---\n", #a); \
    printf("    length:\t%i\n", a->length); \
    printf("    capacity:\t%i\n", a->capacity); \
    printf("    elem size:\t%i\n", a->element_size); \
    printf("-------------------------\n"); \


typedef struct {
    int capacity;       // total amount allocated
    int length;         // total amount being used
    int element_size;
    void* elements;
} Arena;

static int align_arena_length(int old_length)
{
    int new_length = old_length;

    if (old_length < ARENA_MIN_ALLOC)
        new_length = ARENA_MIN_ALLOC;
    else if (old_length > ARENA_MAX_SIZE)
        new_length = ARENA_MAX_SIZE;
    else
        new_length += old_length % ARENA_MIN_ALLOC;

    return new_length;
}

Arena* arena_create(int element_length, int count)
{
    int capacity = align_arena_length(count);

    Arena* a = (Arena*)calloc(1, sizeof(Arena));
    arena_assert(a);

    a->capacity = capacity;
    a->length = count;
    a->element_size = element_length;
    a->elements = calloc(capacity, element_length);
    arena_assert(a->elements);

    return a;
}

void arena_delete(Arena* a)
{
    free(a->elements);
    a->elements = NULL;

    // I think im just tired but I don't think this is necessary or does
    // anything
    free(a);
    a = NULL;
}

void arena_reset(Arena* a)
{
    a->length = 0;
    memset(a->elements, 0, a->capacity);
}

void* arena_alloc(Arena* a, uint numelems)
{
    arena_assert(numelems);
    if (a->length + numelems > a->capacity) {
        int new_length = align_arena_length(numelems);
        a->elements = realloc(a->elements, a->length + (numelems * a->element_size));
        a->capacity = new_length;
    }
    void* elem =  &a->elements + a->length;
    a->length += numelems;
    return elem;
}

#endif // BASE_ARENA
