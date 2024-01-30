#ifndef IDKFN_H
#define IDKFN_H

#include <stdio.h>
#include <stdlib.h>

#define FLAG_ON(f,i) ((f)|(u))
#define FLAG_OFF(f,i) ((f)^((f)&(i)))
#define IS_FLAG_ON(f,i) ((f)&(i)?1:0)

int inline get_file_size(FILE* f)
{
    fseek(f, 0, SEEK_END);
    int l = ftell(f);
    rewind(f);
    return l;
}

int read_file(char** buffer, const char* path, char* mode)
{
    FILE* f = fopen(path, mode);
    if (f == NULL) return -1;

    int l = get_file_size(f);

    int n = fread(*buffer, sizeof(char), l, f);
    if (n != l) return -1;
    return n;
}

// GENERIC LIST

typedef struct {
    int length;
    int capacity;
    void* data;
} list;

list* list_create(int length, void* data)
{
    list* l = (list*)malloc(sizeof(list));
    l->length = length;
    l->capacity = length;
    l->data = data;
    return l;
}

void list_free(list* l)
{
    free(l->data);
    free(l);
    l = NULL;
}

void list_insert(list* l, int idx, void* data)
{
    if (l->length + 1 > capacity) {
        list_resize(l);
    }


}

#endif // IDKFN_H
