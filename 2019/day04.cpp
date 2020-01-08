#include <iostream>
#include <math.h>

bool isValid1(int n)
{
  int lastDigit, prevDigit;
  bool hasDoubles = false;
  while (n > 0)
  {
    lastDigit = n % 10;
    n /= 10;
    if (lastDigit < n % 10)
    {
      return false;
    }
    if (!hasDoubles && lastDigit == n % 10)
    {
      hasDoubles = true;
    }
  }
  return hasDoubles;
}

bool isValid2(int n)
{
  int lastDigit, prevDigit, adj = 1;
  bool hasDoubles = false;
  
  while (n > 0)
  {
    lastDigit = n % 10;
    n /= 10;
    if (lastDigit < n % 10)
    {
      return false;
    }
    if (lastDigit == n % 10)
    {
      adj++;
    }
    else
    {
      if (adj == 2)
      {
        hasDoubles = true;
      }
      adj = 1;
    }
    
  }
  return hasDoubles;
}

int main()
{
  int a, b, cnt1 = 0, cnt2 = 0;
  std::cin >> a >> b;
  std::cout << "Range: " << a << " - " << b << std::endl;
  for (int i = a; i <= b; i++) 
  {
    if (isValid1(i)) 
    {
      cnt1++;
    }

    if (isValid2(i)) 
    {
      cnt2++;
    }

  }
  std::cout << "Valid passwords part 1: " << cnt1 << " part2: " << cnt2 << std::endl;
  a = 355005;
  return 0;
}