#include <iostream>
#include <vector>
#include <math.h>

// The solution worked for my input, but probably it's not generic

int getOutput(std::vector<int> v)
{
  bool done = false;

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
      std::cout << "Something went wrong:" << i << " " << v[i] << std::endl;
      break;
    }
  }
  return v[0];
}


int main()
{
  int n;
  char sep;
  std::vector<int> v;
  int target = 19690720;

  std::cin >> n;
  v.push_back(n);
  while (std::cin >> sep >> n && sep == ',')
  {
    v.push_back(n);
  }

  int initialOutput = getOutput(v);
  
  int initialNoun = v[1];
  int noun = initialNoun + 1;

  int initialVerb = v[2];
  int verb = initialVerb + 1;

  v[1] = noun;
  int noun1Output = getOutput(v);

  v[1] = initialNoun;
  v[2] = verb;
  int verb1Output = getOutput(v);

  int testNoun = std::floor((target - initialOutput) / (noun1Output - initialOutput));
  int testVerb = target - initialOutput - (testNoun * (noun1Output - initialOutput));
  std::cout << testNoun << " " << testVerb << std::endl;

  return 0;
}