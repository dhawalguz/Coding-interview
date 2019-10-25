#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  const char *pa = (const char *)a;
  const char *pb = (const char *)b;
  return strcmp(pa, pb);
}

int main() {

  char str1[30] = "Hello";
  char str2[30] = "elloH";
  char *ptr1 = &str1[0];
  char *ptr2 = &str2[0];
  int len1, len2, i = 0;

  len1 = strlen(str1);
  len2 = strlen(str2);

  while(i<len1) {
    if(isupper(str1[i])) {
      str1[i] = tolower(str1[i]);
    }
    i++;
  }
  i = 0;
  while(i<len2) {
    if(isupper(str2[i])) {
      str2[i] = tolower(str2[i]);
    }
    i++;
  }
  qsort(ptr1, len1, sizeof(char), comp);
  qsort(ptr2, len2, sizeof(char), comp);

  while((*ptr1 != '\0') && (*ptr2 != '\0')) {
    if (*ptr1 != *ptr2) {
      printf("The strings are not premutations\n");
      return 1;
    }
    ptr1++;
    ptr2++;
  }
  printf("String permute\n");
  return 0;
}
