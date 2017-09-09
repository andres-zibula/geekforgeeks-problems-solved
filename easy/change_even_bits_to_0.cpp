/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/change-all-even-bits-in-a-number-to-0/0

Description: Given a number, change all bits at even positions to 0.
*/

#include <iostream>
using namespace std;
int main()
{
  int T;
  long long num;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> num;
    long long mask = 0;

    for (long long n = num, counter = 1; n > 0; n = n >> 1)
    {
      if (counter & 1)
        mask = (mask << 1);
      else
        mask = (mask << 1) | 1;

      counter++;
    }

    if (mask & 1)
      mask = mask << 1;

    cout << (num & mask) << endl;
  }

  return 0;
}