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

test_start("remove_spaces() function");

subtest("Simple spaces inside string",
{
    char *query   = "NOC    > 3";
    char result[] = "NOC    > 3";

    remove_spaces(result, query);

    test_printf("'%s'", result);
    test_assert_str(result, "==", "NOC>3", 6);
});

subtest("Space after the query",
{
    char *query   = "NOC= 42      ";
    char result[] = "NOC= 42      ";

    remove_spaces(result, query);

    test_printf("'%s'", result);
    test_assert_str(result, "==", "NOC=42", 7);
});

subtest("Spaces everywhere",
{
    char *query   = "        N O C   = 1 1 1       ";
    char result[] = "        N O C   = 1 1 1       ";

    remove_spaces(result, query);

    test_printf("'%s'", result);
    test_assert_str(result, "==", "NOC=111", 8);
});

subtest("No spaces == no changes to the string",
{
    char *query   = "BROADBND=1";
    char result[] = "BROADBND=1";

    remove_spaces(result, query);

    test_printf("'%s'", result);
    test_assert_str(result, "==", "BROADBND=1", 11);
});

subtest("Sanity check for NULL arguments",
{
    char *test = "hi";
    remove_spaces(test, NULL);
    remove_spaces(NULL, test);
    remove_spaces(NULL, NULL);
});

test_end
