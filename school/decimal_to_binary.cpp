/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/decimal-to-binary/0

Description: Given a decimal number. Write a program to convert it into
equivalent binary number.
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int n, num;
  stack<int> st;

  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> num;

    while (num)
    {
      if (num & 1)
        st.push(1);
      else
        st.push(0);

      num >>= 1;
    }

    while (!st.empty())
    {
      cout << st.top();
      st.pop();
    }

    cout << endl;
  }

  return 0;
}