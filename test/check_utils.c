#include <check.h>

#include <utils.h>

START_TEST(path_join_simple)
{
        char *a = "/home/mcoll/proj/";
        char *b = "deck/main.c";
        char *expected = "/home/mcoll/proj/deck/main.c";
        char *path = path_join(a, b);

        ck_assert_str_eq(path, expected);
}
END_TEST

Suite* paths_suite() {
        Suite *s;
        TCase *tc_core;

        s = suite_create("Path");

        tc_core = tcase_create("Core");

        tcase_add_test(tc_core, path_join_simple);
        suite_add_tcase(s, tc_core);

        return s;
}

int main(void) {
        int number_failed;
        Suite *s;
        SRunner *sr;

        s = money_suite();
        sr = srunner_create(s);

        srunner_run_all(sr, CK_NORMAL);
        number_failed = srunner_ntests_failed(sr);

        srunner_free(sr);
        return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
