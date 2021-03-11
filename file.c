#include <stdio.h>
#include <string.h>

// make file
int main(void)
{
  char name[100];
  char number[44];
  FILE *file = fopen("phonebook.csv", "a");
  // r : read, w : write, a : append

  printf("Name: ");
  scanf("%s", name);
  printf("Number: ");
  scanf("%s", number);

  fprintf(file, "%s, %s\n", name, number);
}

// read file
int main(int argc, char *argv[])
{
  // Ensure user ran program with two words at prompt
  if (argc != 2)
  {
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    return 1;
  }

  // Read 3 bytes from file
  // unsigned : 0-255 범위 값
  unsigned char bytes[3];
  fread(bytes, 3, 1, file);

  // Check if bytes are 0xff 0xd8 0xff
  // -> JPEG starts with those chars
  if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
  {
    printf("Maybe\n");
  }
  else
  {
    printf("No\n");
  }
}
