#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  const char *pa = (const char *)a;
  const char *pb = (const char *)b;
  return strcmp(pa, pb);
}

int main() {

  char str[30] = "Hellosirhowareyou?";
  char buf[30];
  char tmp[5];
  char *ptr = &str[0];
  int len = 0;
  int count = 0;
  char *prev = NULL;

  while(*ptr != '\0') {
    len++;
    ptr++;
  }
  ptr = &str[0];
  qsort(ptr, len, sizeof(char), comp);

  prev = ptr;
  ptr++;
  while(*ptr != '\0') {
    if (*ptr == ' ') {
      ptr++;
      continue;
    }
    if (*ptr == *prev) {
        count++;
    } else {
      sprintf(tmp, "%c%d", *prev, (count+1));
      strcat(buf, tmp);
      prev = ptr;
      count = 0;
    }
    ptr++;
  }
  printf("Shorthand string: %s\n",buf);
  return 0;
}
