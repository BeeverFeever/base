#include <stdio.h>
#include "../array.h"

typedef char* String;
typedef void* Array;

void array_debug_int(arrayT(int) a)
{
    ArrayHeader* h = array_header(a);
    puts("ARRAY DEBUG");
    printf("\tCapacity: %li\n", h->capacity);
    printf("\tLength: %li\n", h->capacity);
    printf("\tData: { ");

    for (int i = 0; i < array_length(a); i++) {
        printf("%i, ", a[i]);
    }

    puts("}\n");
}

void array_debug_string(arrayT(String) a)
{
    ArrayHeader* h = array_header(a);
    puts("ARRAY DEBUG");
    printf("\tCapacity: %li\n", h->capacity);
    printf("\tLength: %li\n", h->capacity);
    printf("\tData: { ");

    for (int i = 0; i < array_length(a); i++) {
        printf("\"%s\", ", a[i]);
    }

    puts("}\n");
}

int main(void)
{
    arrayT(int) test_int = array(int, NULL);
    arrayT(String) test_string = array(String, NULL);

    for (int t = 0; t < 30; t++) {
        array_append(test_int, t);
    }

    array_append(test_string, "Hi there how are you ");
    array_append(test_string, "this is a message");
    array_append(test_string, "nope");
    array_append(test_string, "agagin");

    array_debug_int(test_int);
    array_debug_string(test_string);

    return 0;
}
