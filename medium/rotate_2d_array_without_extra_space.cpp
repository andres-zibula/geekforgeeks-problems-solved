/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space/0

Description: You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.
*/

#include <iostream>
using namespace std;
int main()
{
  int T, N;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> N;

    int **array = new int *[N];
    for (int i = 0; i < N; ++i)
    {
      array[i] = new int[N];
      for (int j = 0; j < N; ++j)
      {
        cin >> array[i][j];
      }
    }

    for (int i = 0; i < N; ++i)
    {
      for (int j = N - 1; j >= 0; --j)
      {
        if (j == N - 1 && i == 0)
          cout << array[j][i];
        else
          cout << " " << array[j][i];
      }
    }

    cout << endl;

    for (int i = 0; i < N; ++i)
      delete[] array[i];
    delete[] array;
  }

  return 0;
}