/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/largest-prime-factor/0

Description: Given a no N, the task is to find the largest prime factor of the
number.
*/

#include <cmath>
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
    long long j = 2;

    while (j <= sqrt(num))
    {
      if (num % j == 0)
        num = num / j;
      else
        j++;
    }

    if (num > 1)
      cout << num << endl;
  }

  return 0;
}