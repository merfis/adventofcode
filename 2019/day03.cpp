#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
#include <algorithm>

class AoC2019Day03
{
  private:
    int distance = INT32_MAX;
    int steps = INT32_MAX;
    std::vector <std::tuple<int, int>> w1;

    std::tuple<int, int> getTupleFromInput(const char d, const int n, const std::tuple<int, int> currPoint);
    void processInputLine(const bool saveToW1 = true);
    void pointCheck(const std::tuple<int, int> p1, const std::tuple<int, int> p2, int s);
    int manhattanDistance(const int x, const int y);
    int pointDistance(const std::tuple<int, int> p1, const std::tuple<int, int> p2);

  public:
    AoC2019Day03() {};

    void Process();

    void PrintDistance()
    {
      std::cout << "Distance:" << distance << " steps:" << steps << std::endl;
    }
};

std::tuple<int, int> AoC2019Day03::getTupleFromInput(const char d, const int n, const std::tuple<int, int> currPoint)
{
  switch (d)
  {
    case 'U':
      return std::make_tuple(std::get<0>(currPoint), std::get<1>(currPoint) + n);
    case 'D':
      return std::make_tuple(std::get<0>(currPoint), std::get<1>(currPoint) - n);
    case 'L':
      return std::make_tuple(std::get<0>(currPoint) - n, std::get<1>(currPoint));
    default:
      return std::make_tuple(std::get<0>(currPoint) + n, std::get<1>(currPoint));
  }
}

void AoC2019Day03::processInputLine(const bool saveToW1)
{
  char d, sep = ',';
  int n, s = 0;
  std::tuple<int, int> currPoint (0, 0), prevPoint(0, 0);
  if (saveToW1)
  {
    w1.push_back(currPoint);
  } 
  while (std::cin >> d >> n)
  {
    currPoint = this->getTupleFromInput(d, n, currPoint);
    if (saveToW1)
    {
      w1.push_back(currPoint);
    }
    else
    {
      s += n;
      this->pointCheck(currPoint, prevPoint, s);
      prevPoint = std::make_tuple(std::get<0>(currPoint), std::get<1> (currPoint));
    }
    std::cin >> sep;
    if (sep != ',') 
    {
      std::cin.putback(sep);
      break;
    }
  }
}

void AoC2019Day03::Process()
{
  // read first input line and save data for wire 1,
  this->processInputLine();
  this->processInputLine(false);
}

void AoC2019Day03::pointCheck(const std::tuple<int, int> p1, const std::tuple<int, int> p2, int s)
{
  int p1x = std::get<0> (p1);
  int p1y = std::get<1> (p1);
  int p2x = std::get<0> (p2);
  int p2y = std::get<1> (p2);
  int md, stepsWire1 = 0;

  for (std::size_t i = 0, l = w1.size() - 1; i < l; i++)
  {
    auto w1cx = std::get<0> (w1[i]);
    auto w1cy = std::get<1> (w1[i]);
    auto w1nx = std::get<0> (w1[i+1]);
    auto w1ny = std::get<1> (w1[i+1]);
    stepsWire1 += std::abs(w1cx - w1nx + w1cy - w1ny);

    // only compare points which can build crossing lines
    if (p1x == p2x && w1cy == w1ny && p1x >= std::min(w1cx, w1nx) && p1x <= std::max(w1cx, w1nx) && w1cy >= std::min(p1y, p2y) && w1cy <= std::max(p1y, p2y))
    {
      md = this->manhattanDistance(p1x, w1cy);
      if (md < distance)
      {
        distance = md;
      }
      if (md != 0) 
      {
        stepsWire1 -= std::abs(p1x - w1nx);
        s -= std::abs(p1y - w1ny);
        if (stepsWire1 + s < steps)
        {
          steps = stepsWire1 + s;
        }
      }
    }
    else if (p1y == p2y && w1cx == w1nx && p1y >= std::min(w1cy, w1ny) && p1y <= std::max(w1cy, w1ny) && w1cx >= std::min(p1x, p2x) && w1cx <= std::max(p1x, p2x))
    {
      md = this->manhattanDistance(w1cx, p1y);
      if (md < distance)
      {
        distance = md;
      }
      if (md != 0)
      {
        stepsWire1 -= std::abs(w1ny - p1y);
        s -= std::abs(p1x - w1nx);
        if (stepsWire1 + s < steps)
        {
          steps = stepsWire1 + s;
        }
      }
    }
  }
}

int AoC2019Day03::manhattanDistance(const int x, const int y)
{
  return std::abs(x) + std::abs(y);
}

int AoC2019Day03::pointDistance(const std::tuple<int, int> p1, const std::tuple<int, int> p2)
{
  return std::abs(std::get<0> (p1) - std::get<1> (p1)) + std::abs(std::get<0> (p2) - std::get<1> (p2));
}

int main( )
{
  AoC2019Day03 aoc = AoC2019Day03();
  aoc.Process();
  aoc.PrintDistance();
  return 0;
}