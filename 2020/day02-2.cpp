#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

int main()
{
  std::string line, password;
  char word;
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

    word = words[1].at(0);
    if ((words[2].at(low - 1) == word && words[2].at(high - 1) != word) ||
        (words[2].at(low - 1) != word && words[2].at(high - 1) == word)
    )
    {
      valid++;
    }
  }
  std::cout << valid << std::endl;
  return 0;
}