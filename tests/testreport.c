#define REPORT_IMPLEMENTATION
#include "report.h"

int main(void)
{
    report(stderr, INFO, "test report %s", "with all the features");
    report(stderr, INFO, "This is a test report");
    /* report_and_exit(stderr, 0, DEBUG, "this should exit the program"); */
    puts("This shouldn't be printed");
    return 0;
}
