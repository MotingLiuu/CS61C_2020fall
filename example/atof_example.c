#include <ctype.h>
#include <stdio.h>

int int_power(int base, int exp) {
  int result = 1;
  for (; exp > 0; exp--)
    result *= base;

  return result;
}

double atof(char s[]) {
  double val, power;
  int i, sign;
  double result = 0;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  result = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    if (isdigit(s[i])) {
      result = result * int_power(10, s[i] - '0');
    } else {
      i++;
      for (int j = s[i] - '0'; j > 0; j--) {
        result = result / 10;
      }
    }
  }

  return result;
}

int main() {
  char test_str[] = "  -123.45e-3";
  double result = atof(test_str);
  printf("The string '%s' converts to the double value: %f\n", test_str,
         result);
  return 0;
}
