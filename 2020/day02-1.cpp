#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

int main()
{
  std::string line, word, password;
  int low, high, count, valid = 0;
  std::vector<std::string> words;
  std::size_t dashPos, wordPos = 0;

  while (std::getline(std::cin, line))
  {
    std::istringstream iss(line);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());

    dashPos = words[0].find("-");
    low = std::stoi(words[0].substr(0, dashPos));
    high = std::stoi(words[0].substr(dashPos + 1));

    word = words[1].substr(0, words[1].size() - 1);

    count = 0;
    wordPos = 0;
    while ((wordPos = words[2].find(word, wordPos)) != std::string::npos)
    {
      count++;
      wordPos++;
    }
    if (low <= count && count <= high)
    {
      valid++;
    }

  }
  std::cout << valid << std::endl;
  return 0;
}