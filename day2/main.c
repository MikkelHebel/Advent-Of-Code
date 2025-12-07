#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long checkDuplicate(char input[]) {
  char chars[64]; strcpy (chars, input);

  char *dash = strchr(chars, '-');
  if (!dash) return 0;
  *dash = '\0';
  unsigned long long startInt = strtoull(chars, NULL, 10);
  unsigned long long endInt = strtoull(dash + 1, NULL, 10);

  unsigned long long sum = 0;

  for (unsigned long long num = startInt; num <= endInt; num++) {
    char str[32];
    sprintf(str, "%llu", num);

    int len = strlen(str);
    if (len % 2 != 0) continue;

    int half = len / 2;
    int is_bad = 1;

    for (int i = 0; i < half; i++) {
      if (str[i] != str[i + half]) {
        is_bad = 0;
        break;
      }
    }

    if (is_bad) {
      sum += num;
    }
  }

  return sum;
}

int main(int argc, char *argv[]) {
  FILE *fptr = fopen("input", "r");
  if (fptr == NULL) {
    perror("Cannot open input");
    return 1;
  }

  unsigned long long invalidIdsTotal = 0;
  char line[1024];

  while(fgets(line, sizeof(line), fptr)) {
    char *token = strtok(line, ",\n");
    while (token != NULL) {
      invalidIdsTotal += checkDuplicate(token);
      token = strtok(NULL, ",\n");
    }
  }

  fclose(fptr);
  printf("Invalid Ids Added up: %llu\n", invalidIdsTotal);
  return 0;
}
