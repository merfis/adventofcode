#include <iostream>
#include <vector>

int main()
{
  int n;
  char sep;
  std::vector<int> v;

  std::cin >> n;
  v.push_back(n);
  while (std::cin >> sep >> n && sep == ',')
  {
    v.push_back(n);
  }

  bool done = false;

  v[1] = 12;
  v[2] = 2;

  for (std::size_t i = 0, l = v.size(); i < l || !done; i += 4)
  {
    switch (v[i])
    {
    case 99:
      done = true;
      break;
    
    case 1:
      v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
      break;

    case 2:
      v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
      break;
    
    default:
      std::cout << "Something went wrong" << std::endl;
      break;
    }
  }

  std::cout << v[0] << std::endl;

  return 0;
}