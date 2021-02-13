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

test_start("find_col() function");

subtest("Locating a variety of columns",
{
    char *header = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o";
    size_t col_start_char;

    col_start_char = find_col(header, 0);
    test_assert(0 == col_start_char, "Finding column 0");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 3);
    test_assert(6 == col_start_char, "Finding column 3");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 12);
    test_assert(24 == col_start_char, "Finding column 12");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 200);
    test_assert(30 == col_start_char, "Finding column 200");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 999);
    test_assert(30 == col_start_char, "Finding column 999");
    test_printf("%zu", col_start_char);
});

subtest("Locating more columns",
{
    char *header = "124a,fjiowwojweb,c,d,xxe,f,g1111,h,i,j,k,l,m,n,o,hhiiiiiiiiii";
    size_t col_start_char;

    col_start_char = find_col(header, 0);
    test_assert(0 == col_start_char, "Finding column 0");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 3);
    test_assert(19 == col_start_char, "Finding column 3");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 12);
    test_assert(43 == col_start_char, "Finding column 12");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 200);
    test_assert(62 == col_start_char, "Finding column 200");
    test_printf("%zu", col_start_char);

    col_start_char = find_col(header, 999);
    test_assert(62 == col_start_char, "Finding column 999");
    test_printf("%zu", col_start_char);
});

subtest("Sanity check for NULL arguments",
{
    find_col(NULL, 999);
});

test_end
