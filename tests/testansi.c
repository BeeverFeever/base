#include <stdio.h>
#include "ansi.h"

#define R reset(R_ALL)
#define X(c) puts(colour(c) "test " colour(BG_##c) "test " R bold(c) "test " dim(c) "test "R italic(c) "test "R underline(c) "test "R blink(c) "test "R reverse(c) "test "R hidden(c) "test "R strike(c) "test "R)

int main(void)
{
    X(BLACK);
    X(RED);
    X(GREEN);
    X(YELLOW);
    X(BLUE);
    X(MAGENTA);
    X(CYAN);
    X(WHITE);
    X(DEFAULT);
    return 0;
}
