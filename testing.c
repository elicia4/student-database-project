#include <stdio.h>
#include <stdlib.h>

typedef struct test {
  int value;
} test;

int main() {
  test *array[50];
  array[0] = malloc(sizeof(test));
  test *(*p)[] = &array;
  (*p)[0]->value = 5;
  printf("%d", *(*p)[0]);
}