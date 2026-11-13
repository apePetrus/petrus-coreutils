#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s\n", "Too few arguments.");
    return 1;
  }

  bool errors = false;

  for (int i = 1; i < argc; i++) {
    FILE* fp = fopen(argv[i], "r");
    if (fp != 0) {
      char ch;
      while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
      }

      fclose(fp);
    } else {
      fprintf(stderr, "pcat: %s: file or directory does not exists\n", argv[i]);
      errors = true;
    }
  }
  
  if (errors) return 1;

  return 0;
}
