#include <stdio.h>

extern const char* hello_message;
extern const char* goodbye_message;

int main()
{
  printf("%s\n", hello_message);
}
