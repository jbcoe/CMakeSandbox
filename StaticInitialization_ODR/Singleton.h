#include <array>
#include <vector>

std::array<int,6> g_magic_numbers = {4,7,22,1,7,11};
//std::vector<int> g_magic_numbers = {4,7,22,1,7,11};

size_t g_i = 0;

int magic_number()
{
  return g_magic_numbers[(g_i++)%g_magic_numbers.size()];
}
