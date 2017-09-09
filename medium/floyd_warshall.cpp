/*
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0

Description: The problem is to find shortest distances between every pair of
vertices in a given edge weighted directed Graph.
*/

#include <iostream>
using namespace std;
int main()
{
  int T, V;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    cin >> V;

    int **graph = new int *[V];
    for (int i = 0; i < V; ++i)
    {
      graph[i] = new int[V];
      for (int j = 0; j < V; ++j)
      {
        cin >> graph[i][j];
      }
    }

    for (int i = 0; i < V; ++i)
    {
      for (int j = 0; j < V; ++j)
      {
        for (int k = 0; k < V; ++k)
        {
          if (graph[j][k] > graph[j][i] + graph[i][k])
            graph[j][k] = graph[j][i] + graph[i][k];
        }
      }
    }

    for (int i = 0; i < V; ++i)
    {
      for (int j = 0; j < V; ++j)
      {
        if (i == 0 && j == 0)
          cout << graph[i][j];
        else
          cout << " " << graph[i][j];
      }
    }

    cout << endl;

    for (int i = 0; i < V; ++i)
      delete[] graph[i];
    delete[] graph;
  }

  return 0;
}