#include "macros.h"

void a();
void b();

void abd()
{
  log(__func__, __FILE__, __LINE__);
  a();
  b();
}
