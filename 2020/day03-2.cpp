#include <iostream>
#include <numeric>

int main()
{
  std::string treeLine;

  const int nrSlopes = 5;
  int slopeRight[nrSlopes] = {1, 3, 5, 7, 1};
  int slopeDown[nrSlopes] = {1, 1, 1, 1, 2};
  int posRight[nrSlopes] = {0, 0, 0, 0, 0};
  int posDown[nrSlopes] = {0, 0, 0, 0, 2};
  long treeCnt[nrSlopes] = {0, 0, 0, 0, 0};

  std::getline(std::cin, treeLine);
  int lineNr = 0;

  while (std::getline(std::cin, treeLine))
  {
    lineNr++;
    for (std::size_t i = 0; i < nrSlopes; i++)
    {
      if (slopeDown[i] == 1 || lineNr == posDown[i])
      {
        posRight[i] += slopeRight[i];
        posDown[i] += slopeDown[i];
        if (treeLine.at(posRight[i] % treeLine.size()) == '#')
        {
          treeCnt[i]++;
        }
      }
    }
  }

  long cnt = 1;
  for (auto i : treeCnt)
  {
    cnt *= i;
  }

  std::cout << cnt << std::endl;

  return 0;
}