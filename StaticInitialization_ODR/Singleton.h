#include <vector>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

std::vector<int> g_magic_numbers = {0,1,2,3,4,5,6,7,8,9,10,11,15,6,19,21};

int magic_number()
{
  std::uniform_int_distribution<int> d(0,g_magic_numbers.size()-1);
  return g_magic_numbers[d(gen)];
}
