#include <iostream>
#include <sstream>
#include <map>

bool isPassportValid(std::map<std::string, std::string>);

int main()
{
  int valid = 0;
  std::size_t sepPos;
  std::string line, kvPair, key, value;
  std::map<std::string, std::string> passportData;

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

      if (isPassportValid(passportData))
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

bool isPassportValid(std::map<std::string, std::string> passportData)
{
  std::map<std::string, std::string>::iterator it;
  it = passportData.find("cid");

  if ((passportData.size() == 8) ||
      (passportData.size() == 7 && it == passportData.end())
  )
  {
    it = passportData.find("byr");
    int byr = std::stoi(it->second);
    if (byr < 1920 || byr > 2002)
    {
      return false;
    }

    it = passportData.find("iyr");
    int iyr = std::stoi(it->second);
    if (iyr < 2010 || iyr > 2020)
    {
      return false;
    }

    it = passportData.find("eyr");
    int eyr = std::stoi(it->second);
    if (eyr < 2020 || eyr > 2030)
    {
      return false;
    }

    it = passportData.find("hgt");
    std::string unit = it->second.substr(it->second.size() - 2, 2);

    if (unit.compare("cm") != 0 && unit.compare("in") != 0)
    {
      return false;
    }
    int hgt = std::stoi(it->second.substr(0, it->second.size() - 2));
    if ((unit == "cm" && (hgt < 150 || hgt > 193)) ||
        (unit == "in" && (hgt < 59 || hgt > 76))
    )
    {
      return false;
    }

    it = passportData.find("hcl");
    if (it->second.substr(0, 1).compare("#") != 0 ||
        it->second.size() != 7 ||
        it->second.substr(1).find_first_not_of("0123456789abcdef") != std::string::npos
    )
    {
      return false;
    }

    it = passportData.find("ecl");
    if (it->second.compare("amb") != 0 && it->second.compare("blu") != 0 && it->second.compare("brn") != 0 &&
        it->second.compare("gry") != 0 && it->second.compare("grn") != 0 && it->second.compare("hzl") != 0 &&
        it->second.compare("oth") != 0
    )
    {
      return false;
    }

    it = passportData.find("pid");
    if (it->second.size() != 9 || it->second.find_first_not_of("0123456789") != std::string::npos)
    {
      return false;
    }

    return true;
  }
  return false;
}