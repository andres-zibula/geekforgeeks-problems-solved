/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0

Description: Given a boolean 2D matrix (0-based index), find whether there is
path from (0,0) to (x,y) and if there is one path, print the minimum no of steps
needed to reach it, else print -1 if the destination is not reachable. You may
move in only four direction ie up, down, left and right. The path can only be
created out of a cell if its value is 1.
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
using namespace std;

inline bool is_node_valid(int x, int y, int &n, int &m, bool **graph)
{
  if (x < 0 || x >= n || y < 0 || y >= m || !graph[x][y])
    return false;

  return true;
}

inline bool is_node_visited(int x, int y, list<pair<int, int>> &visited)
{
  return std::find(visited.begin(), visited.end(), make_pair(x, y)) !=
         visited.end();
}

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    bool found = false;
    int x, y, n, m;
    queue<pair<int, int>> node_queue;
    queue<int> level_queue;
    list<pair<int, int>> visited;

    cin >> n;
    cin >> m;

    bool **graph = new bool *[n];
    for (int i = 0; i < n; ++i)
    {
      graph[i] = new bool[m];
      for (int j = 0; j < m; ++j)
      {
        cin >> graph[i][j];
      }
    }

    cin >> x;
    cin >> y;

    if (graph[0][0])
    {
      node_queue.push(make_pair(0, 0));
      level_queue.push(0);
    }

    while (!node_queue.empty())
    {
      pair<int, int> current = node_queue.front();
      node_queue.pop();

      int level = level_queue.front();
      level_queue.pop();

      if (current.first == x and current.second == y)
      {
        cout << level << endl;
        found = true;
        break;
      }

      if (is_node_valid(current.first + 1, current.second, n, m, graph) &&
          !is_node_visited(current.first + 1, current.second, visited))
      {
        node_queue.push(make_pair(current.first + 1, current.second));
        level_queue.push(level + 1);
      }
      if (is_node_valid(current.first, current.second + 1, n, m, graph) &&
          !is_node_visited(current.first, current.second + 1, visited))
      {
        node_queue.push(make_pair(current.first, current.second + 1));
        level_queue.push(level + 1);
      }
      if (is_node_valid(current.first - 1, current.second, n, m, graph) &&
          !is_node_visited(current.first - 1, current.second, visited))
      {
        node_queue.push(make_pair(current.first - 1, current.second));
        level_queue.push(level + 1);
      }
      if (is_node_valid(current.first, current.second - 1, n, m, graph) &&
          !is_node_visited(current.first, current.second - 1, visited))
      {
        node_queue.push(make_pair(current.first, current.second - 1));
        level_queue.push(level + 1);
      }

      visited.push_back(current);
    }

    if (!found)
      cout << -1 << endl;

    for (int i = 0; i < n; ++i)
      delete[] graph[i];

    delete[] graph;
  }

  return 0;
}