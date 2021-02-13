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

test_start("copy_token() function");

subtest("Tokenize on spaces",
{
    char *src = "this is a test";
    char result[] = "XXXXXXXXXX";

    copy_token(result, src, " ");

    test_printf("'%s'", result);
    test_assert_str(result, "==", "this", 5);
});

subtest("Tokenize on the letter i",
{
    char *src = "this is a test";
    char result[] = "XXXXXXXXXX";

    copy_token(result, src, "1234i");

    test_printf("'%s'", result);
    test_assert_str(result, "==", "th", 3);
});

subtest("Empty token",
{
    char *src = "this is a test";
    char result[] = "XXXXXXXXXX";

    copy_token(result, src, "tx2$");

    test_printf("'%s'", result);
    test_assert_str(result, "==", "", 1);
});

subtest("Delim not in string",
{
    char *src =     "this is a test";
    char result[] = "XXXXXXXXXX----";

    copy_token(result, src, "$");

    test_printf("'%s'", result);
    test_assert_str(result, "==", "this is a test", 15);
});

subtest("Sanity check for NULL arguments",
{
    size_t sz = 0;
    char test[] = "hi";
    sz = copy_token(test, NULL, "i");
    test_assert(sz == 0);

    sz = copy_token(NULL, test, "i");
    test_assert(sz == 0);

    sz = copy_token(NULL, NULL, NULL);
    test_assert(sz == 0);
});

test_end
