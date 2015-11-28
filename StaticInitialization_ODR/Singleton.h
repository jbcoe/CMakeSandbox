#include <vector>
#include <random>

std::vector<int> g_magic_numbers = {4,7,22,1,7,11};

size_t g_i = 0;

int magic_number()
{
  std::uniform_int_distribution<int> d(0,g_magic_numbers.size()-1);
  return g_magic_numbers[(g_i++)%g_magic_numbers.size()];
}
