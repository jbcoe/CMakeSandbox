#include <cstdio>

void a();
void b();
void abc();
void abd();

void abe()
{
  printf("abe called\n");
  a();
  b();
  abc();
  abd();
}
