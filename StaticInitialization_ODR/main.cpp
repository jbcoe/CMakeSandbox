#include <iostream>

int favourite_number();
int least_favourite_number();

int main()
{
  std::cout << "My favourite number is " << favourite_number() << '\n';
  std::cout << "My least favourite number is " << least_favourite_number() << '\n';
}
