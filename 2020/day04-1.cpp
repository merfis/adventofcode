#include <iostream>
#include <sstream>
#include <map>

int main()
{
  int valid = 0;
  std::size_t sepPos;
  std::string line, kvPair, key, value;
  std::map<std::string, std::string> passportData;
  std::map<std::string, std::string>::iterator it;

  while (std::getline(std::cin, line))
  {
    if (line.length() != 0 || std::cin.eof())
    {
      std::istringstream iss(line);
      while (iss >> kvPair)
      {
        sepPos = kvPair.find(":");
        key = kvPair.substr(0, sepPos);
        value = kvPair.substr(sepPos + 1);
        passportData[key] = value;
      }
    }

    if (line.length() == 0 || std::cin.eof())
    {
      it = passportData.find("cid");
      if ((passportData.size() == 8) ||
          (passportData.size() == 7 && it == passportData.end())
      )
      {
        valid++;
      }
      passportData.erase(passportData.begin(), passportData.end());
      continue;
    }
  }
  std::cout << valid << std::endl;
  return 0;
}