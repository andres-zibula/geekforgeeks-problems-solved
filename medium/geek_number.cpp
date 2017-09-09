/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/prime-factorization-and-geek-number/0

Description: The problem is to find shortest distances between every pair of
vertices in a given edge weighted directed Graph.
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
    long long last_prime = 0;
    bool geek = true;

    while (j <= sqrt(num))
    {
      if (num % j == 0)
      {
        num = num / j;

        if (j == last_prime)
        {
          geek = false;
          break;
        }

        last_prime = j;
      }
      else
        j++;
    }

    if (num > 1 && num == last_prime)
    {
      geek = false;
    }

    if (geek)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}