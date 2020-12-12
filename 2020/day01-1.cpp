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
      if (i + year == 2020)
      {
        std::cout << i * year << std::endl;
        return 0;
      }
    }
    data.insert(year);
  }
  return 0;
}