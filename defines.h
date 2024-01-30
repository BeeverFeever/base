// Inspiration has been taken from u/skeeto on reddit and github
// https://nullprogram.com/blog/2023/10/08/

#ifndef DEFINES_H
#define DEFINES_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    false = 0,
    true = 1,
} bool;

typedef unsigned int uint;
typedef char         byte;
typedef uint8_t      u8;
typedef uint16_t     u16;
typedef uint32_t     u32;
typedef uint64_t     u64;
typedef int8_t       i8;
typedef int16_t      i16;
typedef int32_t      i32;
typedef int64_t      i64;
typedef float        f32;
typedef double       f64;
typedef ptrdiff_t    size;
typedef size_t       usize;

#define sizeof(x) (size)sizeof(x)
#define alignof(x) (size)_Alignof(x)
#define countof(a) (sizeof(a) / sizeof(*(a)))

#endif // DEFINES_H
