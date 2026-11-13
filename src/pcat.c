#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s\n", "Too few arguments.");
    return 1;
  }

  int error_count = 0;

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
      error_count++;
    }
  }
  
  if (error_count > 0) return 1;

  return 0;
}
