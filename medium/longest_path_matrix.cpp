/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/longest-path-in-a-matrix/0

Description: Given a n*n matrix, find the maximum length path (starting from any
cell) such that all cells along the path are in increasing order with a
difference of 1.

We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1,
j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent
cells have a difference of 1.
*/

#include <iostream>
#include <stack>
#include <utility>
using namespace std;

bool is_valid_move(int x_from, int y_from, int x_to, int y_to, int **matrix,
                   int n)
{
  if (x_to < 0 || x_to >= n || y_to < 0 || y_to >= n)
    return false;

  if (matrix[y_to][x_to] - matrix[y_from][x_from] != 1)
    return false;

  return true;
}

int max_path_dfs(int x, int y, int **matrix, int n)
{
  int max_path = 0;
  stack<pair<int, int>> cell_stack;
  stack<int> level_stack;

  cell_stack.push(make_pair(x, y));
  level_stack.push(1);

  while (!cell_stack.empty())
  {
    pair<int, int> current_cell = cell_stack.top();
    cell_stack.pop();
    int level = level_stack.top();
    level_stack.pop();

    if (level > max_path)
      max_path = level;

    if (is_valid_move(current_cell.first, current_cell.second,
                      current_cell.first + 1, current_cell.second, matrix, n))
    {
      cell_stack.push(make_pair(current_cell.first + 1, current_cell.second));
      level_stack.push(level + 1);
    }
    if (is_valid_move(current_cell.first, current_cell.second,
                      current_cell.first, current_cell.second + 1, matrix, n))
    {
      cell_stack.push(make_pair(current_cell.first, current_cell.second + 1));
      level_stack.push(level + 1);
    }
    if (is_valid_move(current_cell.first, current_cell.second,
                      current_cell.first - 1, current_cell.second, matrix, n))
    {
      cell_stack.push(make_pair(current_cell.first - 1, current_cell.second));
      level_stack.push(level + 1);
    }
    if (is_valid_move(current_cell.first, current_cell.second,
                      current_cell.first, current_cell.second - 1, matrix, n))
    {
      cell_stack.push(make_pair(current_cell.first, current_cell.second - 1));
      level_stack.push(level + 1);
    }
  }

  return max_path;
}

int main()
{
  int T, n;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> n;
    int max_path = 0, current_path = 0;

    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i)
    {
      matrix[i] = new int[n];
      for (int j = 0; j < n; ++j)
        cin >> matrix[i][j];
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        current_path = max_path_dfs(j, i, matrix, n);
        if (current_path > max_path)
          max_path = current_path;
      }
    }

    cout << max_path << endl;
  }

  return 0;
}