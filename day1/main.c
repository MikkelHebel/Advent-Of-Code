#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int shift(char chars[]);

int main(int argc, char *argv[]){
  int dial = 50;
  int pwd = 0;

  FILE *fptr;
  fptr = fopen("input", "r");

  char charsFromFile[10];

  if (fptr != NULL) {
    while(fgets(charsFromFile, 10, fptr)) {
      dial += shift(charsFromFile);
      if (dial % 100 == 0) {
        pwd++;
      }
    }
  }
  printf("Done: %d\n", pwd);
  return 0;
}

int shift(char chars[]) {
  char ss[10];
  int result = 0;
  strncpy(ss, chars + 1, strlen(chars) - 2);
  result = atoi(ss);
  if (chars[0] == 'L') {
    result *= (-1);
  }
  return result;
}
