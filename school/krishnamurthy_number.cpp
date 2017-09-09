/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/krishnamurthy-number/0

Description: A Krishnamurthy number is a number whose sum of the factorial of
digits is equal to the number itself. Given a number N as input. Write a program
to check whether this number is krishnamurthy number or not.
*/

#include <iostream>
using namespace std;

int fact[10];

int factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

bool isKrishnamurthy(int n)
{
  int num = n, sum = 0;

  while (num)
  {
    sum += fact[num % 10];
    num /= 10;
  }

  return sum == n;
}

int main()
{
  for (int i = 0; i < 10; ++i)
  {
    fact[i] = factorial(i);
  }

  int n, num;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> num;

    if (isKrishnamurthy(num))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}