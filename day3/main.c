#include <stdio.h>
#include <string.h>

int findJoltage(char line[]);

int main(int argc, char argv[]) {
  FILE *fptr;
  fptr = fopen("input", "r");

  if (fptr == NULL) {
    perror("Cannot open input");
  }

  char line[1024];
  int totalJoltage = 0;
  while(fgets(line, sizeof(line), fptr)) {
    totalJoltage += findJoltage(line);
  }
  printf("Total Joltage: %d\n", totalJoltage);
}

int findJoltage(char line[]) {
  int max_joltage = 0;
  for (int i = 0; i < strlen(line); i++) {
    int x = line[i] - '0';
    for (int j = i + 1; j < strlen(line); j++) {
      int y = line[j] - '0';
      int temp = (10 * x) + y;
      if (temp == 99) {
        return 99;
      }
      if (temp > max_joltage) {
        max_joltage = temp;
      }
    }
  }
  return max_joltage;
}
