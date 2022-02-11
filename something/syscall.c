#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char * const argv[]) {
  char inputstring[50];
  int opt;
  int key = 0;

  while ((opt = getopt(argc, argv, "s:k:")) != -1) {
    switch (opt) {
    case 'k':
      key = atoi(optarg);
      printf("Key is %d\n", key);
      break;
    case 's':
      strcpy(inputstring, optarg);
      printf("Original is %s\n", inputstring);
      break;
    default:
      break;
    }
  }
  printf("Return : %ld \n", syscall(442, inputstring, key));
  return 0;
}
