#include <iostream>
#include <set>

int main()
{
  std::set<int> data;
  int year;

  while (std::cin >> year)
  {
    for (auto i : data)
    {
      for (auto j : data)
      {
        if (i != j && i + j + year == 2020)
        {
          std::cout << i * j * year << std::endl;
          return 0;
        }
      }
    }
    data.insert(year);
  }
  return 0;
}