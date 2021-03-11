#include <stdio.h>
#include <string.h>

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
