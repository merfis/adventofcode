#include <iostream>
#include <math.h>

int main()
{
  int mass, s = 0;
  while (std::cin >> mass)
  {
    // part 1 is just s += mass without calculating
    // fuel for fuel
    while (mass > 0)
    {
      mass = std::floor(mass / 3) - 2;
      if (mass > 0)
      {
        s += mass;
      }
    }
  }
  std::cout << "sum: " << s << std::endl;
  return 0;
}