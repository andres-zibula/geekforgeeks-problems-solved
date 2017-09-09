/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/pronic-number/0

Description: Pronic number is a number which is the product of two consecutive
integers. The task is to check and print Pronic Numbers in a range. The first
few Pronic numbers are: 0, 2, 6, 12, 20, 30, 42, 56, 72, 90, 110, 132 and so on.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> vec;

  int n, num = 0, cont1 = 0, cont2 = 1;

  while (num <= 1000)
  {
    num = cont1 * cont2;
    vec.push_back(num);

    ++cont1;
    ++cont2;
  }

  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> num;
    for (int i = 0; vec[i] <= num; ++i)
    {
      if (i == 0)
        cout << vec[i];
      else
        cout << " " << vec[i];
    }

    cout << endl;
  }

  return 0;
}