#ifndef STRING_H
#define STRING_H

#include <stddef.h>

typedef char* String;
typedef ptrdiff_t size;

typedef struct {
    size length;
} StringHeader;

String string(String s);

#endif // STRING_H
