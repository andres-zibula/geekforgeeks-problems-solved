/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/k-ary-tree/0

Description: Find the number of leaf nodes in a full k-ary tree of height m.
*/

#include <iostream>
using namespace std;

unsigned int mod = 1000000007;

unsigned int pow(int base, int exponent)
{
  if (exponent == 0)
    return 1;

  if (exponent == 1)
    return base;

  unsigned int halfExponent = pow(base, exponent / 2);

  if (exponent % 2 == 0)
    return ((long long)halfExponent * halfExponent) % mod;
  else
    return ((((long long)halfExponent * halfExponent) % mod) * base) % mod;
}

int main()
{
  int T, k, m;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> k;
    cin >> m;

    cout << pow(k, m) << endl;
  }

  return 0;
}