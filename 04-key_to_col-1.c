#if 0
    source "${TEST_DIR}/lib/crunner" -lquery
#endif

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include "query.h"

test_start("key_to_col() function");

subtest("Locating columns based on search key",
{
    char *header = "a,b,cookies,d,e,f,g,hello_world,i,j,k,l,MANGO,n,o";
    int col;

    col = key_to_col(header, "k");
    test_assert(col == 10, "Finding 'k'");
    test_printf("%d", col);

    col = key_to_col(header, "a");
    test_assert(col == 0, "Finding 'a'");
    test_printf("%d", col);

    col = key_to_col(header, "MANGO");
    test_assert(col == 12, "Finding 'MANGO'");
    test_printf("%d", col);

    col = key_to_col(header, "hello_world");
    test_assert(col == 7, "Finding 'MANGO'");
    test_printf("%d", col);

    col = key_to_col(header, "notthere");
    test_assert(col == -1, "Finding 'notthere'");
    test_printf("%d", col);
});

subtest("Sanity check for NULL arguments",
{
    char *header = "hi,there";
    key_to_col(header, NULL);
    key_to_col(NULL, "test");
});

test_end
