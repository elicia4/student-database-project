#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test {
  int value;
} test;

int main() {
  char *a = "aboba";
  char *b = "aboba";
  printf("%d", strcmp(a, b));
}