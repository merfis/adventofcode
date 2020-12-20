#include <iostream>

int main()
{
  long seatId, maxSeatId = 0;
  char bfrl;
  unsigned int i = 0, row = 64, seat = 4, rows = 32, seats = 2;


  while (std::cin >> bfrl)
  {
    // std::cout << " " << bfrl;
    i++;

    switch (bfrl)
    {
      case 'F':
        row -= (rows > 0) ? rows : 1;
        rows = rows >> 1;
        break;

      case 'B':
        row += rows;
        rows = rows >> 1;
        break;

      case 'R':
        seat += seats;
        seats = seats >> 1;
        // std::cout << seat << " (" << seats << ")" << std::endl;
        break;

      case 'L':
        seat -= (seats > 0) ? seats : 1;
        seats = seats >> 1;
        // std::cout << seat << " (" << seats << ")" << std::endl;
        break;

    }

    // std::cout << row << " (" << rows << ") " << seat << " (" << seats << ")" << std::endl;

    if (i % 10 == 0)
    {
      seatId = row * 8 + seat;
      std::cout << row << " " << seat << " " << seatId << std::endl;
      // reset rows and seats
      i = 0;
      row = 64;
      seat = 4;
      rows = 32;
      seats = 2;
      // std::cout << std::endl;

      if (seatId > maxSeatId)
      {
        maxSeatId = seatId;
      }
    }
  }

  std::cout << maxSeatId << std::endl;

  return 0;
}