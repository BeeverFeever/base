#ifndef BMP_H
#define BMP_H

#include <stdio.h>

int static get_file_size(FILE* f)
{
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    rewind(f);
    return size;
}

void bmp(FILE* f) {
    int size = get_file_size(f);
    
}

#endif // BMP_H
