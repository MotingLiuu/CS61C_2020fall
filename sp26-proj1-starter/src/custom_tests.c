#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asserts.h"
// Necessary due to static functions in game.c
#include "game.c"

/* Look at asserts.c for some helpful assert functions */

int greater_than_forty_two(int x) { return x > 42; }

bool is_vowel(char c) {
  char *vowels = "aeiouAEIOU";
  for (int i = 0; i < strlen(vowels); i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

/*
  Example 1: Returns true if all test cases pass. False otherwise.
    The function greater_than_forty_two(int x) will return true if x > 42. False otherwise.
    Note: This test is NOT comprehensive
*/
bool test_greater_than_forty_two() {
  int testcase_1 = 42;
  bool output_1 = greater_than_forty_two(testcase_1);
  if (!assert_false("output_1", output_1)) {
    return false;
  }

  int testcase_2 = -42;
  bool output_2 = greater_than_forty_two(testcase_2);
  if (!assert_false("output_2", output_2)) {
    return false;
  }

  int testcase_3 = 4242;
  bool output_3 = greater_than_forty_two(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  return true;
}

/*
  Example 2: Returns true if all test cases pass. False otherwise.
    The function is_vowel(char c) will return true if c is a vowel (i.e. c is a,e,i,o,u)
    and returns false otherwise
    Note: This test is NOT comprehensive
*/
bool test_is_vowel() {
  char testcase_1 = 'a';
  bool output_1 = is_vowel(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }

  char testcase_2 = 'e';
  bool output_2 = is_vowel(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }

  char testcase_3 = 'i';
  bool output_3 = is_vowel(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char testcase_4 = 'o';
  bool output_4 = is_vowel(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char testcase_5 = 'u';
  bool output_5 = is_vowel(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }

  char testcase_6 = 'k';
  bool output_6 = is_vowel(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }

  return true;
}

/* Task 4.1 */

bool test_is_tail() {
  // TODO: Implement this function.
  if (!assert_equals_bool("w", true, is_tail('w'))) {
    return false;
  }
  if (!assert_equals_bool("a", true, is_tail('a'))) {
    return false;
  }
  if (!assert_equals_bool("s", true, is_tail('s'))) {
    return false;
  }
  if (!assert_equals_bool("d", true, is_tail('d'))) {
    return false;
  }

  if (!assert_equals_bool("W", false, is_tail("W"))) {
    return false;
  }
  if (!assert_equals_bool("A", false, is_tail("A"))) {
    return false;
  }
  if (!assert_equals_bool("S", false, is_tail("S"))) {
    return false;
  }
  if (!assert_equals_bool("D", false, is_tail("D"))) {
    return false;
  }
  
  if (!assert_equals_bool("^", false, is_tail("^"))) {
    return false;
  }
  if (!assert_equals_bool("<", false, is_tail("<"))) {
    return false;
  }
  if (!assert_equals_bool("v", false, is_tail("v"))) {
    return false;
  }
  if (!assert_equals_bool(">", false, is_tail(">"))) {
    return false;
  }

  return true;
}

bool test_is_head() {
  // TODO: Implement this function.
  if (!assert_equals_bool("W", true, is_head('W'))) {
    return false;
  }
  if (!assert_equals_bool("A", true, is_head('A'))) {
    return false;
  }
  if (!assert_equals_bool("S", true, is_head('S'))) {
    return false;
  }
  if (!assert_equals_bool("D", true, is_head('D'))) {
    return false;
  }

  if (!assert_equals_bool("w", false, is_head('w'))) {
    return false;
  }
  if (!assert_equals_bool("a", false, is_head('a'))) {
    return false;
  }
  if (!assert_equals_bool("s", false, is_head('s'))) {
    return false;
  }
  if (!assert_equals_bool("d", false, is_head('d'))) {
    return false;
  }

  if (!assert_equals_bool("^", false, is_head('^'))) {
    return false;
  }
  if (!assert_equals_bool("<", false, is_head('<'))) {
    return false;
  }
  if (!assert_equals_bool("v", false, is_head('v'))) {
    return false;
  }
  if (!assert_equals_bool(">", false, is_head('>'))) {
    return false;
  }

  return true;
}

bool test_is_snake() {
  // TODO: Implement this function.
  if (!assert_equals_bool("W", true, is_snake('W'))) {
    return false;
  }
  if (!assert_equals_bool("A", true, is_snake('A'))) {
    return false;
  }
  if (!assert_equals_bool("S", true, is_snake('S'))) {
    return false;
  }
  if (!assert_equals_bool("D", true, is_snake('D'))) {
    return false;
  }

  if (!assert_equals_bool("w", true, is_snake('w'))) {
    return false;
  }
  if (!assert_equals_bool("a", true, is_snake('a'))) {
    return false;
  }
  if (!assert_equals_bool("s", true, is_snake('s'))) {
    return false;
  }
  if (!assert_equals_bool("d", true, is_snake('d'))) {
    return false;
  }

  if (!assert_equals_bool("^", true, is_snake('^'))) {
    return false;
  }
  if (!assert_equals_bool("<", true, is_snake('<'))) {
    return false;
  }
  if (!assert_equals_bool("v", true, is_snake('v'))) {
    return false;
  }
  if (!assert_equals_bool(">", true, is_snake('>'))) {
    return false;
  }

  if (!assert_equals_bool("x", true, is_snake('x'))) {
    return false;
  }

  return true;
}

bool test_body_to_tail() {
  // TODO: Implement this function.
  if (!assert_equals_char("w", 'w', body_to_tail('^'))) {
    return false;
  }
  if (!assert_equals_char("a", 'a', body_to_tail('<'))) {
    return false;
  }
  if (!assert_equals_char("s", 's', body_to_tail('v'))) {
    return false;
  }
  if (!assert_equals_char("d", 'd', body_to_tail('>'))) {
    return false;
  }

  return true;
}

bool test_head_to_body() {
  // TODO: Implement this function.
  if (!assert_equals_char("W", '^', head_to_body('W'))) {
    return false;
  }
  if (!assert_equals_char("A", '<', head_to_body('A'))) {
    return false;
  }
  if (!assert_equals_char("S", 'v', head_to_body('S'))) {
    return false;
  }
  if (!assert_equals_char("D", '>', head_to_body('D'))) {
    return false;
  }

  return true;
}

bool test_get_next_row() {
  // TODO: Implement this function.
  if (!assert_equals_int("v", 5, get_next_row(4, 'v'))) {
    return false;
  }
  if (!assert_equals_int("s", 5, get_next_row(4, 's'))) {
    return false;
  }
  if (!assert_equals_int("S", 5, get_next_row(4, 'S'))) {
    return false;
  }

  if (!assert_equals_int("^", 5, get_next_row(6, '^'))) {
    return false;
  }
  if (!assert_equals_int("w", 5, get_next_row(6, 'w'))) {
    return false;
  }
  if (!assert_equals_int("W", 5, get_next_row(6, 'W'))) {
    return false;
  }

  if (!assert_equals_int("<", 5, get_next_row(5, '<'))) {
    return false;
  }
  if (!assert_equals_int("a", 5, get_next_row(5, 'a'))) {
    return false;
  }
  if (!assert_equals_int("A", 5, get_next_row(5, 'A'))) {
    return false;
  }

  if (!assert_equals_int(">", 5, get_next_row(5, '>'))) {
    return false;
  }
  if (!assert_equals_int("d", 5, get_next_row(5, 'd'))) {
    return false;
  }
  if (!assert_equals_int("D", 5, get_next_row(5, 'D'))) {
    return false;
  }

  return true;
}

bool test_get_next_col() {
  // TODO: Implement this function.
  if (!assert_equals_int("v", 5, get_next_col(5, 'v'))) {
    return false;
  }
  if (!assert_equals_int("s", 5, get_next_col(5, 's'))) {
    return false;
  }
  if (!assert_equals_int("S", 5, get_next_col(5, 'S'))) {
    return false;
  }

  if (!assert_equals_int("^", 5, get_next_col(5, '^'))) {
    return false;
  }
  if (!assert_equals_int("w", 5, get_next_col(5, 'w'))) {
    return false;
  }
  if (!assert_equals_int("W", 5, get_next_col(5, 'W'))) {
    return false;
  }

  if (!assert_equals_int("<", 4, get_next_col(5, '<'))) {
    return false;
  }
  if (!assert_equals_int("a", 4, get_next_col(5, 'a'))) {
    return false;
  }
  if (!assert_equals_int("A", 4, get_next_col(5, 'A'))) {
    return false;
  }

  if (!assert_equals_int(">", 6, get_next_col(5, '>'))) {
    return false;
  }
  if (!assert_equals_int("d", 6, get_next_col(5, 'd'))) {
    return false;
  }
  if (!assert_equals_int("D", 6, get_next_col(5, 'D'))) {
    return false;
  }
  
  return true;
}

bool test_customs() {
  if (!test_greater_than_forty_two()) {
    printf("%s\n", "test_greater_than_forty_two failed.");
    return false;
  }
  if (!test_is_vowel()) {
    printf("%s\n", "test_is_vowel failed.");
    return false;
  }
  if (!test_is_tail()) {
    printf("%s\n", "test_is_tail failed");
    return false;
  }
  if (!test_is_head()) {
    printf("%s\n", "test_is_head failed");
    return false;
  }
  if (!test_is_snake()) {
    printf("%s\n", "test_is_snake failed");
    return false;
  }
  if (!test_body_to_tail()) {
    printf("%s\n", "test_body_to_tail failed");
    return false;
  }
  if (!test_head_to_body()) {
    printf("%s\n", "test_head_to_body failed");
    return false;
  }
  if (!test_get_next_row()) {
    printf("%s\n", "test_get_next_row failed");
    return false;
  }
  if (!test_get_next_col()) {
    printf("%s\n", "test_get_next_col failed");
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  init_colors();

  if (!test_and_print("custom", test_customs)) {
    return 0;
  }

  return 0;
}
