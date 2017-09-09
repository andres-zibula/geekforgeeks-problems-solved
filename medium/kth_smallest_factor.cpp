/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/prime-factorization-and-geek-number/0

Description: As we know that every number >=2 can be represented as natural
powers of primes(prime factorization). Also prime factorization is unique for a
number.
*/

#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int T;
  long long num, k;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> num;
    cin >> k;
    long long j = 1;
    long long factCounter = 0;
    stack<long long> stck;

    while (j <= sqrt(num))
    {
      if (num % j == 0)
      {
        ++factCounter;

        if (k == factCounter)
        {
          cout << j << endl;
          break;
        }

        if (j != (num / j))
        {
          stck.push(num / j);
        }
      }

      j++;
    }

    if (k != factCounter)
    {
      while (!stck.empty())
      {
        ++factCounter;

        if (k == factCounter)
        {
          cout << stck.top() << endl;
          break;
        }

        stck.pop();
      }
    }

    if (k != factCounter)
      cout << -1 << endl;
  }

  return 0;
}