#include <stdio.h>
#include <string.h>

int main() {

  char str[50] = "My name is Anthony";
  char *tmp = "%20";
  char *ptr = NULL;
  char *start = NULL;
  char *end = NULL;
  int count = 0;

  start = &str[0];
  ptr = start;

  while(*ptr != '\0') {
    if(*ptr == ' ') {
      count++;
    }
    ptr++;
  }
  ptr--;
  end = ptr + 2*count;
  *(end +1) = '\0';
  while(ptr >= start) {
    if (*ptr == ' ') {
      end = end - 2;
      strncpy(end, tmp, 3);
      end--;
      ptr--;
      continue;
    }

    *end = *ptr;
    ptr--;
    end--;
  }
  printf("New string:%s\n", str);
  return 0;
}
