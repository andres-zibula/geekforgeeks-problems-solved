/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/smith-number/0

Description: Given a number n, the task is to find out whether this number is
smith or not. A Smith Number is a composite number whose sum of digits is equal
to the sum of digits in its prime factorization.
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
    long long num2 = num;
    long long j = 2;
    long long prime_sum = 0, number_sum = 0;

    while (j <= sqrt(num))
    {
      if (num % j == 0)
      {
        num = num / j;
        long long factor = j;

        while (factor)
        {
          prime_sum += factor % 10;
          factor /= 10;
        }
      }
      else
        j++;
    }

    if (prime_sum == 0)
    {
      cout << "0" << endl;
      continue;
    }

    if (num > 1)
    {
      long long factor = num;

      while (factor)
      {
        prime_sum += factor % 10;
        factor /= 10;
      }
    }

    while (num2)
    {
      number_sum += num2 % 10;
      num2 /= 10;
    }

    if (prime_sum == number_sum)
      cout << "1" << endl;
    else
      cout << "0" << endl;
  }

  return 0;
}