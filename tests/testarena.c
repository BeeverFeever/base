#include <stdio.h>
#include "arena.h"

struct foo {
    int i;
    char c;
};

int main(void)
{
    Arena* objs = arena_create(sizeof(struct foo), 3);

    struct foo* f = arena_alloc(objs, 2);
    f->i = 3;
    f->c = 'h';

    struct foo* t = arena_alloc(objs, 1);
    t->i = 6;
    t->c = 'x';

    printf("%i %c\n", f->i, f->c);
    printf("%i %c\n", t->i, t->c);
    debug_arena(objs);
    return 0;
}
