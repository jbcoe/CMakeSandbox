#include "macros.h"

void a();
void b();
void abc();
void abd();

void abe()
{
  log(__func__, __FILE__, __LINE__);
  a();
  b();
  abc();
  abd();
}
