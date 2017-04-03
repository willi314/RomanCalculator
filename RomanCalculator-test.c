/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "RomanCalculator-test.check" instead.
 */

#include <check.h>

#line 1 "RomanCalculator-test.check"
/*
 * RomanCalculator-test.c
 *
 *  Created on: Mar 28, 2017
 *      Author: Alex Williams
 */
 
 #include "RomanConverter.h"
 #include <string.h>
 
START_TEST(romanToIntTest)
{
#line 12
 	fail_unless(romanToInt("i") == 1);
 	fail_unless(romanToInt("I") == 1);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, romanToIntTest);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}