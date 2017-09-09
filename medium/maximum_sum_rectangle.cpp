/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0

Description: Given a 2D array, find the maximum sum subarray in it.
*/

#include <iostream>
using namespace std;

int rect_sum(int **array, int x_from, int y_from, int x_to, int y_to)
{
  int sum = 0;
  for (int i = y_from; i <= y_to; ++i)
  {
    for (int j = x_from; j <= x_to; ++j)
    {
      sum += array[i][j];
    }
  }

  return sum;
}

int main()
{
  int T, R, C;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> R;
    cin >> C;

    int **array = new int *[R];
    for (int i = 0; i < R; ++i)
    {
      array[i] = new int[C];
      for (int j = 0; j < C; ++j)
      {
        cin >> array[i][j];
      }
    }

    int max_sum = array[0][0];

    for (int i = 0; i < R; ++i)
    {
      for (int j = 0; j < C; ++j)
      {
        for (int k = i; k < R; ++k)
        {
          for (int l = j; l < C; ++l)
          {
            int sum = rect_sum(array, j, i, l, k);
            if (max_sum < sum)
              max_sum = sum;
          }
        }
      }
    }

    cout << max_sum << endl;

    for (int i = 0; i < R; ++i)
      delete[] array[i];
    delete[] array;
  }

  return 0;
}