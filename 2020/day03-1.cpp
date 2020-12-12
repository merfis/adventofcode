#include <iostream>

int main()
{
  std::string treeLine;
  int slopeRight = 3, slopeDown = 1, treeCnt = 0, pos = 0;
  std::getline(std::cin, treeLine);

  while (std::getline(std::cin, treeLine))
  {
    pos += slopeRight;
    // std::cout << treeLine << std::endl;
    // std::cout << "pos:" << pos << " " << pos % treeLine.size() << " " << treeLine.at(pos % treeLine.size()) << std::endl;
    if (treeLine.at(pos % treeLine.size()) == '#')
    {
      treeCnt++;
    }
  }
  std::cout << treeCnt << std::endl;
  return 0;
}